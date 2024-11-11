#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define mod 998244353
#define Mod1(x) (x>=mod?x-mod:x)
#define Mod2(x) (x<0?x+mod:x)
#define maxn 3000010
inline ll read()
{
    ll x=0; char c=getchar(),f=1;
    for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
    for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
    return x*f;
}
inline void write(ll x)
{
    static int buf[20],len; len=0;
    if(x<0)x=-x,putchar('-');
    for(;x;x/=10)buf[len++]=x%10;
    if(!len)putchar('0');
    else while(len)putchar(buf[--len]+'0');
}
inline void writeln(ll x){write(x); putchar('\n');}
inline void writesp(ll x){write(x); putchar(' ');}
ll fac[maxn],inv[maxn];
int n,m;
inline ll power(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1)ans=ans*a%mod;
    return ans;
}
inline ll C(int n,int m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
inline ll calc(int n,int m,int k)
{
    ll sum=0;
    for(int i=0;i<=n&&i<=k;i++)
        if(!((m-i)&1)&&m>=i)sum=(sum+C(n,i)*C((m-i)/2+n-1,n-1))%mod;
    // writeln(sum);
    return sum;
}
int main()
{
    n=read(); m=read();
    fac[0]=inv[0]=1;
    for(int i=1;i<=n+3*m;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=power(fac[i],mod-2);
    }
    ll ans=(calc(n,3*m,m)-n*(calc(n,m,m)-calc(n-1,m,m)+mod))%mod;
    writeln(Mod2(ans));
    return 0;
}

agc036C