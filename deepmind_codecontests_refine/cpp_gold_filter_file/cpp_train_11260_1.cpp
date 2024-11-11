#include <bits/stdc++.h>
using namespace std;
int tot = 0;
int qd(int x) {
  if (tot++ == 36)
    while (1)
      ;
  printf("d %d\n", x);
  fflush(stdout);
  int d;
  scanf("%d", &d);
  return d;
}
int qs(int x) {
  if (tot++ == 36)
    while (1)
      ;
  printf("s %d\n", x);
  fflush(stdout);
  int s;
  scanf("%d", &s);
  return s;
}
void ans(int x) {
  printf("! %d\n", x);
  fflush(stdout);
}
vector<int> edges[200005];
int sze[200005], dep[200005], par[200005];
int mxd;
void dfs(int u, int p, int d) {
  sze[u] = 0;
  par[u] = p;
  dep[u] = d;
  if (d == mxd) {
    sze[u] = 1;
    return;
  }
  for (auto v : edges[u]) {
    if (v == p) continue;
    dfs(v, u, d + 1);
    sze[u] += sze[v];
  }
}
int tmp[200005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = (1); i <= (n - 1); i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  mxd = qd(1);
  if (!mxd) {
    ans(1);
    return 0;
  }
  dfs(1, -1, 0);
  int rt = 1;
  while (dep[rt] < mxd) {
    int s = sze[rt], hc = 0;
    for (auto u : edges[rt]) {
      if (u == par[rt]) continue;
      if (sze[u] * 2 > s) {
        hc = u;
        break;
      }
    }
    if (!hc) {
      rt = qs(rt);
    } else {
      int t = rt, it = 0;
      while (dep[t] < mxd) {
        bool large = 0;
        tmp[++it] = t;
        for (auto v : edges[t]) {
          if (v != par[t] && sze[v] * 2 > s) {
            t = v;
            large = 1;
            break;
          }
        }
        if (!large) break;
      }
      int d = qd(t);
      if (d == -1) return 0;
      rt = qs(tmp[it - (d - (mxd - dep[t])) / 2]);
    }
    if (rt == -1) return 0;
  }
  ans(rt);
  return 0;
}
