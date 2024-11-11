#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m, q, f[505][505], a[505], b[505], ans;
char s[505];
inline int sub(int x, int y) {
  x -= y;
  if (x < 0) x += 5;
  return x;
}
inline int mult(int x, int y) { return x * y % 5; }
inline int rev(int x) {
  int y = 1;
  while (y % x) y += 5;
  return y / x;
}
inline void gauss() {
  int r = 0;
  for (int i = 0; i < m; ++i) {
    int v = -1;
    for (int j = r; j < n; ++j)
      if (f[j][i] != 0) {
        v = j;
        break;
      }
    if (v == -1) continue;
    a[i] = r;
    swap(f[r], f[v]);
    int x = rev(f[r][i]);
    for (int j = 0; j < m; ++j) f[r][j] = mult(f[r][j], x);
    for (int j = r + 1; j < n; ++j)
      for (int k = m - 1; k >= i; --k)
        f[j][k] = sub(f[j][k], mult(f[r][k], f[j][i]));
    ++r;
  }
  ans = 1;
  for (int i = r; i < n; ++i) ans = 1LL * ans * 5 % mod;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    for (int j = 0; j < m; ++j) f[i][j] = s[j] - 'a';
  }
  memset(a, -1, sizeof a);
  gauss();
  scanf("%d", &q);
  while (q--) {
    scanf("%s", s);
    for (int i = 0; i < m; ++i) b[i] = s[i] - 'a';
    bool bad = false;
    for (int i = 0; i < m; ++i) {
      if (b[i] == 0) continue;
      if (a[i] == -1) {
        bad = true;
        break;
      }
      for (int j = m - 1; j >= i; --j) b[j] = sub(b[j], mult(b[i], f[a[i]][j]));
    }
    if (bad)
      puts("0");
    else
      printf("%d\n", ans);
  }
  return 0;
}
