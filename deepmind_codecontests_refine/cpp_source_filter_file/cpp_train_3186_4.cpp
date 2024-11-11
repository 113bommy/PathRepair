#include <bits/stdc++.h>
using namespace std;
const int N = 5003;
long long a[N + 2], x[N + 2], dp[N + 2];
int l[N + 2], r[N + 2], cnt[N + 2];
int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 1; i <= N; i++) {
    l[i] = 1000000;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
    l[a[i + 1]] = min(i + 1, l[a[i + 1]]);
    r[a[i + 1]] = max(i + 1, r[a[i + 1]]);
  }
  for (int i = n + 1; i >= 1; i--) {
    if (i == n + 1)
      dp[i] = 0;
    else {
      dp[i] = max(dp[i], dp[i + 1]);
      if (l[a[i]] == i) {
        long long sum = 0;
        int tope = 0;
        int tt = 10000000;
        for (int j = i; j <= n; j++) {
          if (cnt[a[j]] == 0) {
            sum ^= a[j];
            cnt[a[j]] = 1;
          }
          tt = min(tt, l[a[j]]);
          if ((r[a[j]] == j) && tope <= j && tt >= i) {
            dp[i] = max(dp[j + 1] + sum, dp[i]);
          }
          tope = max(tope, r[a[j]]);
        }
        for (int j = i; j <= n; j++) {
          cnt[a[j]] = 0;
        }
      }
    }
  }
  cout << dp[1] << endl;
}
