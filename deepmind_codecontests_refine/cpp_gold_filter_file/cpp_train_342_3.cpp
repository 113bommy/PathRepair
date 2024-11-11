#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, k, mask;
int a[N][N], dp[130][N][N];
int pre[130][N][N];
pair<int, int> p[10];
bool vis[N][N];
void print(pair<int, int> v, int s) {
  int x = v.first, y = v.second;
  vis[x][y] = 1;
  if (pre[s][x][y] > 0) {
    print(v, pre[s][x][y]);
    print(v, s ^ pre[s][x][y]);
  } else if (pre[s][x][y] < 0) {
    int p = -pre[s][x][y];
    if (p == 1) {
      print(make_pair(x - 1, y), s);
    } else if (p == 2) {
      print(make_pair(x, y - 1), s);
    } else if (p == 3) {
      print(make_pair(x + 1, y), s);
    } else
      print(make_pair(x, y + 1), s);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i < 130; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++) dp[i][j][k] = 1e6;
  for (int i = 1; i <= k; i++) {
    scanf("%d%d", &p[i].first, &p[i].second);
    dp[(1 << (i - 1))][p[i].first][p[i].second] = a[p[i].first][p[i].second];
    pre[(1 << (i - 1))][p[i].first][p[i].second] = 0;
  }
  mask = (1 << k) - 1;
  for (int s = 1; s <= mask; s++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        for (int p = (s - 1) & s; p > 0; p = (p - 1) & s) {
          if (dp[s][i][j] > dp[p][i][j] + dp[p ^ s][i][j] - a[i][j]) {
            dp[s][i][j] = dp[p][i][j] + dp[p ^ s][i][j] - a[i][j];
            pre[s][i][j] = p;
          }
        }
      }
    }
    bool done = 0;
    while (!done) {
      done = 1;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          int cur;
          if (dp[s][i - 1][j] + a[i][j] < dp[s][i][j]) {
            dp[s][i][j] = dp[s][i - 1][j] + a[i][j];
            pre[s][i][j] = -1;
            done = 0;
          }
          if (dp[s][i][j - 1] + a[i][j] < dp[s][i][j]) {
            dp[s][i][j] = dp[s][i][j - 1] + a[i][j];
            pre[s][i][j] = -2;
            done = 0;
          }
          if (dp[s][i + 1][j] + a[i][j] < dp[s][i][j]) {
            dp[s][i][j] = dp[s][i + 1][j] + a[i][j];
            pre[s][i][j] = -3;
            done = 0;
          }
          if (dp[s][i][j + 1] + a[i][j] < dp[s][i][j]) {
            dp[s][i][j] = dp[s][i][j + 1] + a[i][j];
            pre[s][i][j] = -4;
            done = 0;
          }
        }
      }
    }
  }
  int cur = INT_MAX;
  pair<int, int> ver;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dp[mask][i][j] < cur) {
        ver = make_pair(i, j);
        cur = dp[mask][i][j];
      }
    }
  }
  printf("%d\n", cur);
  print(ver, mask);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%c", ".X"[vis[i][j]]);
    }
    printf("\n");
  }
}
