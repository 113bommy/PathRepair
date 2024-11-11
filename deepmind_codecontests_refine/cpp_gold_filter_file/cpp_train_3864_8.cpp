#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, k;
long long dp[N][2 * N][3][3];
long long md(long long x) { return x % 998244353LL; }
long long solve(int p, int x, int flag1, int flag2) {
  if (x > k) return 0LL;
  if (p == n) {
    if (x == k) return 1LL;
    return 0LL;
  }
  long long &ans = dp[p][x][flag1][flag2];
  if (ans != -1LL) return ans;
  int at = 0;
  ans = 0LL;
  if (flag1 != 1 && flag2 != 1) at = 1;
  ans = md(ans + solve(p + 1, x + at, 1, 1));
  at = 0;
  if (flag1 != 0 && flag2 != 0) at = 1;
  ans = md(ans + solve(p + 1, x + at, 0, 0));
  at = 0;
  if (flag1 != 1) at++;
  if (flag2 != 0) at++;
  ans = md(ans + solve(p + 1, x + at, 1, 0));
  at = 0;
  if (flag1 != 0) at++;
  if (flag2 != 1) at++;
  ans = md(ans + solve(p + 1, x + at, 0, 1));
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(dp, -1LL, sizeof(dp));
  cin >> n >> k;
  cout << solve(0, 0, 2, 2) << "\n";
  return 0;
}
