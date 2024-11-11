#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=200005;
ll sum[maxn],a[maxn];
ll n,b,c,d,e;
ll ans=1e15+7;
bool check(ll x,ll y,int i)
{
    if(abs((x+a[i])-(y-a[i]))<abs(x-y))
    return 1;
    return 0;
}
int main()
{
    cin>>n;
    ll s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
        sum[i]=s;
    }
    int j=0,k=2;
    for(int i=1;i<n-2;i++)
    {
        b=sum[j];
        c=sum[i]-sum[j];
        d=sum[k]-sum[i];
        e=sum[n-1]-sum[k];
        while(check(b,c,j+1) && j+1<i)
        {
            j++;
            b=sum[j];
            c=sum[i]-sum[j];
        }
        while(check(d,e,k+1) && k+1<n-1)
        {
            k++;
            d=sum[k]-sum[i];
            e=sum[n-1]-sum[k];
        }
        ans=min(ans,std::max({b,c,d,e})-std::min({b,c,d,e}));
    }
    cout<<ans<<endl;
    return 0;
}