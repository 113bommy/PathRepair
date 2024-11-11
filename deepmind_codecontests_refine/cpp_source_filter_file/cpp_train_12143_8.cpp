#include <bits/stdc++.h>
using namespace std;
const int N = 47;
const int mod = (1e9 + 7);
int a[1 << 23], b[1 << 23];
int n, tot, ans, fa[N], sz[N], bl[N], w[N][N];
char s[N][N];
int ask(int x) { return fa[x] == x ? x : fa[x] = ask(fa[x]); }
void unite(int x, int y) {
  int p = ask(x), q = ask(y);
  if (p == q) return;
  fa[p] = q;
  sz[q] += sz[p];
  sz[p] = 0;
}
void init() {
  for (int i = 2; i <= (1 << tot); i <<= 1) {
    int I = i >> 1;
    for (int j = 0; j < (1 << tot); j += i) {
      for (int k = j; k < j + I; ++k) {
        a[k + I] += a[k];
        if (a[k + I] >= mod) a[k + I] -= mod;
      }
    }
  }
  for (int i = 0; i <= (1 << tot) - 1; ++i) {
    int t = 0;
    for (int j = 0; j <= tot - 1; ++j)
      if (!(i >> j & 1)) t ^= 1;
    if (t)
      b[i] = -a[i];
    else
      b[i] = a[i];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (s[i][j] == 'A') unite(i, j);
  for (int i = 1; i <= n; ++i)
    if (sz[i] != 1)
      if (ask(i) == i) tot++, bl[i] = tot;
  for (int i = 1; i <= n; ++i)
    if (sz[i] != 1) bl[i] = bl[ask(i)];
  for (int i = 1; i <= tot; ++i)
    for (int j = 1; j <= tot; ++j) w[i][j] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (bl[i] && bl[j]) {
        if (s[i][j] == 'X' && bl[i] == bl[j]) {
          printf("-1\n");
          return 0;
        }
        if (s[i][j] == 'X') w[bl[i]][bl[j]] = 0;
      }
  if (tot == 0) {
    printf("%d\n", n - 1);
    return 0;
  }
  for (int i = 1; i <= tot; ++i)
    for (int j = 1; j <= tot; ++j)
      if (w[i][j]) w[i][0] |= (1 << j - 1);
  for (int i = 1; i <= (1 << tot) - 1; ++i) {
    int W = (1 << tot) - 1;
    for (int j = 1; j <= tot; ++j)
      if (i >> j - 1 & 1) W = W & w[j][0];
    if ((W & i) == i) a[i] = 1;
  }
  init();
  for (int i = 1; i <= tot; ++i) {
    int res = 0;
    for (int j = 0; j <= (1 << tot) - 1; ++j) {
      res += b[j];
      if (res >= mod) res -= mod;
    }
    if (res) {
      printf("%d\n", n + i - 1);
      return 0;
    }
    for (int j = 0; j <= (1 << tot) - 1; ++j) b[j] = 1LL * b[j] * a[j] % mod;
  }
}
