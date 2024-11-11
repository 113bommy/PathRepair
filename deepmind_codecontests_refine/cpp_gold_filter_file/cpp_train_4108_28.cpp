#include <bits/stdc++.h>
using namespace std;
long long b[100001];
long long dp[100001];
int main() {
  long long n;
  cin >> n;
  long long a[n];
  set<long long> s;
  long long mx = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]] += 1;
    mx = max(mx, a[i]);
  }
  dp[1] = b[1];
  for (long long i = 2; i <= mx; i++) {
    dp[i] = max(dp[i - 2] + b[i] * i, dp[i - 1]);
  }
  cout << dp[mx] << "\n";
}
