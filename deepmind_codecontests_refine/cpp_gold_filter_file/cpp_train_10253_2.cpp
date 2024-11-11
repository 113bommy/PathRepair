#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print_range(const T* begin, const T* end) {}
template <typename T>
inline int sign(const T& a) {
  return a < 0 ? -1 : a > 0;
}
void task();
int main() {
  ios_base::sync_with_stdio(false);
  task();
  return 0;
}
long long dp[110][1111];
void task() {
  long long v1, v2, t, d;
  cin >> v1 >> v2 >> t >> d;
  for (int i = -d; i <= d; i++) {
    if (v1 + i >= 0) {
      dp[1][v1 + i] = v1;
    }
  }
  for (int i = 1; i <= t; i++)
    for (int v = 0; v <= 1100; v++)
      for (int dv = -d; dv <= d; dv++) {
        if (dp[i][v]) {
          if (v + dv >= 0) {
            dp[i + 1][v + dv] = max(dp[i][v] + v, dp[i + 1][v + dv]);
          }
        }
      }
  cout << dp[t - 1][v2] + v2;
}
