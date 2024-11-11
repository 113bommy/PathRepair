#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k;
const int M = 1003;
int a[12345678];
bool dp[M][M];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] %= m;
  }
  if (n >= m) {
    cout << "YES";
    return 0;
  }
  for (i = 0; i < n; i++) {
    dp[i][a[i]] = 1;
    for (j = 0; j < m; j++) {
      dp[i][j] = dp[i][j] | dp[i - 1][j];
      dp[i][j] = dp[i][j] | dp[i - 1][(j - a[i] + m) % m];
    }
  }
  dp[n - 1][0] ? cout << "YES" : cout << "NO";
  return 0;
}
