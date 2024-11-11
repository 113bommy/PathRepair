#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 9;
vector<pair<long long, long long> > adj[N];
set<pair<long long, long long> > s;
pair<long long, long long> par[N][22];
long long dis[N], h[N], st[N], tt = 0;
void DFS(long long u, long long p) {
  st[u] = tt++;
  for (pair<long long, long long> v : adj[u])
    if (v.first != p)
      par[v.first][0] = {u, v.second}, dis[v.first] = dis[u] + v.second,
      h[v.first] = h[u] + 1, DFS(v.first, u);
}
void PREP(long long n) {
  DFS(1, 1);
  for (long long i = 1; i < 22; i++)
    for (long long j = 1; j <= n; j++)
      par[j][i].first = par[par[j][i - 1].first][i - 1].first,
      par[j][i].second =
          par[par[j][i - 1].first][i - 1].second + par[j][i - 1].second;
}
long long LYFT(long long v, long long x) {
  for (long long i = 21; i >= 0; i--)
    if (h[v] - (1 << i) >= x) v = par[v][i].first;
  return v;
}
long long LCA(long long u, long long v) {
  if (h[v] < h[u]) swap(u, v);
  v = LYFT(v, h[u]);
  if (v == u) return v;
  for (long long i = 21; i >= 0; i--)
    if (par[u][i].first != par[v][i].first)
      v = par[v][i].first, u = par[u][i].first;
  return par[u][0].first;
}
long long DIST(long long u, long long v) {
  return dis[u] + dis[v] - 2 * dis[LCA(u, v)];
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 1; i < n; i++) {
    long long u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }
  PREP(n);
  long long q, ans = 0;
  cin >> q;
  while (q--) {
    char ch;
    cin >> ch;
    if (ch == '+') {
      long long v;
      cin >> v;
      auto it = s.insert({st[v], v}).first, it1 = --s.end(), it2 = s.begin();
      if (it != s.begin()) {
        it--;
        it1 = it;
        it++;
      }
      if (it != --s.end()) {
        it++;
        it2 = it;
        it--;
      }
      long long a = (*it1).second, b = (*it).second, c = (*it2).second;
      ans += DIST(a, b) + DIST(b, c) - DIST(a, c);
    }
    if (ch == '-') {
      long long v;
      cin >> v;
      auto it = s.find({st[v], v}), it1 = --s.end(), it2 = s.begin();
      if (it != s.begin()) {
        it--;
        it1 = it;
        it++;
      }
      if (it == --s.end()) {
        it++;
        it2 = it;
        it--;
      }
      long long a = (*it1).second, b = (*it).second, c = (*it2).second;
      ans -= DIST(a, b) + DIST(b, c) - DIST(a, c);
      s.erase({st[v], v});
    }
    if (ch == '?') cout << ans / 2 << '\n';
  }
  return 0;
}
