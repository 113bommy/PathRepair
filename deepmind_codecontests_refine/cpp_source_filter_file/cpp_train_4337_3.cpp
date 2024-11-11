#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 101, MAX_M = 100001;
int n;
int a[MAX_N];
long long m, dp[MAX_N][MAX_M];
long long dfs(int k, long long m) {
  if (k >= n || m == 0) {
    return 0;
  }
  if (m < MAX_M && dp[k][m] != -1) {
    return dp[k][m];
  }
  long long ret = dfs(k + 1, m) - dfs(k + 1, m / a[k]);
  if (m < MAX_M) {
    dp[k][m] = ret;
  }
  return ret;
}
int main() {
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n, greater<int>());
  memset(dp, -1, sizeof(dp));
  cout << dfs(0, m) << endl;
}
