#include <bits/stdc++.h>
using namespace std;
mt19937_64 random_num(
    chrono::high_resolution_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const int inf = 2000000000;
const int mod = 1007050321;
const double e = 0.000001;
const int N = 200005;
const bool aut = 788480;
const int base = 521;
int n, m, s[N], ans[N];
struct edge {
  int v, w, id;
};
vector<edge> adj[N];
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    if (u == 1 && v == n)
      ans[i] = 0;
    else if (u == n && v == 1)
      ans[i] = 1;
    adj[u].push_back({v, c, i});
    adj[v].push_back({u, c, -i});
  }
  for (int i = 2; i <= n; ++i)
    for (auto e : adj[i]) s[i] += e.w;
  for (int i = 2; i <= n; ++i) s[i] /= 2;
  queue<int> qu;
  qu.push(1);
  while (qu.size()) {
    int u = qu.front();
    qu.pop();
    for (auto e : adj[u])
      if (s[e.v] != 0) {
        if (e.id < 0) ans[-e.id] = 1;
        s[e.v] -= e.w;
        if (s[e.v] == 0 && e.v != n) qu.push(e.v);
      }
  }
  for (int i = 1; i <= m; ++i) cout << ans[i] << "\n";
  return 0;
}
