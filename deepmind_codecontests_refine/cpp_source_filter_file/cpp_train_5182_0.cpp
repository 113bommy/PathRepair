#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
    int n;
    ll k;
    cin >> n >> k;
    vector<int> p(n), c(n);
    rep(i, n){
        cin >> p[i];
        --p[i];
    }
    rep(i, n) cin >> c[i];
    ll ans = -1e9 - 1;
    rep(i, n){
        int to = p[i];
        ll sum = 0;
        vector<ll> r;
        while(1){
            sum += c[to];
            r.push_back(c[to]);
            if(to == i || r.size >= k) break;
            to = p[to];
        }
        ll ts = 0, rs = r.size();
        for(ll i = 0; i < rs; ++i){
            ts += r[i];
            ans = max(ans, ts);
            if(sum > 0)
                ans = max(ans, sum * ((k - i - 1) / rs) + ts);
        }
    }
    cout << ans << endl;
    return 0;
}