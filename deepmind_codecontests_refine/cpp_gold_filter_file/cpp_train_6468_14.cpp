#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmax(T& x, T y) {
  return x < y ? x = y, 1 : 0;
}
template <class T>
bool ckmin(T& x, T y) {
  return x > y ? x = y, 1 : 0;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? x : -x;
}
const int N = 105;
int n, num[N], s[N];
long long dp[N][N][N], f[N];
char str[N];
signed main() {
  scanf("%d%s", &n, str + 1);
  for (int i = 1, iend = n; i <= iend; ++i) f[i] = read(), s[i] = str[i] - '0';
  for (int i = 1, iend = n; i <= iend; ++i)
    for (int j = 1, jend = i - 1; j <= jend; ++j) ckmax(f[i], f[j] + f[i - j]);
  for (int i = 1, iend = n; i <= iend; ++i)
    for (int j = i + 1, jend = n; j <= jend; ++j) num[i] += s[j] == s[i];
  for (int i = n, iend = 1; i >= iend; --i) {
    for (int j = i, jend = n; j <= jend; ++j) {
      for (int k = 0, kend = num[j]; k <= kend; ++k)
        ckmax(dp[i][j][k], dp[i][j - 1][0] + f[k + 1]);
      for (int k = i, kend = j - 1; k <= kend; ++k) {
        if (s[j] == s[k]) {
          for (int l = 0, lend = num[j]; l <= lend; ++l)
            ckmax(dp[i][j][l], dp[i][k][l + 1] + dp[k + 1][j - 1][0]);
        }
      }
    }
  }
  cout << dp[1][n][0] << '\n';
}
