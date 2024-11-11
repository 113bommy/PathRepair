#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
const int mod = 5;
const int mod1 = 1e9 + 7;
const int inv[] = {0, 1, 3, 2, 4};
int a[maxn][maxn], ans[maxn];
char s[maxn];
int gauss(int n, int m, int x) {
  int row = 0, ret = 1;
  for (int i = 0; i < x; ++i) {
    int p = row;
    for (int j = row + 1; j < n; ++j) {
      if (a[j][i] > a[p][i]) p = j;
    }
    for (int j = 0; j < m; ++j) swap(a[row][j], a[p][j]);
    if (a[row][i] == 0) continue;
    for (int j = 0; j < n; ++j) {
      if (a[j][i] == 0 || j == row) continue;
      int q = (mod - a[j][i] * inv[a[row][i]]) % mod;
      for (int k = i; k < m; ++k) {
        a[j][k] = (a[j][k] + a[row][k] * q) % mod;
      }
    }
    ++row;
  }
  for (int i = 0; i < x - row; ++i) ret = 5LL * ret % mod1;
  return ret;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    for (int j = 0; j < m; ++j) a[j][i] = s[j] - 'a';
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%s", s);
    for (int j = 0; j < m; ++j) a[j][i + n] = s[j] - 'a';
  }
  int tmp = gauss(m, q + n, n);
  for (int i = 0; i < q; ++i) ans[i] = tmp;
  for (int i = 0; i < m; ++i) {
    bool all_zero = true;
    for (int j = 0; j < n; ++j)
      if (a[i][j]) all_zero = false;
    if (all_zero) {
      for (int j = n; j < n + q; ++j)
        if (a[i][j]) ans[j - n] = 0;
    }
  }
  for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
  return 0;
}
