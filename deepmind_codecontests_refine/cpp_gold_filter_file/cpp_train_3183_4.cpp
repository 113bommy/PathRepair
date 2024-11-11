#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
const int M = (1 << 8);
int dp[N][M];
int n;
int g[N], cur[8];
vector<int> v[8];
int ok(int m) {
  memset((cur), (0), sizeof(cur));
  memset((dp), (-1), sizeof(dp));
  dp[0][0] = 0;
  for (int i = (int)0; i < (int)n; ++i) {
    for (int j = (int)0; j < (int)M; ++j)
      if (dp[i][j] != -1) {
        for (int k = (int)0; k < (int)8; ++k)
          if (!((1 << k) & j)) {
            int x = m + cur[k] - 1, y, z;
            if (x >= ((int)(v[k]).size())) continue;
            y = v[k][x];
            z = j | (1 << k);
            dp[y][z] = max(dp[y][z], dp[i][j]);
            if (++x >= ((int)(v[k]).size())) continue;
            y = v[k][x];
            dp[y][z] = max(dp[y][z], dp[i][j] + 1);
          }
      }
    ++cur[g[i]];
  }
  int x = -1;
  for (int i = (int)0; i < (int)n; ++i) x = max(x, dp[i][M - 1]);
  return x == -1 ? x : m * 8 + x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = (int)0; i < (int)n; ++i) {
    cin >> g[i];
    v[--g[i]].push_back(i);
  }
  int l = 1, r = (n >> 3) + 1, m;
  int res = 0, x;
  while (l + 1 <= r) {
    m = (l + r) >> 1;
    if ((x = ok(m)) != -1) {
      l = m + 1;
      res = max(res, x);
    } else
      r = m;
  }
  if (res == 0)
    for (int i = (int)0; i < (int)8; ++i)
      if (!v[i].empty()) ++res;
  cout << res;
  return 0;
}
