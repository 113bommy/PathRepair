#include<iostream>
#include<cmath>
#define MOD 1000000007

using namespace std;

long long power(long long a,long long x){
    return x?x%2?power(a,x-1)*a%MOD:(long long)powl(power(a,x/2),2)%MOD:1;
}
long long nCr(long long n,long long r){
    long long nCr=1LL;
    for(long long i=n;i>n-r;nCr%=MOD,i--)nCr*=i;
    for(long long i=1;i<=r;nCr%=MOD,i++)nCr*=power(i,MOD-2);
    return nCr;
}


int main(){
    long long x,y;
    cin>>x>>y;
    long long r=(2*y-x)/3LL,n=r+(y-2*r);
    if((2*y-x)%3!=0LL||r<0||n<=0{cout<<0<<endl;return 0;}

    cout<<nCr(n,r)<<endl;

    return 0;
}