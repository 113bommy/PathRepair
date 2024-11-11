#include <bits/stdc++.h>
using namespace std;
using INT = long long;
using DO = double;
int n, l;
DO dp[1110], prv[1110];
DO dst[1110][1110];
int x[1110], b[1110];
int solve(DO md) {
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    DO mx = -1e9;
    for (int j = 0; j < i; j++) {
      if (dp[j] - dst[j][i] > mx) {
        mx = dp[j] - dst[j][i];
        prv[i] = j;
      }
    }
    dp[i] = mx + b[i] * md;
  }
  if (dp[n] > -1e-8) return 1;
  return 0;
}
int main() {
  cin >> n >> l;
  for (int i = 1; i <= n; i++) scanf("%d %d", x + i, b + i);
  for (int i = 0; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      dst[i][j] = sqrt(abs(x[j] - x[i] - l));
    }
  DO st = 0, ed = 2000;
  int step = 25;
  while (step--) {
    DO md = (st + ed) / 2;
    if (solve(md))
      ed = md;
    else
      st = md;
  }
  vector<int> ans;
  int pos = n;
  while (pos) {
    ans.push_back(pos);
    pos = prv[pos];
  }
  reverse(ans.begin(), ans.end());
  for (int u : ans) printf("%d ", u);
  return 0;
}
