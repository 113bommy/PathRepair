#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<(int)(b);i++)
#define rep(i,b) loop(i,0,b)
typedef long long ll;

// 1 indexed

int main(){
    ll N;
    while(cin >> N && N){
        ll a,d;
        ll M;
        cin >> a >> d >> M;
        vector<ll> x(M), y(M), z(M);
        ll k;

        auto kth = [&](ll k){
            ll res = a;
            rep(i,k-1){
                res += d;
            }
            return res;
        };

        rep(i,M) cin >> x[i] >> y[i] >> z[i];
        set<int> s;
        s.insert(y.begin(), y.end());
        s.insert(z.begin(), z.end());
        cin >> k;

        // rep(i,5){
        //     cout << kth(i+1) << " ";
        // }
        // cout << endl;

        ll ans = -1;
        if(s.count(k)){
            map<ll,ll> m;
            for(int i : s) m[i] = i;
            rep(i,M){
                if(x[i] == 0){
                    swap(m[y[i]],m[z[i]]);
                } else {
                    m[y[i]] = m[z[i]];
                }
            }
            ans = kth(m[k]);
        } else {
            ans = kth(k);
        }
        cout << ans << endl;
    }
}