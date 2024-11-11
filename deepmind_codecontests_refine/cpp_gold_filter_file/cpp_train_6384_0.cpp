#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
mt19937_64 rnd;

const ll maxn=7e5+10;
const ll mod =998244353  ;
const ll base=500;
/// you will be the best but now you just are trash
ll a[maxn];
ll gt[maxn];
ll gtv[maxn];
ll mu(ll a,ll n)
{
    if (n==0)
        return 1;
    if (n==1)
        return a;
    ll t=mu(a,n/2);
    if (n%2==0)
        return (t*t)%mod;
    return ((t*t)%mod*a)%mod;
}
void setup()
{
    gt[0]=1;
    for (int i=1; i<maxn; i++)
    {
        gt[i]=(gt[i-1]*i)%mod;
    }
    gtv[maxn-1]=mu(gt[maxn-1],mod-2);
    for (int i=maxn-2; i>=0; i--)
    {
        gtv[i]=(gtv[i+1]*(i+1))%mod;
    }
}
ll nck(ll n,ll k)
{
    if (n<k)
        return 0;
    return ((gt[n]*gtv[k])%mod*gtv[n-k])%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    setup();
    ll t;
    cin>> t;
    while (t--)
    {
       ll n;
       cin>> n;
       string s;
       cin>> s;
       ll nw=n;
       ll cntnw=0;
       for (int i=0;i<n;i++)
       {
           if (s[i]=='0') continue;
           ll j=i;
           while (j<n&&s[j]=='1') j++;
           j--;
           ll len=(j-i+1);
           cntnw+=(len/2);
           nw-=((len+1)/2);
           i=j;
       }
       cout <<nck(nw,cntnw)<<endl;
    }
}
