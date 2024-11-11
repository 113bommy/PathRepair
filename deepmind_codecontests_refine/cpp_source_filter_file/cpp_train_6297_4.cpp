#include <bits/stdc++.h>
using namespace std;
int n, m, f[1000005], ff[1000005], v[1000005], x[1000005], y[1000005],
    p[1000005];
int gf(int x) {
  if (f[x] == x) return x;
  f[x] = gf(f[x]);
  return f[x];
}
int gff(int x) {
  if (ff[x] == x) return x;
  int rt = gff(ff[x]);
  v[x] ^= v[ff[x]];
  ff[x] = rt;
  return ff[x];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) f[i] = ff[i] = i;
  int poi = n;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &x[i], &y[i], &p[i]);
    if (p[i] == 1) {
      if (gf(x[i]) != gf(y[i])) {
        f[gf(x[i])] = gf(y[i]);
        poi--;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (p[i] == 0) {
      if (gf(x[i]) == gf(y[i])) {
        puts("0");
        return 0;
      }
      int xx = gf(x[i]), yy = gf(y[i]);
      if (gff(xx) == gff(yy)) {
        if (v[xx] == v[yy]) {
          puts("0");
          return 0;
        }
      } else {
        int td = gff(xx);
        v[td] = v[xx] ^ v[yy] ^ 1;
        ff[td] = yy;
        poi--;
      }
    }
  }
  int ans = 1;
  for (int i = 1; i < poi; i++) ans = (ans * 2) % 1000000007;
  printf("%d", ans);
}
