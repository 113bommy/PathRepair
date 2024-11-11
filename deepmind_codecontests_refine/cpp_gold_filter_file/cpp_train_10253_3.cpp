#include <bits/stdc++.h>
using namespace std;
int dp[20001][150];
int Solve(int v1, int v2, int t, int d) {
  if (t == 0) {
    if (abs(v1 - v2) <= d)
      return 0;
    else
      return -1000000;
  }
  if (dp[v1][t] != -1) return dp[v1][t];
  int ret = -100000000;
  for (int i = v1 - d; i <= v1 + d; i++) {
    if (i < 0) continue;
    ret = max(ret, i + Solve(i, v2, t - 1, d));
  }
  return dp[v1][t] = ret;
}
int main() {
  int v1, v2, t, d;
  cin >> v1 >> v2 >> t >> d;
  if (v1 > v2) swap(v1, v2);
  if (d == 0) {
    cout << t * v1 << endl;
  } else if (t == 2) {
    cout << v1 + v2 << endl;
  } else {
    memset(dp, -1, sizeof dp);
    cout << Solve(v1, v2, t - 2, d) + v1 + v2 << endl;
  }
  return 0;
}
