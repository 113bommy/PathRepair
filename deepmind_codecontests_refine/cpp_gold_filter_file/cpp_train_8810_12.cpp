#include <bits/stdc++.h>
using namespace std;
int const N = 100000;
int R = 1, in[N + 1], out[N + 1], pa[N + 1][17], n, x[N + 1], T, dp[N + 1], q;
long long s[N << 2], z[N << 2];
vector<int> tr[N + 1];
inline void sl(int id, int l, int m, int r, int a, int b) {
  long long &t = z[id];
  if (t) {
    s[a] += t * (m - l + 1);
    s[b] += t * (r - m);
    z[a] += t;
    z[b] += t;
    t = 0;
  }
}
void rm(int x, int y, int v, int l = 1, int r = n, int id = 1) {
  if (l > y || r < x) return;
  if (l >= x && r <= y) {
    s[id] += (long long)v * (r - l + 1);
    z[id] += v;
    return;
  }
  int m = l + r >> 1, a = id << 1, b = a | 1;
  sl(id, l, m, r, a, b);
  rm(x, y, v, l, m, a);
  rm(x, y, v, m + 1, r, b);
  s[id] = s[a] + s[b];
}
long long gt(int x, int y, int l = 1, int r = n, int id = 1) {
  if (l > y || r < x) return 0;
  if (l >= x && r <= y) return s[id];
  int m = l + r >> 1, a = id << 1, b = a | 1;
  sl(id, l, m, r, a, b);
  return gt(x, y, l, m, a) + gt(x, y, m + 1, r, b);
}
void pl(int v = 1, int p = 0) {
  in[v] = ++T;
  dp[v] = dp[p] + 1;
  pa[v][0] = p;
  int k = 1, z;
  while (k < 17 && (z = pa[v][k - 1])) pa[v][k] = pa[z][k - 1], ++k;
  for (int i = 0; i < (int)(tr[v].size()); ++i)
    if (tr[v][i] != p) pl(tr[v][i], v);
  out[v] = T;
}
inline int up(int a, int d) {
  int j = 0;
  while (d) {
    if (d & 1) a = pa[a][j];
    ++j;
    d >>= 1;
  }
  return a;
}
int lca(int a, int b) {
  if (dp[a] < dp[b]) swap(a, b);
  int d = dp[a] - dp[b], j = 0;
  while (d) {
    if (d & 1) a = pa[a][j];
    ++j;
    d >>= 1;
  }
  if (a == b) return a;
  for (int i = 16; i >= 0; --i)
    if (pa[a][i] != pa[b][i]) a = pa[a][i], b = pa[b][i];
  return pa[a][0];
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i < (int)(n + 1); ++i) scanf("%d", x + i);
  for (int i = 1; i < (int)(n); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    tr[a].push_back(b);
    tr[b].push_back(a);
  }
  pl();
  for (int i = 1; i < (int)(n + 1); ++i) rm(in[i], in[i], x[i]);
  for (int qq = 0; qq < (int)(q); ++qq) {
    int o;
    scanf("%d", &o);
    if (o == 1)
      scanf("%d", &R);
    else if (o == 2) {
      int a, b, x;
      scanf("%d%d%d", &a, &b, &x);
      int ab = lca(a, b);
      int ar = lca(a, R);
      if (dp[ar] <= dp[ab]) {
        swap(a, b);
        ar = lca(a, R);
      }
      if (dp[ar] >= dp[ab]) {
        if (ar == R)
          rm(1, n, x);
        else {
          int t = up(R, dp[R] - dp[ar] - 1);
          rm(1, in[t] - 1, x);
          rm(out[t] + 1, n, x);
        }
      } else
        rm(in[ab], out[ab], x);
    } else {
      int v;
      scanf("%d", &v);
      int vr = lca(v, R);
      long long an;
      if (v == R)
        an = gt(1, n);
      else if (vr == v) {
        int t = up(R, dp[R] - dp[v] - 1);
        an = gt(1, in[t] - 1) + gt(out[t] + 1, n);
      } else
        an = gt(in[v], out[v]);
      printf("%lld\n", an);
    }
  }
}
