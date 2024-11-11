#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 3;
char s[N];
long long f[N][N][27];
long long g[N][N];
long long n, m;
int main() {
  scanf("%I64d%I64d", &n, &m);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) {
    f[i][1][s[i] - 'a'] = 1;
    for (int j = 1; j <= i; ++j) {
      for (int k = 0; k < 26; ++k) {
        if (k + 'a' == s[i])
          f[i][j][k] += g[i - 1][j - 1];
        else
          f[i][j][k] += f[i - 1][j][k];
        g[i][j] += f[i][j][k];
      }
    }
  }
  g[n][0] = 1;
  long long k = m, ans = 0;
  for (int i = n; i >= 0; --i) {
    long long num = k >= g[n][i] ? g[n][i] : k;
    ans += num * n - num * i;
    k -= g[n][i];
    if (k <= 0) break;
  }
  if (k <= 0)
    printf("%I64d\n", ans);
  else
    printf("-1");
  return 0;
}
