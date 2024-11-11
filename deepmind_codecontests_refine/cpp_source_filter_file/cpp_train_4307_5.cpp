#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double PI = acos(-1);
template <class T, class S>
inline void add(T &a, S b) {
  a += b;
  if (a >= mod) a -= mod;
}
template <class T, class S>
inline void sub(T &a, S b) {
  a -= b;
  if (a < 0) a += mod;
}
template <class T, class S>
inline bool chkmax(T &a, S b) {
  return a < b ? a = b, true : false;
}
template <class T, class S>
inline bool chkmin(T &a, S b) {
  return a > b ? a = b, true : false;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, a, b, k, S[N], T[N];
int G[N][N], d[N][N], ans[N], dp[N];
int fnow;
int vis[N];
vector<int> V[N];
vector<pair<int, int> > vc;
int dfs(int u, int who) {
  if (vis[u] == fnow) return dp[u];
  vis[u] = fnow;
  int ret = -1;
  for (int v = 1; v <= n; v++) {
    if (G[u][v] == 1 && d[S[who]][u] + d[v][T[who]] + 1 == d[S[who]][T[who]]) {
      chkmax(ret, dfs(v, u));
    }
  }
  if (ret == -1) ret = inf;
  chkmin(ret, ans[u]);
  return dp[u] = ret;
}
int main() {
  memset(ans, 0x3f, sizeof(ans));
  memset(G, 0x3f, sizeof(G));
  memset(d, 0x3f, sizeof(d));
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for (int i = 1; i <= n; i++) {
    G[i][i] = d[i][i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u][v] = d[u][v] = 1;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        chkmin(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  scanf("%d", &k);
  for (int o = 1; o <= k; o++) {
    int s, t;
    scanf("%d%d", &s, &t);
    S[o] = s;
    T[o] = t;
    vc.clear();
    if (d[s][t] >= inf) continue;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (G[i][j] != 1) continue;
        if (d[s][i] + d[j][t] + 1 == d[s][t]) {
          vc.push_back(make_pair(d[s][i], i));
          vc.push_back(make_pair(d[s][j], j));
        }
      }
    }
    sort((vc).begin(), (vc).end());
    vc.erase(unique((vc).begin(), (vc).end()), vc.end());
    for (int i = 0; i < ((int)vc.size()); i++) {
      if (i && vc[i].first == vc[i - 1].first) continue;
      if (i < ((int)vc.size()) - 1 && vc[i].first == vc[i + 1].first) continue;
      V[o].push_back(vc[i].second);
    }
  }
  ans[b] = 0;
  while (1) {
    bool flag = false;
    for (int o = 1; o <= k; o++) {
      if (d[S[o]][T[o]] >= inf) continue;
      for (auto &u : V[o]) {
        fnow++;
        int ret = dfs(u, o) + 1;
        if (chkmin(ans[u], ret)) {
          flag = true;
        }
      }
    }
    if (!flag) break;
  }
  printf("%d\n", ans[a] < inf ? ans[a] : -1);
  return 0;
}
