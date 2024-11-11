#include<iostream>
using namespace std;
long long gcd(long long a,long long b)
{
if(!b)return a;return gcd(b,a%b);
}
long long T,N,rez;
int main()
{
cin>>N;
cin>>rez;N--;
while(N--){cin>>T;rez=(rez/gcd(rez,T))*T;}
cout<<rez;
}