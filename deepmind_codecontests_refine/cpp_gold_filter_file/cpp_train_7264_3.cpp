#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> pint;

constexpr int INF = 1 << 30;
constexpr ll LINF = 1LL << 60;
constexpr int MOD = 998244353;

vector<int> to[200005];

ll dfs(int v) {
    ll res = 1;
    for (int u: to[v]) {
        res *= dfs(u);
        res %= MOD;
    }
    return res + 1;
}

int main() {
    int n; cin >> n;
    vector<pint> p(n); rep(i, n) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());

    set<pint> s;
    for (int i = n-1; i >= 0; --i) {
        int x = p[i].first, d = p[i].second;
        while (s.size() && s.begin()->first < x+d) {
            to[i].push_back(s.begin()->second);
            s.erase(s.begin());
        }
        s.emplace(x, i);
    }

    ll ans = 1;
    for (auto x: s) {
        int v = x.second;
        ans *= dfs(v);
        ans %= MOD;
    }
    cout << ans << endl;


    return 0;
}


    
