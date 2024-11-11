#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    ll ans=1e15;
    for(ll i=0;i<(1<<n);i++){
        ll cost=0;
        ll mh=0;
        ll num=0;
        vector<ll>b=a;
        for(ll j=0;j<n;j++){
            if(i & (1<<j)){
                cost+=max((ll)0,mh+1-b[j]);
                b[j]=max(b[j],mh+1);
                if(b[j]>mh) num++;
            }
            mh=max(mh,b[j]);
        }
        if(num>=k) ans=min(ans,cost);
    }
    cout << ans << endl;
}