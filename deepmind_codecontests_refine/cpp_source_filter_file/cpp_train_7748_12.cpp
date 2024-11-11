#include <bits/stdc++.h>
using namespace std;
int DP[2001][2001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i <= n; i++) DP[1][i] = 1;
  for (int i = 1; i < k; i++)
    for (int j = 1; j <= n; j++)
      for (int d = 1; d * j <= n; d++)
        DP[i + 1][d * j] = (DP[i + 1][d * j] + DP[i][j]) % 1000000007;
  int ans = 0;
  for (int i = 0; i <= n; i++) ans = (ans + DP[k][i]) % 1000000007;
  cout << ans;
  return 0;
}
