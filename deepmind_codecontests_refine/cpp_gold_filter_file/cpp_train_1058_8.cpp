#include <bits/stdc++.h>
using namespace std;
int n;
int a[128][128];
int dp[52][52][52][52];
int mincost(int x, int y, int w, int h) {
  if (w == 0 || h == 0 || x >= n || y >= n) return 0;
  if (dp[x][y][w][h] >= 0) return dp[x][y][w][h];
  vector<int> c(max(w, h) + 1);
  c.back() = 10000;
  int minc, maxc;
  int ci = 0, cl = 0, ans;
  if (w > h) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        c[j] += a[y + i][x + j];
      }
    }
    minc = 1;
    maxc = 0;
    for (int i = 0; i < w; ++i) {
      minc = min(minc, c[i]);
      maxc = max(maxc, c[i]);
    }
    if (minc > 0) {
      dp[x][y][w][h] = w;
      return w;
    }
    if (maxc == 0) {
      dp[x][y][w][h] = 0;
      return 0;
    }
    ci = 0;
    ans = w;
    while (ci < w) {
      if (c[ci] == 0) {
        cl = ci;
        while (c[ci + 1] == 0) ++ci;
        ans = min(ans,
                  mincost(x, y, cl, h) + mincost(x + ci + 1, y, w - ci - 1, h));
      }
      ci++;
    }
    dp[x][y][w][h] = ans;
    return ans;
  } else {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        c[i] += a[y + i][x + j];
      }
    }
    minc = 1;
    maxc = 0;
    for (int i = 0; i < h; ++i) {
      minc = min(minc, c[i]);
      maxc = max(maxc, c[i]);
    }
    if (minc > 0) {
      dp[x][y][w][h] = h;
      return h;
    }
    if (maxc == 0) {
      dp[x][y][w][h] = 0;
      return 0;
    }
    ans = h;
    for (ci = 0; ci < h; ++ci) {
      if (c[ci] == 0) {
        cl = ci;
        while (c[ci + 1] == 0) ci++;
        ans = min(ans,
                  mincost(x, y, w, cl) + mincost(x, y + ci + 1, w, h - ci - 1));
      }
    }
    dp[x][y][w][h] = ans;
    return ans;
  }
}
int solve() {
  memset(dp, 0xff, sizeof(dp));
  memset(a, 0, sizeof(a));
  scanf("%d", &n);
  assert(n >= 1 && n <= 50);
  for (int i = 0; i < n; ++i) {
    char s[128] = {};
    scanf("%s", s);
    for (int j = 0; j < n; ++j) {
      assert(s[j] == '#' || s[j] == '.');
      a[i][j] = s[j] == '#' ? 1 : 0;
    }
  }
  printf("%d\n", mincost(0, 0, n, n));
  return 0;
}
int main() {
  int Q = 1;
  while (Q--) solve();
  return 0;
}
