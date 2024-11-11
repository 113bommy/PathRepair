#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
signed main()
{
    int n;
    scanf("%d",&n);
    vector<ll> c(n,0);
    vector<ll> d(n+1,0);
    for(int i=0;i<n;i++)
    {
        int a;scanf("%d",&a);--a;
        c[a]++;
        d[c[a]]++;
    }    
    vector<ll> s(n+1,0),s2(n+1,0);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+d[i],s2[i]=s[i]/i;

    ll itr=n;
    for(ll k=1;k<=n;k++)
    {
        while(itr>0&&k>s2[itr])--itr;
        printf("%lld\n",itr);
    }
    return 0;
}