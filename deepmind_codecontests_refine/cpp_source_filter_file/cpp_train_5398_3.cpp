include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    int n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    ll ans=1e18;
    for(int bit = 0; bit<(1<<n-1); bit++){
        if(__builtin_popcount(bit) != k-1) continue;
        ll s=0;
        ll h=a[0];
        bool flag = true;

        for(int i=1; i<n; i++){
            if(((bit >> i-1) & 1)){
                if(a[i]>h){
                    h=a[i];
                } else {
                    s += h+1-a[i];
                    h += 1;
                }
            } else {
                if (a[i]>h) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) ans = min(ans,s);
    }
    cout << ans << endl;
}