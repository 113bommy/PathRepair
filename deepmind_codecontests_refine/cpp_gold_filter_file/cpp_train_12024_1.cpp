#include <bits/stdc++.h>
using namespace std;
long long int power(long long int n, long long int p) {
  if (p < 0) return 0;
  long long int res = 1;
  while (p) {
    if (p % 2) res = (res % 1000000007 * n % 1000000007) % 1000000007;
    n = (n % 1000000007 * n % 1000000007) % 1000000007;
    p = p >> 1;
  }
  return res % 1000000007;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    long long int n;
    cin >> n;
    int a[n], i;
    int dp[1000010] = {0};
    for (i = 0; i < n; i++) {
      cin >> a[i];
      dp[a[i]] = 1;
    }
    for (i = 0; i <= 1000010; i++) {
      if (dp[i]) {
        for (int j = 2 * i; j <= 1000010; j += i) {
          if (dp[j]) {
            dp[j] = max(dp[j], dp[i] + 1);
          }
        }
      }
    }
    cout << *max_element(dp, dp + 1000010) << "\n";
  }
}
