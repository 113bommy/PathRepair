#include <bits/stdc++.h>
using namespace std;
int dp[5][5][210][210];
vector<pair<int, int> > out[5][5][210][210];
void Init() {
  dp[0][0][0][0] = 1;
  for (int sum = 0; sum <= 5; ++sum) {
    for (int l = 0; l <= sum; ++l) {
      for (int i = 0; i <= 200; ++i) {
        for (int j = 0; j <= 200; ++j) {
          int r = sum - l;
          if (!dp[l][r][i][j]) continue;
          if (max(l, r) > 3) continue;
          int limit = 25;
          if (sum == 5) limit = 15;
          for (int tmp = limit; tmp <= 200; ++tmp) {
            if (i + tmp <= 200 && j + tmp - 2 <= 200 &&
                !dp[l + 1][r][i + tmp][j + tmp - 2]) {
              dp[l + 1][r][i + tmp][j + tmp - 2] = 1;
              out[l + 1][r][i + tmp][j + tmp - 2] = out[l][r][i][j];
              out[l + 1][r][i + tmp][j + tmp - 2].push_back(
                  make_pair(tmp, tmp - 2));
            }
            if (i + tmp - 2 <= 200 && j + tmp <= 200 &&
                !dp[l][r + 1][i + tmp - 2][j + tmp]) {
              dp[l][r + 1][i + tmp - 2][j + tmp] = 1;
              out[l][r + 1][i + tmp - 2][j + tmp] = out[l][r][i][j];
              out[l][r + 1][i + tmp - 2][j + tmp].push_back(
                  make_pair(tmp - 2, tmp));
            }
          }
          for (int tmp = 0; tmp <= limit - 2; ++tmp) {
            if (i + limit <= 200 && j + tmp <= 200 &&
                !dp[l + 1][r][i + limit][j + tmp]) {
              dp[l + 1][r][i + limit][j + tmp] = 1;
              out[l + 1][r][i + limit][j + tmp] = out[l][r][i][j];
              out[l + 1][r][i + limit][j + tmp].push_back(
                  make_pair(limit, tmp));
            }
            if (i + tmp <= 200 && j + limit <= 200 &&
                !dp[l][r + 1][i + tmp][j + limit]) {
              dp[l][r + 1][i + tmp][j + limit] = 1;
              out[l][r + 1][i + tmp][j + limit] = out[l][r][i][j];
              out[l][r + 1][i + tmp][j + limit].push_back(
                  make_pair(tmp, limit));
            }
          }
        }
      }
    }
  }
}
int a, b;
int main() {
  Init();
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &a, &b);
    int l = -1, r = -1;
    if (dp[3][0][a][b]) {
      l = 3;
      r = 0;
    } else if (dp[3][1][a][b]) {
      l = 3;
      r = 1;
    } else if (dp[3][2][a][b]) {
      l = 3;
      r = 2;
    } else if (dp[2][3][a][b]) {
      l = 2;
      r = 3;
    } else if (dp[1][3][a][b]) {
      l = 1;
      r = 3;
    } else if (dp[0][3][a][b]) {
      l = 0;
      r = 3;
    }
    if (l == -1 && r == -1) {
      puts("Impossible");
    } else {
      printf("%d:%d\n", l, r);
      int len = out[l][r][a][b].size();
      for (int i = 0; i < len; ++i)
        printf("%d:%d%c", out[l][r][a][b][i].first, out[l][r][a][b][i].second,
               " \n"[i == len - 1]);
    }
  }
  return 0;
}
