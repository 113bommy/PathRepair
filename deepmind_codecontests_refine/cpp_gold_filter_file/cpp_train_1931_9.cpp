#include <bits/stdc++.h>
using namespace std;
const double PI = acos(0) * 2;
const double EPS = 1e-8;
const long long MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int oo = 1e9;
const double foo = 1e30;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcounll(s);
}
int n, m, k, a[1010], dp[1010][1010][11], b[1010], v[1010][1010][11];
int main() {
  cin >> n >> m >> k;
  char x;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    a[i] = x - 'a';
  }
  for (int i = 1; i <= m; i++) {
    cin >> x;
    b[i] = x - 'a';
  }
  a[0] = -1;
  b[0] = -2;
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j][0] = 0;
      for (int t = 0; t <= k; t++) {
        v[i][j][t] = v[i - 1][j - 1][t];
        v[i][j][t] = max(v[i][j][t], v[i - 1][j][t]);
        v[i][j][t] = max(v[i][j][t], v[i][j - 1][t]);
      }
      if (a[i] == b[j]) {
        if (a[i - 1] == b[j - 1]) {
          for (int t = 1; t <= k; t++)
            if (1) {
              dp[i][j][t] = dp[i - 1][j - 1][t] + 1;
              ans = max(ans, dp[i][j][t]);
              v[i][j][t] = max(v[i][j][t], dp[i][j][t]);
            }
        } else {
          for (int t = 0; t < k; t++)
            if (1) {
              dp[i][j][t + 1] = v[i - 1][j - 1][t] + 1;
              v[i][j][t + 1] = max(v[i][j][t + 1], dp[i][j][t + 1]);
              ans = max(ans, dp[i][j][t + 1]);
            }
        }
      } else {
        for (int t = 0; t <= k; t++) {
          if (1) {
            dp[i][j][t] = dp[i - 1][j][t];
            v[i][j][t] = max(v[i][j][t], v[i - 1][j][t]);
          }
          if (1) {
            dp[i][j][t] = max(dp[i][j][t], dp[i][j - 1][t]);
            v[i][j][t] = max(v[i][j][t], v[i][j - 1][t]);
          }
        }
      }
    }
  }
  if (ans == -1) ans = 0;
  cout << ans;
}
