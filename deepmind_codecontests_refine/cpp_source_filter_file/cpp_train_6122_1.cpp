#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; ++i) cin >> a[i];
    ll ans = 0;
    for(int i = 1; i < N; ++i) {
        int l = 0,r = N-1;
        ll suml = 0, sumr = 0;
        map<int,int> mp;
        mp[0] = mp[N-1] = 1;
        while(l < N-1 - i && i < r && mp[l]==1 && mp[r]==1) {
            suml += a[l];
            sumr += a[r];
            chmax(ans,suml+sumr);
            l += i;
            r -= i;
            mp[l]++;
            mp[r]++;
        }
    }
    cout << ans << endl;
    return 0;
}
