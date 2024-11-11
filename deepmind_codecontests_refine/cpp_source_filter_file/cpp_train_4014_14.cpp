#include <bits/stdc++.h>
using namespace std;
int dp[2][1005][1005][2][2];
int n, px, py, dx, dy, d, h;
pair<int, int> ar[22];
int pyt(int a, int b) {
  dx = a - px;
  dy = b - py;
  return dx * dx + dy * dy;
}
int rek(int g, int lx, int ly, int pu1, int pu2) {
  if (pyt(lx, ly) > d) {
    return 1;
  } else if (dp[g][lx][ly][pu1][pu2] != -1) {
    return dp[g][lx][ly][pu1][pu2];
  } else if (g == 1) {
    int ret = 0;
    if (pu1) {
      if (rek(0, ly, lx, 0, pu2) == 0) {
        ret = 1;
      }
    }
    if (ret == 0) {
      for (int i = 0; i < n; i++) {
        if (rek(0, lx + ar[i].first, ly + ar[i].second, pu1, pu2) == 0) {
          ret = 1;
          break;
        }
      }
    }
    dp[g][lx][ly][pu1][pu2] = ret;
    return ret;
  } else {
    int ret = 0;
    if (pu2) {
      if (rek(1, ly, lx, pu1, 0) == 0) {
        ret = 1;
      }
    }
    if (ret == 0) {
      for (int i = 0; i < n; i++) {
        if (rek(1, lx + ar[i].first, ly + ar[i].second, pu1, pu2) == 0) {
          ret = 1;
          break;
        }
      }
    }
    dp[g][lx][ly][pu1][pu2] = ret;
    return ret;
  }
}
int main() {
  scanf("%d%d%d%d\n", &px, &py, &n, &d);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &ar[i].first, &ar[i].second);
  }
  px += 201;
  py += 201;
  d *= d;
  memset(dp, -1, sizeof dp);
  h = rek(1, px, py, 1, 1);
  if (h == 1) {
    printf("Anton\n");
  } else {
    printf("Dasha\n");
  }
  return 0;
}
