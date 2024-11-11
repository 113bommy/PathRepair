#include <bits/stdc++.h>
using namespace std;
const int size = 1e5 + 7;
const int mod = 1e9 + 7;
int dp[1 << 22], a[size];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, i, j, N = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    dp[a[i]] = a[i];
    while ((1 << N) <= a[i]) N++;
  }
  for (j = 0; j < N; j++)
    for (i = 0; i < (1 << N); i++)
      if ((i >> j) & 1) dp[i] = max(dp[i ^ (1 << j)], dp[i]);
  for (i = 0; i < n; i++)
    cout << (dp[a[i] ^ ((1 << N) - 1)] ? dp[a[i] ^ ((1 << N) - 1)] : -1) << " ";
  return 0;
}
