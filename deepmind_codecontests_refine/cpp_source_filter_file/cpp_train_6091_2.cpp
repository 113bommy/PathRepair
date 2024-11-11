#include <bits/stdc++.h>
using namespace std;
long long bit[100010], arr[100010], dp[100010][12];
void update(int val, int idx, int n) {
  for (; idx <= n; idx += idx & -idx) bit[idx] += val;
}
long long query(int idx) {
  long long sum = 0;
  for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
  return sum;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    dp[i][1] = 1;
  }
  if (k == 0) return cout << n << "\n", 0;
  for (int j = 2; j <= k + 1; j++) {
    for (int i = 0; i < n; i++) bit[i + 1] = 0;
    for (int i = 1; i < n; i++) {
      update(dp[i - 1][j - 1], arr[i - 1] + 1, n);
      dp[i][j] = query(arr[i]);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) ans += dp[i][k + 1];
  cout << ans << "\n";
  return 0;
}
