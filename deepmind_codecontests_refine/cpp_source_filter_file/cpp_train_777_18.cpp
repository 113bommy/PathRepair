#include <bits/stdc++.h>
int sz[200010], fr[200010], v[400010], w[400010], ne[400010], bs = 0;
void addb(int a, int b, int c) {
  v[bs] = b;
  w[bs] = c;
  ne[bs] = fr[a];
  fr[a] = bs++;
}
double cal(int u, int f, long long h) {
  double rt = sz[u] * pow(h, 1.5);
  for (int i = fr[u]; i != -1; i = ne[i]) {
    if (v[i] != f) rt += cal(v[i], u, h + w[i]);
  }
  return rt;
}
bool bk[200010];
int count(int u, int f) {
  int rt = 1;
  for (int i = fr[u]; i != -1; i = ne[i]) {
    if (v[i] != f && !bk[v[i]]) rt += count(v[i], u);
  }
  return rt;
}
int mi, xx;
int dfs0(int u, int f, int nn) {
  int rt = 1, ma = 0;
  for (int i = fr[u]; i != -1; i = ne[i]) {
    if (v[i] != f && !bk[v[i]]) {
      int t = dfs0(v[i], u, nn);
      rt += t;
      if (t > ma) ma = t;
    }
  }
  if (nn - rt > ma) ma = nn - rt;
  if (ma < mi) mi = ma, xx = u;
  return rt;
}
int getzx(int u) {
  mi = 1e9;
  int nn = count(u, 0);
  dfs0(u, 0, nn);
  return xx;
}
double qiudao(int u, int f, long long h) {
  double rt = sz[u] * sqrt(h);
  for (int i = fr[u]; i != -1; i = ne[i]) {
    if (v[i] != f) rt += cal(v[i], u, h + w[i]);
  }
  return rt;
}
double ans = 1e30;
int wz;
void dfs(int u) {
  u = getzx(u);
  bk[u] = true;
  double jg = cal(u, 0, 0);
  if (jg < ans) ans = jg, wz = u;
  double dh = qiudao(u, 0, 0), zx = 1e20;
  int wi = -1;
  for (int i = fr[u]; i != -1; i = ne[i]) {
    if (bk[v[i]]) continue;
    double d = qiudao(v[i], u, w[i]);
    if (dh - d * 2 < zx) zx = dh - d * 2, wi = i;
  }
  if (wi != -1) dfs(v[wi]);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    fr[i] = -1;
    scanf("%d", &sz[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    addb(a, b, c);
    addb(b, a, c);
  }
  dfs(1);
  printf("%d %.8lf", wz, ans);
  return 0;
}
