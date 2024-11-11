#include <bits/stdc++.h>
using namespace std;
vector<int> v[50010];
int fa[50010], n, q, upfa[50010], f[50010][256], U, V, dep[50010], a[50010];
void dfs(int np, int fath) {
  fa[np] = fath;
  dep[np] = dep[fath] + 1;
  for (int x : v[np])
    if (x != fath) dfs(x, np);
  if (dep[np] > 256) {
    int tp = np;
    for (int j = 1; j <= 256; j++) tp = fa[tp];
    upfa[np] = tp;
    tp = np;
    for (int j = 0; j < 256; j++) {
      int v = (a[tp] ^ j) >> 8;
      f[np][v ^ 255] = max(f[np][v ^ 255], (a[tp] ^ j) | (255 << 8));
      tp = fa[tp];
    }
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 256; j++) {
        if (f[np][j] != -1 && f[np][j ^ (1 << i)] == -1)
          f[np][j ^ (1 << i)] = f[np][j] ^ (256 << i);
      }
    }
  }
}
int main() {
  memset(f, 255, sizeof(f));
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1, ti, tj; i < n; i++) {
    scanf("%d%d", &ti, &tj);
    v[ti].push_back(tj);
    v[tj].push_back(ti);
  }
  dfs(1, 0);
  while (q--) {
    scanf("%d%d", &U, &V);
    int ans = 0, st = V;
    for (int i = 0; dep[upfa[V]] >= dep[U]; i++)
      ans = max(ans, f[V][i]), V = upfa[V];
    while (V != U) {
      ans = max(ans, a[V] ^ (dep[st] - dep[V]));
      V = fa[V];
    }
    ans = max(ans, a[U] ^ (dep[st] - dep[U]));
    printf("%d\n", ans);
  }
  return 0;
}
