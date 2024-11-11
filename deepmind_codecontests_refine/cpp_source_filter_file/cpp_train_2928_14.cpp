#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;
long long a[N];
int n, k, x;
long long dp[N][N][N];
long long solve(int idx, int last, int now) {
  if (idx - last > k) return INT_MIN;
  if (idx - 1 == n) return (now == x ? 0 : -1e15);
  if (dp[idx][last][now] != -1) return dp[idx][last][now];
  long long ans = solve(idx + 1, last, now);
  ans = max(ans, a[idx] + solve(idx + 1, idx, now + 1));
  return dp[idx][last][now] = ans;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(dp, -1, sizeof(dp));
  long long ans = solve(1, 0, 0);
  cout << (ans <= 0 ? -1 : ans);
  return 0;
}
