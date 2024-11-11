#include <bits/stdc++.h>
int fr[3010], ne[6010], v[6010], bs = 0;
void addb(int a, int b) {
  v[bs] = b;
  ne[bs] = fr[a];
  fr[a] = bs++;
}
int bk[3010], sd[3010], hu[3010], fa[3010], sl = 0;
void dfs1(int u, int f) {
  bk[u] = 1;
  fa[u] = f;
  sd[u] = sd[f] + 1;
  for (int i = fr[u]; i != -1; i = ne[i]) {
    if (v[i] == f) continue;
    if (bk[v[i]]) {
      if (sd[v[i]] < sd[u]) {
        int t = u;
        while (1) {
          hu[sl++] = t;
          if (t == v[i]) break;
          t = fa[t];
        }
      }
    } else
      dfs1(v[i], u);
  }
}
int hd[3010], ro[3010], lc[3010][3010], wz[3010];
void dfs2(int u, int f, int rt) {
  fa[u] = f;
  ro[u] = rt;
  sd[u] = sd[f] + 1;
  for (int i = fr[u]; i != -1; i = ne[i]) {
    if (v[i] == f || hd[v[i]]) continue;
    dfs2(v[i], u, rt);
  }
}
int dfs3(int a, int b) {
  if (a == b) return lc[a][b] = a;
  if (lc[a][b]) return lc[a][b];
  if (sd[a] > sd[b])
    lc[a][b] = dfs3(fa[a], b);
  else
    lc[a][b] = dfs3(a, fa[b]);
  return lc[a][b];
}
int getdis(int a, int b) {
  int l = dfs3(a, b);
  return sd[a] + sd[b] - sd[l] * 2 + 1;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) fr[i] = -1;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a += 1;
    b += 1;
    addb(a, b);
    addb(b, a);
  }
  dfs1(1, 0);
  for (int i = 0; i < sl; i++) {
    hd[hu[i]] = 1;
    wz[hu[i]] = i;
  }
  for (int i = 0; i < sl; i++) dfs2(hu[i], 0, hu[i]);
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (ro[i] == ro[j])
        ans += 1.0 / getdis(i, j);
      else {
        int a = sd[i] + sd[j];
        int b = wz[ro[i]] - wz[ro[j]];
        if (b < 0) b = -b;
        b -= 1;
        int c = sl - 2 - b;
        ans += 1.0 / (a + b);
        ans += 1.0 / (a + c);
        ans -= 1.0 / (a + b + c);
      }
    }
  }
  printf("%.10lf", ans);
  return 0;
}
