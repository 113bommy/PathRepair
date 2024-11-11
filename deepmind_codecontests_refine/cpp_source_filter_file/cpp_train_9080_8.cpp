#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3010;
const long long Mod = 998245353;
long long n, m, f[maxn][maxn];
char s[maxn], t[maxn];
signed main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  scanf("%s", t + 1);
  m = strlen(t + 1);
  for (long long i = (1), _end_ = (m + 1); i <= _end_; ++i) f[0][i] = 1;
  for (long long i = (0), _end_ = (n - 1); i <= _end_; ++i) {
    for (long long j = (1), _end_ = (m + 1); j <= _end_; ++j) {
      if (j > 1 && s[i + 1] == t[j - 1])
        f[i + 1][j - 1] = (f[i + 1][j - 1] + f[i][j]) % Mod;
      if (i + j <= m && s[i + 1] == t[i + j])
        f[i + 1][j] = (f[i + 1][j] + f[i][j]) % Mod;
      if (i + j > m) f[i + 1][j] = (f[i + 1][j] + f[i][j]) % Mod;
    }
    f[i + 1][m + 1] = f[i][m + 1] * 2 % Mod;
  }
  long long ans = 0;
  for (long long i = (m), _end_ = (n); i <= _end_; ++i)
    ans = (ans + f[i][1]) % Mod;
  printf("%I64d\n", ans);
  return 0;
}
