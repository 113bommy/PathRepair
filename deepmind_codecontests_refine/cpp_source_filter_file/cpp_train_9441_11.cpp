#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long int n, k;
long long int arr[100];
long long int csum[100];
bool way(long long int mask, long long int targ) {
  long long int dp[n + 5][k + 10];
  memset(dp, false, sizeof dp);
  dp[0][0] = true;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 0; j < i; j++) {
      if (((csum[i] - csum[j]) & mask & targ) == targ) {
        for (long long int p = 0; p <= k; p++) {
          if (dp[j][p]) {
            dp[i][p + 1] = true;
          }
        }
      }
    }
  }
  return dp[n][k];
}
int main() {
  cin >> n >> k;
  csum[0] = 0;
  for (long long int i = 1; i <= n; i++) {
    cin >> arr[i];
    csum[i] = csum[i - 1] + arr[i];
  }
  long long int ans = 0;
  for (long long int i = 55; i >= 0; i--) {
    if (way(~((1 << i) - 1), ans | (1 << i))) {
      ans |= (1 << i);
    }
  }
  cout << ans;
  return 0;
}
