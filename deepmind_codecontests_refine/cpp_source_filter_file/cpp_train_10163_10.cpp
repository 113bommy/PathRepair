#include <bits/stdc++.h>
using namespace std;
template <typename T, typename L>
inline bool smax(T &x, L y) {
  return x < y ? (x = y, true) : false;
}
template <typename T, typename L>
inline bool smin(T &x, L y) {
  return y < x ? (x = y, true) : false;
}
constexpr int MAXN = 1e6 + 15;
const int MAXM = 10;
int dp[MAXN];
int a[MAXM];
int n;
int main() {
  a[0] = 1, a[1] = 5, a[2] = 10, a[3] = 25, a[4] = 50, a[5] = 100, a[6] = 250,
  a[7] = 500, a[8] = 1000, a[9] = 2500;
  dp[0] = true;
  cin >> n;
  for (int i = 0; i < 10; i++) {
    for (int j = a[i]; j <= MAXN; j++) {
      dp[j] += dp[j - a[i]];
      if (dp[j] == n) {
        cout << j << ' ' << i << '\n';
        for (int k = 0; k <= i; k++) {
          cout << a[k] << ' ';
        }
        return cout << '\n', false;
      }
    }
  }
  for (int i = 1; i <= 1e6; i++) {
    if (dp[i] == n) {
      cout << i << ' ' << 10 << '\n';
      for (int j = 0; j < 10; j++) {
        cout << a[j] << ' ';
      }
      return cout << '\n', false;
    }
  }
}
