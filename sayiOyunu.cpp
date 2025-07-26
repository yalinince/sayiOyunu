#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <utility>

auto sayiyiIsle(std::vector<int> kume, std::vector<int> bilgisayarSayi) -> std::pair<int, int>;
auto sayiAl() -> std::vector<int>;
void kurallar();
auto sayiTut() -> std::vector <int>;
auto rakamlariFarkliMi(int sayi) -> bool;
void ipucunuEkranaYaz(std::pair<int, int> ipucu);


std::vector <int> bilgisayarSayi;

int main()
{
    srand(time(0));
    bilgisayarSayi = sayiTut();
    int tercih;
    std::cout << "Sayi oyununa hos geldiniz. Kurallar icin 1, oyun icin 2 giriniz: ";
    std::cin >> tercih;

    if (tercih == 1)
    {
        kurallar();
    }

    std::cout << "Sayi oyunu basliyor. Bol sans :)" << std::endl;

    int i = 0;
    for (;true;)
    {
        auto alinanSayi = sayiAl();
        auto ipucu = sayiyiIsle(alinanSayi, bilgisayarSayi);
        ipucunuEkranaYaz(ipucu);
        ++i;
        if (ipucu.second == 4) 
            break;
    } 
    i += 2;

    std::cout << "Tebrikler! Sayi oyununu " << i << " denemede bitirdiniz." << std::endl;
    system("pause");
    
}

auto sayiyiIsle(std::vector<int> kume, std::vector<int> bilgisayarSayi) -> std::pair<int, int>
{
    int artiSayisi = 0;
    int eksiSayisi = 0;

    for (int i = 0; i < 4; ++i)
    {
        if (kume.at(i) == bilgisayarSayi.at(j))
        {
            ++artiSayisi;
        }
        else
        {
            for (int j = 0; j < 4; ++j)
            {
                if (i != j && kume.at(i) == bilgisayarSayi.at(j))
                {
                    ++eksiSayisi;
                }
            }
        }
    }

    return {eksiSayisi, artiSayisi};
}


auto sayiAl() -> std::vector<int>
{
    int sayi;
    
    int sayac = 0;
    do
    {
        if (sayac > 1)
        {
            std::cout << "Girdiginiz sayi gecersizdir." << std::endl;
        }
        std::cout << "Lutfen 4 basamakli, rakamlari birbirinden farkli bir sayi giriniz: ";
        std::cin.clear();
        std::cin >> sayi;
    } while (!rakamlariFarkliMi(sayi));

    std::vector<int> basamaklar = { 0, 0, 0, 0 };

    basamaklar.at(0) = (sayi / 1000) % 10;
    basamaklar.at(1) = (sayi / 100) % 10;
    basamaklar.at(2) = (sayi / 10) % 10;
    basamaklar.at(3) = sayi % 10;

    return basamaklar;
}

void kurallar()
{
    std::cout << "----- OYUN KURALLARI -----" << std::endl;
    std::cout << "- Oyun, size bilgisayarin tuttugu sayiyi bilmeniz icin ipuclari verecektir. Bu ip-" << std::endl;
    std::cout << "uclarindan yararlanarak sayiyi bulmaya calisiniz. Ipuclarinda - (eksi) ile belirti-" << std::endl;
    std::cout << "len deger tahmininizdeki yeri yanlis ama sayida bulununan rakamlarin sayisini, +" << std::endl;
    std::cout << "(arti) ile belirtilen deger ise dogru yerdeki rakamlarin sayisini belirtir. Bilgi-" << std::endl;
    std::cout << "sayarin sectigi sayiyi bulmak icin her ipucundan sonra tahmin yapiniz. Tahminler" << std::endl;
    std::cout << "rakamlari birbirinden farkli 4 basamakli tam sayilar olmalidir. Oyun basliyor..." << std::endl << std::endl;
    std::cout << "----------------------------------------O----------------------------------------" << std::endl << std::endl;
}

auto sayiTut() -> std::vector <int>
{
    std::vector<int> basamaklar = { 0, 0, 0, 0 };
    int sayi;
    
    do
    {
        sayi = (rand() % 9000) + 1000;
    } while (!rakamlariFarkliMi(sayi));

    basamaklar.at(0) = (sayi / 1000) % 10;
    basamaklar.at(1) = (sayi / 100) % 10;
    basamaklar.at(2) = (sayi / 10) % 10;
    basamaklar.at(3) = sayi % 10;

    return basamaklar;
}   

auto rakamlariFarkliMi(int sayi) -> bool
{
    std::vector<int> basamaklar = { 0, 0, 0, 0 };

    basamaklar.at(0) = (sayi / 1000) % 10;
    basamaklar.at(1) = (sayi / 100) % 10;
    basamaklar.at(2) = (sayi / 10) % 10;
    basamaklar.at(3) = sayi % 10;
    
    if(basamaklar.at(0) != basamaklar.at(1) && basamaklar.at(0) != basamaklar.at(2) && basamaklar.at(0) != basamaklar.at(3) && basamaklar.at(1) != basamaklar.at(2) && basamaklar.at(1) != basamaklar.at(3) && basamaklar.at(2) != basamaklar.at(3))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ipucunuEkranaYaz(std::pair<int, int> ipucu)
{
    std::cout << "-" << ipucu.first << " +" << ipucu.second << std::endl;
}
