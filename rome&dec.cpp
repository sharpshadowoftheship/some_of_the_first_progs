#include <iostream>

using namespace std;
int pow(int wyk)
{
int    wyn=1;
    for(int i=0; i<wyk; i++)
    {
        wyn*=10;
    }
    return wyn;
}

int rome_to_dec(string a)
{
    int tab[100000];
    tab[(int)'I']=1;
    tab[(int)'V']=5;
    tab[(int)'X']=10;
    tab[(int)'L']=50;
    tab[(int)'C']=100;
    tab[(int)'D']=500;
    tab[(int)'M']=1000;
    int s=0;

    for(int i=0; i<a.size(); i++)
    {
        if(i+1<a.size())
        {
            if(tab[(int)a[i]]<tab[(int)a[i+1]])
            {
                   s+=(tab[(int)a[i+1]]-tab[(int)a[i]]);
                   i++;
            }
            else
            {
                s+=tab[(int)a[i]];
            }
        }
        else
        {
            s+=tab[(int)a[i]];
        }

    }
    return s;

}
void dec_to_rome(int a)
{
    char tab[100001];

    tab[1]='I';
    tab[5]='V';
    tab[10]='X';
    tab[50]='L';
    tab[100]='C';
    tab[500]='D';
    tab[1000]='M';
    int ile=0,dl=0;
    int w;
    int tmp;
    tmp=a;
    while(tmp>0)
    {
        tmp/=10;
        dl++;
    }


ile=dl;

while(a>0)
{
    w=a/(pow(ile-1));

    if(w<=3)
    {
        for(int i=1; i<=w; i++)
        {
            cout<<tab[(pow(ile-1))];
           // cout<<w<<" "<<pow(ile-1)<<"\n";
        }
    }
    if(w==4)
    {
        cout<<tab[(pow(ile-1))]<<tab[(pow(ile-1))*(w+1)];
       // cout<<w<<" "<<pow(ile-1)<<"\n";
    }
    if(w==5)
    {
        cout<<tab[(pow(ile-1))*w];
       // cout<<w<<" "<<pow(ile-1)<<"\n";
    }
    if(w>5 && w<=8)
    {
       // cout<<w<<" "<<pow(ile-1)<<"\n";
        cout<<tab[(pow(ile-1))*5];
         for(int i=1; i<=w-5; i++)
        {
            cout<<tab[(pow(ile-1))];
        }

    }
    if(w==9)
    {
       // cout<<w<<" "<<pow(ile-1)<<"\n";
        cout<<tab[(pow(ile-1))]<<tab[(pow(ile-1))*(w+1)];
    }
    a=(a%(pow((ile-1))));
    ile--;
}

}


int main()
{
    cout<<rome_to_dec("MMCDXLVIII");
}
