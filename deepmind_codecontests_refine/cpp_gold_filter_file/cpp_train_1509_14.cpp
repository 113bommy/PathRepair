#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 11);
const int64_t inf = (int64_t)1e17 + 42 + 17;
int n, m, S, T, p[MAXN];
vector<pair<int, int64_t> > G[MAXN];
void read() {
  cin >> n >> m >> S >> T;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 0; i < m; i++) {
    int u, v;
    int64_t w;
    cin >> u >> v >> w;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
}
vector<pair<int, int64_t> > ord[2];
int64_t mn[MAXN][2];
int64_t dist[MAXN];
bool cmp(pair<int, int64_t> f, pair<int, int64_t> s) {
  return f.second < s.second;
}
void dijkstra(int st, int fl) {
  memset(dist, -1, sizeof(dist));
  for (int u = 1; u <= n; u++) mn[u][fl] = inf;
  priority_queue<pair<int64_t, int> > Q;
  Q.push({0, st});
  dist[st] = 0;
  while (!Q.empty()) {
    int u = Q.top().second;
    mn[u][fl] = min(mn[u][fl], dist[u]);
    Q.pop();
    for (pair<int, int64_t> e : G[u]) {
      int v = e.first;
      int64_t w = e.second;
      if (dist[v] == -1 || dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        Q.push({-dist[v], v});
      }
    }
  }
  for (int u = 1; u <= n; u++) ord[fl].push_back({u, dist[u]});
  sort(ord[fl].begin(), ord[fl].end(), cmp);
}
int64_t dp[MAXN][MAXN][2];
int64_t L(int pl, int idx) {
  if (idx < 0) return -1;
  return ord[pl][idx].second;
}
int64_t rec(int kS, int kT, int pl) {
  if (kS == n || kT == n) return 0;
  int64_t &memo = dp[kS][kT][pl];
  if (memo != -1) return memo;
  int has = 0, en = n;
  int64_t sum = 0, last = ord[pl][((pl == 0) ? kS : kT)].first;
  for (int i = ((pl == 0) ? kS : kT); i < n; i++) {
    if (ord[pl][i].first != last) break;
    has |=
        (L(pl ^ 1, ((pl == 1) ? kS : kT) - 1) < mn[ord[pl][i].first][pl ^ 1]);
    sum +=
        (L(pl ^ 1, ((pl == 1) ? kS : kT) - 1) < mn[ord[pl][i].first][pl ^ 1]) *
        p[ord[pl][i].first];
    en = i;
  }
  if (pl == 0) {
    memo = -inf;
    memo = max(memo, rec(en + 1, kT, pl) + sum);
    if (has) memo = max(memo, rec(en + 1, kT, pl ^ 1) + sum);
  } else {
    memo = inf;
    memo = min(memo, rec(kS, en + 1, pl) - sum);
    if (has) memo = min(memo, rec(kS, en + 1, pl ^ 1) - sum);
  }
  return memo;
}
void solve() {
  dijkstra(S, 0);
  dijkstra(T, 1);
  memset(dp, -1, sizeof(dp));
  int64_t score = rec(0, 0, 0);
  if (score == 0)
    cout << "Flowers" << '\n';
  else if (score > 0)
    cout << "Break a heart" << '\n';
  else
    cout << "Cry" << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  read();
  solve();
  return 0;
}
