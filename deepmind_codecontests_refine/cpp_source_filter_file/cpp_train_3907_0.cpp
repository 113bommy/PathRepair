#include <bits/stdc++.h>
using namespace std;
void ri(long long &x) {
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
void pi(long long x, char ch = '\n') {
  print(x);
  putchar(ch);
}
long long n, m, t;
long long s[100010], cnt;
struct node {
  long long num, next;
} mp[100010 << 1];
void init(long long x, long long y) {
  mp[++cnt].next = s[x];
  mp[cnt].num = y;
  s[x] = cnt;
}
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
long long size[100010], dep[100010];
long long sum1[100010], sum2[100010];
long long f[100010][20];
void dfs1(long long x, long long fa) {
  size[x] = 1;
  if (x != 1) dep[x] = dep[fa] + 1;
  f[x][0] = fa;
  for (long long i = 1; i <= t; i++) f[x][i] = f[f[x][i - 1]][i - 1];
  for (long long i = s[x]; i; i = mp[i].next) {
    long long y = mp[i].num;
    if (y == fa) continue;
    dfs1(y, x);
    size[x] += size[y];
    sum1[x] += sum1[y] + size[y];
  }
}
void dfs2(long long x, long long d) {
  sum2[x] = d;
  for (long long i = s[x]; i; i = mp[i].next) {
    long long y = mp[i].num;
    if (y == f[x][0]) continue;
    dfs2(y, d + sum1[x] - sum1[y] - size[y] + n - size[y]);
  }
}
long long lca(long long x, long long y) {
  for (long long i = t; i >= 0; i--)
    if (dep[f[x][i]] >= dep[y]) x = f[x][i];
  if (x == y) return x;
  for (long long i = t; i >= 0; i--)
    if (f[x][i] != f[y][i]) {
      x = f[x][i];
      y = f[y][i];
    }
  return f[x][0];
}
signed main() {
  ri(n), ri(m);
  t = log2(n);
  for (long long i = 2; i <= n; i++) {
    long long x, y;
    ri(x), ri(y);
    init(x, y);
    init(y, x);
  }
  dfs1(1, 1);
  dfs2(1, 0);
  while (m--) {
    long long x, y;
    ri(x), ri(y);
    if (dep[x] < dep[y]) swap(x, y);
    long long z = lca(x, y);
    if (z == y) {
      long long zson = x;
      for (long long i = t; i >= 0; i--)
        if (dep[f[zson][i]] > dep[y]) zson = f[zson][i];
      long long fz, fm;
      fz = sum1[x] * (n - size[zson]) +
           (sum2[y] + sum1[y] - sum1[zson] - size[zson]) * size[x] +
           1ll * (dep[x] - dep[y] + 1) * size[x] * (n - size[zson]);
      fm = 1ll * size[x] * (n - size[zson]);
      double res = fz * 1.0 / fm;
      printf("%0.8lf", res);
    } else {
      long long fz, fm;
      fz = sum1[x] * size[y] + sum1[y] * size[x] +
           1ll * (dep[x] + dep[y] - 2 * dep[z] + 1) * size[x] * size[y];
      fm = 1ll * size[x] * size[y];
      double res = fz * 1.0 / fm;
      printf("%0.8lf", res);
    }
  }
}
