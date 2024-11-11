#include <bits/stdc++.h>
using namespace std;
int n, k, a[150], b[150], dp[150][10050];
long long int INF = 999999999;
int rec(int num, int balance) {
  if (num == n) {
    if (balance == 0)
      return 0;
    else
      return -INF;
  }
  if (dp[num][balance] != -1) return dp[num][balance];
  int x1 = rec(num + 1, balance);
  int x2 = rec(num + 1, balance + a[num] - k * b[num]) + a[num];
  return dp[num][balance] = max(x1, x2);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  if (rec(0, 0) < 1)
    cout << -1;
  else
    cout << rec(0, 0);
  return 0;
}
