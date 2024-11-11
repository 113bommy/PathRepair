#include <bits/stdc++.h>
using namespace std;
int initial, n, d1, p1;
int cost[11][4];
int dp[1005][11];
int calc(int material, int pos) {
  if (dp[material][pos] != -1) return dp[material][pos];
  if (pos == n) {
    dp[material][pos] = 0;
    return 0;
  }
  int res = 0;
  for (int i = 0;
       i * cost[pos][1] <= cost[pos][0] && i * cost[pos][2] <= material; i++)
    res =
        max(res, calc(material - i * cost[pos][2], pos + 1) + i * cost[pos][3]);
  dp[material][pos] = res;
  return res;
}
int main() {
  cin >> initial >> n >> d1 >> p1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> cost[i][j];
    }
  }
  int res = 0;
  for (int i = 0; i < 1010; i++) {
    for (int j = 0; j < 11; j++) {
      dp[i][j] = -1;
    }
  }
  for (int i = 0; d1 * i <= initial; i++)
    res = max(res, calc(initial - d1 * i, 0) + i * p1);
  cout << res << endl;
}
