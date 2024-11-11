#include <bits/stdc++.h>
using namespace std;
const int MaxN = 500;
const int Pow = 62;
int n, m;
bool f[MaxN + 5][MaxN + 5][Pow + 2];
bool g[MaxN + 5][MaxN + 5][Pow + 2];
bool vis[MaxN + 5];
vector<int> vf[2][MaxN + 5];
vector<int> vg[2][MaxN + 5];
void Init() {
  for (int i = 0; i <= 1; i++)
    for (int j = 1; j <= n; j++) vf[i][j].clear(), vg[i][j].clear();
  for (int i = 1; i <= m; i++) {
    int u, v, t;
    scanf("%d%d%d", &u, &v, &t);
    if (t == 0)
      f[u][v][0] = true, vf[0][u].push_back(v);
    else
      g[u][v][0] = true, vg[0][u].push_back(v);
  }
}
void Prepare() {
  for (int t = 1; t <= Pow; t++) {
    int s = t & 1;
    for (int u = 1; u <= n; u++) {
      vf[s][u].clear();
      for (int v = 1; v <= n; v++) {
        for (int k = 0; k < vf[1 - s][u].size(); k++) {
          int now = vf[1 - s][u][k];
          f[u][v][t] |= (f[u][now][t - 1] & g[now][v][t - 1]);
          if (f[u][v][t]) {
            vf[s][u].push_back(v);
            break;
          }
        }
      }
    }
    for (int u = 1; u <= n; u++) {
      vg[s][u].clear();
      for (int v = 1; v <= n; v++) {
        for (int k = 0; k < vg[1 - s][u].size(); k++) {
          int now = vg[1 - s][u][k];
          g[u][v][t] |= (g[u][now][t - 1] & f[now][v][t - 1]);
          if (g[u][v][t]) {
            vg[s][u].push_back(v);
            break;
          }
        }
      }
    }
  }
}
bool Check(long long mid) {
  vector<int> vs[2];
  vs[0].clear();
  vs[1].clear();
  int s = 0;
  vs[0].push_back(1);
  for (int t = Pow; t >= 0; t--) {
    if ((1LL << t) & mid) {
      vs[1 - s].clear();
      memset(vis, 0, sizeof(vis));
      for (int i = 0; i < vs[s].size(); i++) {
        int u = vs[s][i];
        if (s == 0) {
          for (int v = 1; v <= n; v++)
            if (f[u][v][t] && !vis[v]) {
              vis[v] = true;
              vs[1 - s].push_back(v);
            }
        } else {
          for (int v = 1; v <= n; v++)
            if (g[u][v][t] && !vis[v]) {
              vis[v] = true;
              vs[1 - s].push_back(v);
            }
        }
      }
      s = 1 - s;
      if (vs[s].size() == 0) return false;
    }
  }
  return true;
}
void Solve() {
  long long l = 0, r = (long long)1e18 + 5;
  while (l < r - 1) {
    long long mid = (l + r) >> 1;
    if (Check(mid))
      l = mid;
    else
      r = mid;
  }
  if (r > 1e18)
    printf("-1\n");
  else
    printf("%I64d\n", l);
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    Init();
    Prepare();
    Solve();
  }
  return 0;
}
