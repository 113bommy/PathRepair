#include <bits/stdc++.h>
using namespace std;
typedef struct point {
  int start;
  int end;
} point;
bool sort_cmp(const point& lhs, const point& rhs) {
  if (lhs.end < rhs.end)
    return true;
  else
    return false;
}
long long dp[1000006];
int main() {
  long long i, j, k, l, n, m, a, t, s, x, y;
  cin >> n;
  for (i = 0; i < 1000006; i++) dp[i] = 100000000;
  dp[0] = 0;
  for (i = 0; i < 9; i++) dp[i + 1] = 1;
  for (i = 10; i <= n; i++) {
    x = i;
    while (x > 0) {
      y = x % 10;
      x = x / 10;
      dp[i] = min(dp[i], dp[i - y] + 1);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
