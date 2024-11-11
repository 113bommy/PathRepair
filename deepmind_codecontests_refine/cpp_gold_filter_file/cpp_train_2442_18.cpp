#include <bits/stdc++.h>
using namespace std;
int n, k;
int place[1005][8];
int num[8][1005];
int dp[1005];
bool is_forward(int a, int b) {
  for (int i = 0; i < k; i++) {
    if (place[a][i] <= place[b][i]) {
      return false;
    }
  }
  return true;
}
int f(int idx) {
  if (dp[idx] != -1) return dp[idx];
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (is_forward(i, idx)) ans = max(ans, 1 + f(i));
  }
  dp[idx] = ans;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      cin >> num[i][j];
      place[num[i][j]][i] = j;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, f(i));
  cout << ans << endl;
  return 0;
}
