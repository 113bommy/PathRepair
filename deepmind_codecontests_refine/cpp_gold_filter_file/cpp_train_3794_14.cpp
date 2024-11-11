#include <bits/stdc++.h>
using namespace std;
long long m, k, n, dp[205][205], a[205][205];
void init() {
  memset(dp, 0, sizeof(dp));
  dp[1][0] = 1, dp[1][1] = 1;
  for (int i = 2; i <= 64; i++) {
    for (int j = 1; j < i; j++) {
      for (int k = 0; k <= 64; k++) {
        dp[i][k + 1] += dp[j][k];
      }
    }
  }
}
long long calc(long long n) {
  long long ans = 0, cnt = 0;
  for (long long i = 63; i >= 0; i--) {
    if (n & (1ll << i)) {
      if (k > cnt) {
        for (int j = 0; j <= i; j++) {
          ans += dp[j][k - cnt];
        }
      }
      cnt++;
      if (cnt == k) {
        ans++;
      }
    }
  }
  return ans;
}
void work() {
  long long low = 1, high = 1e18;
  while (low < high) {
    long long mid = (low + high) / 2;
    long long tmp = calc(mid * 2) - calc(mid);
    if (tmp == m) {
      cout << mid << endl;
      return;
    }
    if (tmp < m) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
}
int main() {
  init();
  while (cin >> m >> k) {
    work();
  }
  return 0;
}
