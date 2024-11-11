#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 1e6 + 6;
ll n, m, k, ver, a[maxn], c[maxn], h[maxn];
bool b, mark[maxn], odd[maxn];
vector<ll> adj[maxn], G[maxn], vec, v[2];
map<pair<ll, ll>, vector<pair<ll, ll>>> mp;
void dfs(ll u) {
  mark[u] = 1;
  for (ll i : G[u]) {
    if (mark[i]) {
      if (h[u] % 2 == h[i] % 2) b = 1;
    } else {
      h[i] = h[u] + 1;
      dfs(i);
    }
  }
}
void dfs2(ll u) {
  mark[u] = 1;
  v[h[u] & 1].push_back(u);
  for (ll i : G[u]) {
    if (!mark[i]) {
      h[i] = h[u] + 1;
      dfs2(i);
    }
  }
}
void comp(ll u) {
  v[0].clear();
  v[1].clear();
  dfs2(u);
  if (v[1].empty()) {
    a[u] = ver;
    ver++;
  } else {
    adj[ver].push_back(ver + 1);
    adj[ver + 1].push_back(ver);
    while (v[0].size()) {
      a[v[0].back()] = ver;
      v[0].pop_back();
    }
    while (v[1].size()) {
      a[v[1].back()] = ver + 1;
      v[1].pop_back();
    }
    ver += 2;
  }
}
void dfs3(ll u) {
  mark[u] = 1;
  for (ll i : adj[u]) {
    if (mark[i]) {
      if (h[u] % 2 == h[i] % 2) b = 1;
    } else {
      h[i] = h[u] + 1;
      dfs3(i);
    }
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  ver = n + 1;
  for (ll i = 1; i <= n; i++) cin >> c[i];
  for (ll i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    if (c[u] == c[v]) {
      G[u].push_back(v);
      G[v].push_back(u);
    } else {
      ll x = min(c[u], c[v]);
      ll y = max(c[u], c[v]);
      mp[{x, y}].push_back({u, v});
    }
  }
  for (ll i = 1; i <= n; i++) {
    b = 0;
    if (!mark[i]) dfs(i);
    if (b) odd[c[i]] = 1;
  }
  memset(mark, 0, sizeof mark);
  memset(h, 0, sizeof h);
  for (ll i = 1; i <= n; i++) {
    if (!mark[i]) comp(i);
  }
  ll cnt = 0;
  for (ll i = 1; i <= k; i++) {
    if (!odd[i]) cnt++;
  }
  ll ans = cnt * (cnt - 1) / 2;
  for (auto [P, v2] : mp) {
    if (odd[c[P.first]] || odd[c[P.second]]) continue;
    vec.clear();
    for (auto i : v2) {
      adj[a[i.first]].push_back(a[i.second]);
      adj[a[i.second]].push_back(a[i.first]);
      vec.push_back(a[i.first]);
      vec.push_back(a[i.second]);
    }
    for (ll i : vec) {
      mark[i] = 0;
      h[i] = 0;
      for (ll j : adj[i]) {
        mark[j] = 0;
        h[j] = 0;
      }
    }
    b = 0;
    for (ll i : vec) {
      if (!mark[i]) dfs3(i);
    }
    if (b) ans--;
    for (auto i : v2) {
      adj[a[i.first]].pop_back();
      adj[a[i.second]].pop_back();
    }
  }
  cout << ans << endl;
}
