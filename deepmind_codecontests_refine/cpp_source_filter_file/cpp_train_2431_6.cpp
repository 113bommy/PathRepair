#include <bits/stdc++.h>
using namespace std;
template <typename T>
T next_int() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return p * x;
}
const int max_int = (int)1e9 + 227 + 1;
const int max_n = (int)1e6 + 227 + 1;
const int mod = (int)1e9 + 7;
int a[max_n];
long long kek[max_n], lol[max_n];
long long dp[max_n][4];
int main() {
  int n = next_int<int>();
  for (int i = 0; i < n - 1; i++) a[i] = next_int<int>();
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == 1) {
      dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + a[i] - (1 - a[i] % 2));
      dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + a[i] - (1 - a[i] % 2));
    } else {
      dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + a[i] - (1 - a[i] % 2));
      dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + a[i] - (1 - a[i] % 2));
      dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + a[i] / 2 * 2);
    }
  }
  for (int i = n - 1; i >= 1; i--) {
    if (a[i - 1] == 1) {
      dp[i - 1][3] =
          max(dp[i - 1][3], dp[i][2] + a[i - 1] - (1 - a[i - 1] % 2));
      dp[i - 1][3] =
          max(dp[i - 1][3], dp[i][3] + a[i - 1] - (1 - a[i - 1] % 2));
    } else {
      dp[i - 1][3] =
          max(dp[i - 1][3], dp[i][2] + a[i - 1] - (1 - a[i - 1] % 2));
      dp[i - 1][3] =
          max(dp[i - 1][3], dp[i][3] + a[i - 1] - (1 - a[i - 1] % 2));
      dp[i - 1][2] = max(dp[i - 1][2], dp[i][2] + a[i - 1] / 2 * 2);
    }
  }
  long long k = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == 1) {
      k = 0;
    } else
      k += a[i] / 2 * 2;
    lol[i] = k;
  }
  k = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] == 1) {
      k = 0;
    } else
      k += a[i] / 2 * 2;
    kek[i] = k;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dp[i][1] + kek[i]);
    ans = max(ans, lol[i] + dp[i][3]);
  }
  cout << ans << "\n";
}
