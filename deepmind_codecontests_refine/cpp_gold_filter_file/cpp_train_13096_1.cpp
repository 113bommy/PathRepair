#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 998244353
#define inv2 499122177
#define eps 1e-8
int n;
ll a[1001000],f[1001000],g[1001000];
int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

void fwt_xor(int lim,ll *a,int typ)
{
    int mid;
    for (mid=1;mid<lim;mid<<=1)
    {
        int len=(mid<<1),sta,j;
        for (sta=0;sta<lim;sta+=len)
        {
            for (j=0;j<mid;j++)
            {
                ll x=a[sta+j],y=a[sta+j+mid];
                a[sta+j]=(x+y)%maxd;
                a[sta+j+mid]=(x+maxd-y)%maxd;
                if (typ==-1) {a[sta+j]=a[sta+j]*inv2%maxd;a[sta+j+mid]=a[sta+j+mid]*inv2%maxd;}
            }
        }
    }
}

ll qpow(ll x,int y)
{
    ll ans=1;
    while (y)
    {
        if (y&1) ans=ans*x%maxd;
        x=x*x%maxd;y>>=1;
    }
    return ans;
}

int main()
{
    n=read();int lim=(1<<n);
    ll sum=0;
    rep(i,0,lim-1) {a[i]=read();sum=(a[i]+sum)%maxd;}
    sum=qpow(sum,maxd-2);
    rep(i,0,lim-1) {f[i]=maxd-1;g[i]=a[i]*sum%maxd;}
    f[0]=lim-1;g[0]=(g[0]+maxd-1)%maxd;
    fwt_xor(lim,f,1);fwt_xor(lim,g,1);
    rep(i,0,lim-1) f[i]=f[i]*qpow(g[i],maxd-2)%maxd;
    fwt_xor(lim,f,-1);
    rep(i,0,lim-1)
        printf("%lld\n",(f[i]-f[0]+maxd)%maxd);
    return 0;
}
