#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dp[N][321];
int main() {
  int n, q;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int s = sqrt(n);
  int t;
  if (s * s == n) {
    t = s - 1;
  } else {
    t = s;
  }
  for (int k = 1; k <= t; k++) {
    for (int i = n; i >= 1; i--) {
      if (i + a[i] + k > n)
        dp[i][k] = 1;
      else
        dp[i][k] = dp[i + a[i] + k][k] + 1;
    }
  }
  cin >> q;
  while (q--) {
    int p, k;
    cin >> p >> k;
    if (k <= t)
      cout << dp[p][k] << endl;
    else {
      int cnt = 0;
      while (p <= n) {
        cnt++;
        p = p + a[p] + k;
      }
      cout << cnt << endl;
    }
  }
}
