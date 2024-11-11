#include <bits/stdc++.h>
using namespace std;
int n, t;
int dp[21][5][11][11][2];
int solve(int pos, int h, int mn, int mx, bool w) {
  if (mn > t - 1 || mx > t) return 0;
  if (pos == n) return mx == t && mn == t - 1;
  int &ref = dp[pos][h][mn][mx][w];
  if (ref != -1) return ref;
  ref = 0;
  for (int i = 1; i < 5; ++i) {
    if (i == h) continue;
    bool wp = i > h;
    if (!pos)
      ref += solve(pos + 1, i, mn, mx, w);
    else if (pos == 1)
      ref += solve(pos + 1, i, mn, mx, wp);
    else
      ref += solve(pos + 1, i, mn + (!w & wp), mx + (w & !wp), wp);
  }
  return ref;
}
int main() {
  scanf("%d %d", &n, &t);
  memset(dp, -1, sizeof(dp));
  int sol = solve(0, 0, 0, 0, 0);
  printf("%d\n", sol);
  return 0;
}
