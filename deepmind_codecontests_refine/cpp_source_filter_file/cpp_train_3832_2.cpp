#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll max_n = 100010;
ll n, c[max_n];
vector<pair<ll, ll>> t[max_n];

void dfs(ll v, ll previous=-1) {
    for (auto it: t[v]) {
        ll u = it.first;
        ll w = it.second % 2;
        if (u != previous) {
            c[u] = c[v] ^ w;
            dfs(u, v);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        t[u].push_back({v, w});
        t[v].push_back({u, w});
    }
    dfs(1);
    for(int i = 1; i <=n; ++i) {
        cout << c[i] << endl;
    }
