#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T& x) {
  x = 0;
  char c;
  bool fg = 0;
  while ((unsigned)((c = getchar()) - '0') > 9) {
    if (c == '-') fg = 1;
    if (c == -1) return;
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while ((unsigned)((c = getchar()) - '0') <= 9);
  if (fg) x = -x;
}
template <typename T>
void write(T x) {
  char buff[20];
  int t = 0;
  if (x < 0) x = -x, putchar('-');
  for (; x; x /= 10) buff[t++] = '0' + x % 10;
  if (!t) buff[t++] = '0';
  while (t) putchar(buff[--t]);
}
template <typename T>
void writeln(const T& x) {
  write(x);
  putchar('\n');
}
const int INF = 0x3f3f3f3f;
const int maxn = 100010;
template <typename T>
bool updmx(T& A, const T& B) {
  return A < B ? A = B, 1 : 0;
}
template <typename T>
bool updmn(T& A, const T& B) {
  return A > B ? A = B, 1 : 0;
}
int n, d;
long long h[maxn], f[maxn];
int g[maxn];
int idx[maxn];
void cdq(int l, int r) {
  if (r - l == 1) return;
  int m = (l + r) >> 1;
  stable_partition(idx + l, idx + r, [m](const int& i) { return i < m; });
  cdq(l, m);
  long long mxf = -1;
  int mxj = -1;
  for (int p = l, q = m; p < m || q < r;) {
    int i = idx[q], j = idx[p];
    if (q >= r || (p < m && (j == 0 || h[j] <= h[i] - d))) {
      if (updmx(mxf, f[j])) mxj = j;
      ++p;
    } else {
      if (updmx(f[i], mxf + 1)) g[i] = mxj;
      ++q;
    }
  }
  mxf = -1;
  mxj = -1;
  for (int p = m - 1, q = r - 1; p >= l || q >= m;) {
    int i = idx[q], j = idx[p];
    if (q < m || (p >= l && (j == 0 || h[j] >= h[i] + d))) {
      if (updmx(mxf, f[j])) mxj = j;
      --p;
    } else {
      if (updmx(f[i], mxf + 1)) g[i] = mxj;
      --q;
    }
  }
  cdq(m, r);
  static int tmp[maxn];
  merge(idx + l, idx + m, idx + m, idx + r, tmp + l,
        [](const int& i, const int& j) { return h[i] < h[j]; });
  copy(tmp + l, tmp + r, idx);
}
void dfs(int i) {
  if (!i) return;
  dfs(g[i]);
  write(i);
  putchar(' ');
}
int main() {
  read(n);
  read(d);
  for (int i = 1; i <= n; ++i) read(h[i]);
  memset(f, 0, sizeof f);
  f[0] = g[0] = 0;
  for (int i = 0; i <= n; ++i) idx[i] = i;
  sort(idx, idx + n + 1,
       [](const int& i, const int& j) { return h[i] < h[j]; });
  cdq(0, n + 1);
  long long res = -1;
  int resi = -1;
  for (int i = 1; i <= n; ++i)
    if (updmx(res, f[i])) resi = i;
  writeln(res);
  dfs(resi);
  return 0;
}
