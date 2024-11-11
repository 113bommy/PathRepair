#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, sum = 0, e, e1, f;
  cin >> n >> m;
  int a[n], dp[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0] = a[0];
  for (int i = 1; i < n; i++) {
    dp[i] = dp[i - 1] + a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> e >> e1;
    e1--;
    e--;
    f = dp[e1] - dp[e - 1];
    if (f > 0 && e1 <= n - 1 && e >= 0) {
      sum = sum + f;
    }
  }
  cout << sum;
  return 0;
}
