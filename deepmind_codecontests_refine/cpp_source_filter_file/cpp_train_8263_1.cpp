#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 1e6 + 5;
int c[5];
int dp[N] = {1, 1, 2};
int add(int a, int b) {
  int res = a + b;
  if (res >= mod) res -= mod;
  return res;
}
int mul(int a, int b) { return a * b % mod; }
int main() {
  int n;
  cin >> n;
  for (int i = (0); i < (n); ++i) {
    int x;
    cin >> x;
    c[x]++;
  }
  dp[1] = 1;
  for (int i = (3); i < (c[1] + 1); ++i)
    dp[i] = add(dp[i - 1], mul((i - 1), dp[i - 2]));
  for (int i = (n - c[2] + 1); i < (n + 1); ++i) dp[c[1]] = mul(dp[c[1]], i);
  cout << dp[c[1]] << "\n";
  return 0;
}
