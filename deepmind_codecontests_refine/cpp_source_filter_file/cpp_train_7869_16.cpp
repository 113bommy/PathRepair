#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;
const int MOD = (int)1e9 + 7;
int n, m, a[MAXN][MAXN], b[MAXN][MAXN];
char S[MAXN];
int Power(int a, int k, int MOD) {
  int ans = 1;
  while (k) {
    if (k & 1) ans = (long long)ans * a % MOD;
    a = (long long)a * a % MOD;
    k >>= 1;
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", S + 1);
    for (int j = 1; j <= m; ++j) a[j][i] = S[j] - 'a';
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) b[i][j] = 0;
    b[i][i] = 1;
  }
  int r = 1;
  for (int c = 1; r <= 1 && c <= n; ++c) {
    if (a[r][c] == 0) {
      for (int i = r + 1; i <= m; ++i)
        if (a[i][c] != 0) {
          for (int j = 1; j <= n; ++j) swap(a[r][j], a[i][j]);
          for (int j = 1; j <= m; ++j) swap(b[r][j], b[i][j]);
          break;
        }
      if (a[r][c] == 0) continue;
    }
    int t = Power(a[r][c], 3, 5);
    for (int j = 1; j <= n; ++j) a[r][j] = a[r][j] * t % 5;
    for (int j = 1; j <= m; ++j) b[r][j] = b[r][j] * t % 5;
    for (int i = r + 1; i <= m; ++i) {
      int t = a[i][c];
      for (int j = 1; j <= n; ++j)
        a[i][j] = ((a[i][j] - t * a[r][j]) % 5 + 5) % 5;
      for (int j = 1; j <= m; ++j)
        b[i][j] = ((b[i][j] - t * b[r][j]) % 5 + 5) % 5;
    }
    r++;
  }
  r--;
  int q;
  scanf("%d", &q);
  while (q--) {
    scanf("%s", S + 1);
    int ok = 1;
    for (int i = 1; i <= m; ++i) {
      int allZero = 1;
      for (int j = 1; j <= n; ++j) allZero &= a[i][j] == 0;
      if (allZero == 0) continue;
      int c = 0;
      for (int j = 1; j <= m; ++j)
        c = ((c + (S[j] - 'a') * b[i][j]) % 5 + 5) % 5;
      if (c != 0) ok = 0;
    }
    if (ok)
      printf("%d\n", Power(5, n - r, MOD));
    else
      puts("0");
  }
  return 0;
}
