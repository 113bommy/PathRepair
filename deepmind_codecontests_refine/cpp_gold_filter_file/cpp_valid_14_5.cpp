#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
long long ceiling(long long a, long long b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
long long power(long long a, long long b) {
  if (b == 0)
    return 1;
  else if (b % 2 == 1) {
    long long k = power(a, b / 2) % mod;
    return (((a * k) % mod) * k) % mod;
  } else {
    long long k = power(a, b / 2) % mod;
    return (k * k) % mod;
  }
}
long long gcd(long long a, long long b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool comparePairs(vector<long long> &a, vector<long long> &b) {
  long long cnt = 0;
  for (int i = 0; i < 5; i++) {
    if (a[i] < b[i]) cnt++;
  }
  return cnt >= 3;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long q;
  cin >> q;
  while (q--) {
    long long n, k, i, j;
    cin >> n >> k;
    vector<long long> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    long long ans = -1;
    for (i = 1; i < n + 1; i++) {
      for (j = 1; j < i + 1; j++) {
        long long k = (a[i - 1] == j) ? 1 : 0;
        dp[i][j] = max(k + dp[i - 1][j - 1], dp[i - 1][j]);
      }
    }
    for (i = 0; i <= n; i++) {
      if (dp[n][i] >= k) ans = max(ans, i);
    }
    if (ans != -1)
      cout << n - ans << endl;
    else
      cout << -1 << endl;
  }
}
