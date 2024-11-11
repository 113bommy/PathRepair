#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long dp[1001][10001][2];
int a[1001];
long long fun(int idx, int sum, int isNegetive) {
  if (idx == 0) return sum == a[0];
  long long &ans = dp[idx][sum][isNegetive];
  if (ans != -1) return ans;
  if (isNegetive) sum *= -1;
  ans = (fun(idx - 1, abs(sum + a[idx]), sum + a[idx] < 0) +
         fun(idx - 1, abs(sum - a[idx]), sum - a[idx] < 0)) %
        MOD;
  if (abs(sum) == a[idx]) ans = (ans + 1) % MOD;
  return ans;
}
int main() {
  int n;
  long long ans = 0;
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) ans = (ans + fun(i, 0, 0)) % MOD;
  printf("%lld\n", ans);
  return 0;
}
