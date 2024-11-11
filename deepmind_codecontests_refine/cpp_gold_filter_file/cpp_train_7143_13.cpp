#include <bits/stdc++.h>
using namespace std;
const int N = 3010, M = 4e5 + 5, inf = 1e9 + 7;
char B[1 << 14], *S = B, *T = B;
inline int read() {
  int x = 0, f = 1;
  char ch =
      (S == T && (T = (S = B) + fread(B, 1, 1 << 14, stdin), S == T) ? -1
                                                                     : *S++);
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = (S == T && (T = (S = B) + fread(B, 1, 1 << 14, stdin), S == T) ? -1
                                                                        : *S++);
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = (S == T && (T = (S = B) + fread(B, 1, 1 << 14, stdin), S == T) ? -1
                                                                        : *S++);
  }
  return x * f;
}
struct edge {
  int y, nex;
} a[N];
int len, fir[N];
void ins(int x, int y) { a[++len] = (edge){y, fir[x]}, fir[x] = len; }
int f[N][12], fr[N], p[N];
bool v[N], in[N];
void dfs(int x) {
  v[x] = 1;
  for (int k = fir[x]; k; k = a[k].nex) {
    int y = a[k].y;
    fr[y] = min(fr[y], x);
    if (!v[y]) dfs(y);
  }
}
void dfs2(int x) {
  if (p[x] < inf) return;
  if (fr[x] > inf || in[fr[x]]) {
    p[x] = -1;
    return;
  }
  in[x] = 1;
  dfs2(fr[x]);
  p[x] = p[fr[x]] == -1 ? -1 : p[fr[x]] + 1;
  in[x] = 0;
}
struct E {
  int x, y, k, id;
  bool operator<(const E &a) const { return y < a.y; }
} e[M];
int ans[M];
int main() {
  int i, n = read(), m = read(), q = read();
  for (i = 1; i <= m; ++i) {
    int x = read(), y = read();
    ins(y, x);
  }
  for (i = 0; i < q; ++i)
    e[i].x = read(), e[i].y = read(), e[i].k = read(), e[i].id = i;
  sort(e, e + q);
  for (int x, y, k, la = -1, w = q; w--;) {
    x = e[w].x, y = e[w].y, k = e[w].k;
    if (y != la) {
      memset(v, 0, sizeof v), memset(fr, 63, sizeof fr),
          memset(p, 63, sizeof p);
      dfs(y), p[y] = 1;
      for (i = 1; i <= n; ++i) dfs2(i), f[i][0] = fr[i];
      for (int j = 1; j < 12; ++j)
        for (i = 1; i <= n; ++i)
          if (f[i][j - 1] < inf) f[i][j] = f[f[i][j - 1]][j - 1];
    }
    if (fr[x] > inf)
      ans[e[w].id] = -1;
    else {
      if (p[x] == -1 || p[x] < k)
        ans[e[w].id] = -1;
      else {
        --k;
        for (int j = 0; j < 12; ++j)
          if (k >> j & 1) x = f[x][j];
        ans[e[w].id] = x;
      }
    }
    la = y;
  }
  for (i = 0; i < q; ++i) printf("%d\n", ans[i]);
  return 0;
}
