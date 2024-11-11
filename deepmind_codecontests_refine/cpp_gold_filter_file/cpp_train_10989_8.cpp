#include <bits/stdc++.h>
using namespace std;
long long dp[1003];
long long tree(long long h) {
  if (h == 0) return 1;
  if (h == 1) return 2;
  if (dp[h] != -1) return dp[h];
  return dp[h] = tree(h - 1) + tree(h - 2);
}
long long solve(long long remain, long long height) {
  if (remain == 0) return 0;
  if (remain < 0) return -1;
  long long h = max(0LL, height - 1);
  return 1 + solve(remain - tree(h), height + 1);
}
int main() {
  long long N;
  cin >> N;
  memset(dp, -1, sizeof(dp));
  cout << solve(N - 1, 0) << endl;
  return 0;
}
