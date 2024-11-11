#include <bits/stdc++.h>
using namespace std;
int n, t[155][4], m, f[155][55][55][55], c[4];
char s[155];
void up(int i, int j, int k, int l, int d) {
  if (j > m || k > m || l > m || !i) return;
  (f[i][j][k][l] += d) %= 51123987;
}
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) s[i] -= 'a';
  for (int i = n; i >= 1; --i) {
    c[s[i]] = i;
    for (int j = 0; j < 3; ++j) t[i][j] = c[j];
  }
  m = n / 3 + 1;
  f[1][0][0][0] = 1;
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= m; ++j)
      for (int k = 0; k <= m; ++k)
        for (int l = 0; l <= m; ++l) {
          int p = f[i][j][k][l];
          if (j + k + l == n && abs(j - k) < 2 && abs(j - l) < 2 &&
              abs(k - l) < 2)
            (ans += p) %= 51123987;
          up(t[i][0], j + 1, k, l, p);
          up(t[i][1], j, k + 1, l, p);
          up(t[i][2], j, k, l + 1, p);
        }
  printf("%d\n", ans);
}
