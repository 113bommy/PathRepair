#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 60;
struct date {
  long long x, st;
  bool operator<(const date &r) const { return x < r.x; }
} a[maxn];
long long bag[maxn];
long long dp[maxn][2][2];
long long mi[maxn];
struct node {
  int st, x1, x2;
} path[maxn][2][2];
int vis[maxn];
int idx[maxn];
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i].x);
    a[i].st = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        path[i][j][k] = {-1, -1, -1};
      }
    }
  }
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    bag[++cnt] = a[i].x - a[i - 1].x;
  }
  for (int i = 3; i <= n; i++) {
    if (n - i >= 3) {
      dp[i][1][0] = dp[i - 1][0][0] + bag[i];
      path[i][1][0] = node{i - 1, 0, 0};
    }
    if (dp[i - 2][0][0] < dp[i - 2][0][1]) {
      if (dp[i - 2][1][0] > dp[i - 2][0][1]) {
        path[i][0][0].st = i - 2, path[i][0][0].x1 = 1, path[i][0][0].x2 = 0;
      } else {
        path[i][0][0].st = i - 2, path[i][0][0].x1 = 0, path[i][0][0].x2 = 1;
      }
    } else {
      if (dp[i - 2][1][0] > dp[i - 2][0][0]) {
        path[i][0][0].st = i - 2, path[i][0][0].x1 = 1, path[i][0][0].x2 = 0;
      } else {
        path[i][0][0].st = i - 2, path[i][0][0].x1 = 0, path[i][0][0].x2 = 0;
      }
    }
    dp[i][0][0] = max(dp[i - 2][1][0], max(dp[i - 2][0][0], dp[i - 2][0][1]));
    if (i > 3 && (n - (i - 1) >= 3)) {
      dp[i][0][1] = dp[i - 2][0][0] + bag[i - 1];
      path[i][0][1] = {i - 2, 0, 0};
    }
  }
  long long res = max(dp[n][0][0], max(dp[n][0][1], dp[n][1][0]));
  int st, x1, x2;
  if (dp[n][0][0] > dp[n][0][1]) {
    st = n, x1 = 0, x2 = 0;
  } else {
    st = n, x1 = 0, x2 = 1;
  }
  if (dp[st][x1][x2] < dp[n][1][0]) {
    x1 = 1, x2 = 0;
  }
  while (path[st][x1][x2].st != -1) {
    if (x1 == 1) {
      vis[st] = 1;
    }
    if (x2 == 1) {
      vis[st - 1] = 1;
    }
    int sst = path[st][x1][x2].st, xx1 = path[st][x1][x2].x1,
        xx2 = path[st][x1][x2].x2;
    st = sst, x1 = xx1, x2 = xx2;
  }
  int id = 1;
  for (int i = 1; i <= n; i++) {
    idx[a[i].st] = id;
    if (vis[i]) id++;
  }
  printf("%I64d\n", a[n].x - a[1].x - res);
  for (int i = 1; i <= n; i++) {
    printf("%d ", idx[i]);
  }
  printf("\n");
  return 0;
}
