#include <bits/stdc++.h>
using namespace std;
template <typename T>
void R(T &x) {
  x = 0;
  char ch = getchar();
  while (ch < '0' || '9' < ch) ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}
void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
const int N = 1510000, M = 1510000;
struct OP {
  int p, x, y;
} a[M];
struct Q {
  int x, id, fg, q;
  bool operator<(const Q &rhs) const { return id < rhs.id; }
} c[M];
int n, m, b[N];
char s[20];
struct F1 {
  int f[N], tot, g[N];
  int getf(int x) {
    if (f[x] == x) return x;
    int t = getf(f[x]);
    g[x] = max(g[x], g[f[x]]);
    return f[x] = t;
  }
  inline int ver(int x, int y) {
    ++tot;
    f[tot] = tot;
    f[x] = f[y] = tot;
    return tot;
  }
  inline int getv(int x) {
    getf(x);
    return g[x];
  }
} f1;
struct F2 {
  int f[N], tot, sz[N];
  long long g[N], G[N];
  inline int getf(int x) {
    if (f[x] == x) return x;
    int t = getf(f[x]);
    g[x] += g[f[x]];
    return f[x] = t;
  }
  inline int ver(int x, int y) {
    ++tot;
    f[tot] = tot;
    g[x] = G[x];
    g[y] = G[y];
    G[x] = G[y] = 0;
    sz[tot] = sz[x] + sz[y];
    f[x] = f[y] = tot;
    return tot;
  }
  inline long long getv(int x) {
    int t = getf(x);
    return g[x] + G[t];
  }
} f2;
int cnt, num;
long long ans[M];
int main() {
  R(n), R(m);
  for (int i = 1; i <= n; ++i) f1.f[i] = i, f2.f[i] = i, f2.sz[i] = 1;
  f1.tot = f2.tot = n;
  for (int i = 1; i <= m; ++i) {
    scanf("%s", s);
    if (s[0] == 'U') {
      a[i].p = 1;
      R(a[i].x), R(a[i].y);
    }
    if (s[0] == 'M') {
      a[i].p = 2;
      R(a[i].x), R(a[i].y);
    }
    if (s[0] == 'A') {
      a[i].p = 3;
      R(a[i].x);
    }
    if (s[0] == 'Z') {
      a[i].p = 4;
      R(a[i].x);
    }
    if (s[0] == 'Q') {
      a[i].p = 5;
      R(a[i].x);
    }
  }
  for (int i = 1; i <= n; ++i) b[i] = i;
  for (int i = 1; i <= m; ++i) {
    if (a[i].p == 2) b[a[i].x] = f1.ver(b[a[i].x], b[a[i].y]);
    if (a[i].p == 4) f1.g[b[a[i].x]] = i;
    if (a[i].p == 5) {
      ++num;
      c[++cnt].x = a[i].x;
      c[cnt].id = f1.getv(a[i].x);
      c[cnt].q = num;
      c[cnt].fg = -1;
      c[++cnt].x = a[i].x;
      c[cnt].id = i;
      c[cnt].fg = 1;
      c[cnt].q = num;
    }
  }
  sort(c + 1, c + 1 + cnt);
  int j = 1;
  for (int i = 1; i <= n; ++i) b[i] = i;
  for (int i = 0; i <= m; ++i) {
    if (a[i].p == 1) b[a[i].x] = f2.ver(b[a[i].x], b[a[i].y]);
    if (a[i].p == 3) f2.G[b[a[i].x]] += f2.sz[b[a[i].x]];
    while (j <= cnt && c[j].id <= i) {
      ans[c[j].q] += c[j].fg * f2.getv(c[j].x);
      ++j;
    }
  }
  for (int i = 1; i <= num; ++i) writeln(ans[i]);
  return 0;
}
