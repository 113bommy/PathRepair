#include <bits/stdc++.h>
using namespace std;
int v1, v2, d;
int dp[1000][1000];
int dist(int t, int v) {
  int i, a1, a2, m = -1;
  if (t == 1) {
    if (v == v1)
      return v1;
    else
      return -1;
  }
  if (dp[t][v] != 0) return dp[t][v];
  for (i = 0; i <= d; i++) {
    if (i == 0) {
      m = max(m, dist(t - 1, v));
    } else {
      a1 = dist(t - 1, v - i);
      a2 = dist(t - 1, v + i);
      m = max(m, max(a1, a2));
    }
  }
  dp[t][v] = m != -1 ? m + v : m;
  return dp[t][v];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  memset(dp, 0, sizeof(dp));
  cin >> v1 >> v2 >> t >> d;
  cout << dist(t, v2);
  cout << endl;
  return 0;
}
