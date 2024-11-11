#include <bits/stdc++.h>
using namespace std;
int n, m;
int array1[100];
int dp[51][51][1010];
int DP(int i, int j, int k) {
  if (j == m) {
    if (i == n)
      return 0;
    else
      return 1e5;
  }
  if (i == n) return 0;
  if (dp[i][j][k] != -1) return dp[i][j][k];
  int ret = 0, ret1 = 0;
  if (i == 0) {
    ret += min(DP(i + 1, j + 1, array1[j]), DP(i, j + 1, k));
  } else {
    ret = ret + min((abs(array1[j] - k) + DP(i + 1, j + 1, array1[j])),
                    DP(i, j + 1, k));
  }
  return dp[i][j][k] = ret;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> array1[i];
  }
  sort(array1, array1 + m);
  memset(dp, -1, sizeof(dp));
  cout << DP(0, 0, 0) << endl;
}
