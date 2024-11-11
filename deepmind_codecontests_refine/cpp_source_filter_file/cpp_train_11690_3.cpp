#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.141592653589793238462643383279;
const long double EPS = 1e-9;
const long long INF = 1e9 + 7;
const long long MOD = INF;
const long long maxn = 1e5 + 2;
const long long HASH_MODS[] = {1000000007333, 1000000009367, 1000000075747,
                               1000000158923, 1000000203119};
int l;
int ans = 0;
vector<int> g[maxn];
int d[maxn];
set<pair<int, int> > s;
vector<pair<int, int> > e;
bool used[2 * maxn];
int main() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  int st;
  cin >> st;
  for (int i = (0); i < (m); ++i) {
    int v, u, w;
    cin >> v >> u >> w;
    g[u].push_back(e.size());
    e.push_back({v, w});
    g[v].push_back(e.size());
    e.push_back({u, w});
  }
  for (int i = (1); i < (n + 1); ++i) d[i] = INF;
  d[st] = 0;
  s.insert({d[st], st});
  while (!s.empty()) {
    int v = s.begin()->second;
    s.erase(s.begin());
    for (int id : g[v]) {
      int to = e[id].first;
      int len = e[id].second;
      if (d[to] > d[v] + len) {
        s.erase({d[to], to});
        d[to] = d[v] + len;
        s.insert({d[to], to});
      }
    }
  }
  cin >> l;
  for (int i = (1); i < (n + 1); ++i)
    if (d[i] == l) ++ans;
  for (int i = 1; i <= n; ++i)
    for (int id : g[i]) {
      if (used[id]) continue;
      used[id] = true;
      used[id ^ 1] = true;
      int to = e[id].first;
      int w = e[id].second;
      if (d[i] < l) {
        if (d[i] + w > l) {
          int rzn = l - d[i];
          if (d[i] + rzn == d[to] + w - rzn) {
            ans++;
          } else if (d[i] + rzn < d[to] + w - rzn) {
            ++ans;
          }
        }
      }
      if (d[to] < l) {
        if (d[to] + w > l) {
          int rzn = l - d[i];
          if (d[to] + rzn < d[i] + w - rzn) {
            ans++;
          }
        }
      }
    }
  cout << ans;
}
