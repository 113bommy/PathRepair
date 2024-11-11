#include <bits/stdc++.h>
using namespace std;
const int N(100), M(300000);
long long dp[N][M], k;
int n, a[N];
long long get(int n, long long k) {
  if (n == -1) return 1;
  if (k < M) {
    if (dp[n][k] != -1) return dp[n][k];
    return dp[n][k] = k / a[n] + get(n - 1, k) - get(n - 1, k / a[n]);
  }
  return k / a[n] - get(n - 1, k / a[n]) + get(n - 1, k);
}
int main() {
  cin >> k >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  memset(dp, -1, sizeof dp);
  cout << k - get(n - 1, k);
  return 0;
}
