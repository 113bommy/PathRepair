#include <bits/stdc++.h>
const int maxn = (int)1e6;
const int mod = (int)1e9 + 7;
using namespace std;
int n;
long long dp[maxn];
long long a[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0] = abs(a[0]);
  for (int i = 1; i < n; i++) {
    dp[i] = abs(a[i] - a[i - 1]) + dp[i - 1];
  }
  cout << dp[n - 1];
  return 0;
}
