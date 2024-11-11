#include <bits/stdc++.h>
using namespace std;
int n, x;
long long fr[105][105], bk[105][105], f[105], cnt[105][105][105], l[105];
char s[105];
int main() {
  scanf("%d%d", &n, &x);
  scanf("%s", s + 1);
  memset(cnt, 0, sizeof cnt);
  memset(fr, 0, sizeof fr);
  memset(bk, 0, sizeof bk);
  for (int i = 1; i <= n; i++) cnt[s[i] - '0'][i][i] = 1;
  fr[0][1] = cnt[0][1][1];
  bk[0][n] = cnt[0][n][n];
  fr[1][1] = cnt[1][1][1];
  bk[1][n] = cnt[1][n][n];
  if (n == 1) {
    if (s[0] == '0')
      f[0] = 1;
    else
      f[1] = 1;
  }
  l[0] = l[1] = 2;
  for (int i = 2; i <= x; i++) {
    l[i] = l[i - 1] * l[i - 2] % 1000000007;
    for (int a = 1; a <= n; a++)
      for (int b = a; b <= n; b++)
        cnt[i][a][b] = (cnt[i - 1][a][b] + cnt[i - 2][a][b]) % 1000000007;
    for (int a = 1; a < n; a++)
      for (int b = a; b < n; b++)
        for (int c = b + 1; c <= n; c++)
          cnt[i][a][c] = (cnt[i - 1][a][b] * cnt[i - 2][b + 1][c] % 1000000007 +
                          cnt[i][a][c]) %
                         1000000007;
    for (int a = 1; a <= n; a++) {
      fr[i][a] =
          (fr[i - 2][a] * l[i - 1] % 1000000007 + fr[i][a] + fr[i - 1][a]) %
          1000000007;
      for (int b = a + 1; b <= n; b++)
        fr[i][b] =
            (fr[i - 1][a] * cnt[i - 2][a + 1][b] + fr[i][b]) % 1000000007;
    }
    for (int a = n; a >= 1; a--) {
      bk[i][a] =
          (bk[i - 1][a] * l[i - 2] % 1000000007 + bk[i][a] + bk[i - 2][a]) %
          1000000007;
      for (int b = 1; b < a; b++)
        bk[i][b] =
            (bk[i - 2][a] * cnt[i - 1][b][a - 1] + bk[i][b]) % 1000000007;
    }
    f[i] =
        (f[i - 1] * l[i - 2] % 1000000007 + f[i - 2] * l[i - 1] % 1000000007) %
        1000000007;
    for (int a = 1; a < n; a++)
      f[i] = (fr[i - 1][a] * bk[i - 2][a + 1] % 1000000007 + f[i]) % 1000000007;
  }
  printf("%I64d\n", f[x] % 1000000007);
  return 0;
}
