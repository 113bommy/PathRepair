# include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
typedef long long LL;
const int maxn = 23000000;
short dig[maxn+1];
inline add(int &x, int y)
{
    x+=y;
    if(x>=mod) x-=mod;
}
int qmod(LL a, int b)
{
    LL res = 1;
    for(;b;b>>=1)
    {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
    }
    return (int)res;
}
int main()
{
    for(int i=1; i<=maxn; ++i) dig[i] = dig[i/10]+1;
    int n, ans=0;
    scanf("%d",&n);
    for(int i=1, j=1, s=0; i<1e7; ++i)
    {
        while(s<n) s+=dig[j],++j;
        if(s==n) add(ans, 1);
        s -= dig[i];
    }
    for(int i=1; i<=n/8; ++i)
    {
        if(n%i==0) add(ans, ((qmod(10,n/i)-qmod(10,n/i-1)-i+1)%mod+mod)%mod);
        else add(ans, 1);
    }
    printf("%d\n",ans);
    return 0;
}
