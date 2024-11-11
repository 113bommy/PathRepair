#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
int n, a[N], dp[N];
int main() {
  int x, y, z, j;
  cin >> n;
  for (int i = 1; i <= (int)(n); ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    x = dp[i - 1] + 20;
    j = lower_bound(a + 1, a + 1 + n, a[i] - 90) - a - 1;
    y = dp[j] + 50;
    j = lower_bound(a + 1, a + 1 + n, a[i] - 1440) - a - 1;
    z = dp[j] + 120;
    dp[i] = min(min(x, y), z);
  }
  for (int i = 1; i <= n; i++) {
    cout << dp[i] - dp[i - 1] << endl;
  }
  return 0;
}
