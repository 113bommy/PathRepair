#include <bits/stdc++.h>
using namespace std;
const int MAXN = 310;
int dp[MAXN][MAXN][MAXN];
int dp2[MAXN][MAXN][MAXN];
int a[MAXN][MAXN];
struct Node {
  int r1;
  int cost;
  Node(int _r1 = 0, int _cost = 0) {
    r1 = _r1;
    cost = _cost;
  }
};
struct classcomp {
  bool operator()(const Node &a, const Node &b) const {
    return a.cost < b.cost;
  }
};
int b[MAXN];
int main() {
  int n, m, t;
  int tp, tu, td;
  while (scanf("%d%d%d", &n, &m, &t) == 3) {
    scanf("%d%d%d", &tp, &tu, &td);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) dp[i][j][j] = dp2[i][j][j] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        for (int k = j + 1; k <= m; k++) {
          dp[i][j][k] = dp[i][j][k - 1];
          if (a[i][k] == a[i][k - 1])
            dp[i][j][k] += tp;
          else if (a[i][k] > a[i][k - 1])
            dp[i][j][k] += tu;
          else
            dp[i][j][k] += td;
        }
    for (int i = 1; i <= n; i++)
      for (int j = m - 1; j >= 1; j--)
        for (int k = j + 1; k <= m; k++) {
          dp2[i][j][k] = dp2[i][j + 1][k];
          if (a[i][j] == a[i][j + 1])
            dp2[i][j][k] += tp;
          else if (a[i][j] > a[i][j + 1])
            dp2[i][j][k] += tu;
          else
            dp2[i][j][k] += td;
        }
    long long ans = 100000000000000LL;
    int sx, sy;
    int ex, ey;
    for (int c1 = 1; c1 <= m; c1++)
      for (int c2 = c1 + 1; c2 <= m; c2++) {
        multiset<Node, classcomp> mt;
        multiset<Node, classcomp>::iterator it;
        int tmp = 0;
        int dis;
        if (c2 - c1 == 0)
          dis = 2;
        else if (c2 - c1 == 1)
          dis = 1;
        else
          dis = 0;
        dis = 1;
        b[1] = 0;
        for (int i = 2; i <= n; i++) {
          if (a[i][c1] == a[i - 1][c1])
            tmp += tp;
          else if (a[i][c1] > a[i - 1][c1])
            tmp += td;
          else
            tmp += tu;
          if (a[i][c2] == a[i - 1][c2])
            tmp += tp;
          else if (a[i][c2] > a[i - 1][c2])
            tmp += tu;
          else
            tmp += td;
          b[i] = tmp;
          if (i - dis >= 1) {
            mt.insert(Node(i - dis, dp[i - dis][c1][c2] - b[i - dis]));
          }
          if (!mt.empty()) {
            it = mt.lower_bound(Node(-1, t - dp2[i][c1][c2] - tmp));
            if (it != mt.end()) {
              int ttt = (*it).cost + dp2[i][c1][c2] + tmp - t;
              if (ttt < 0) ttt = -ttt;
              if (ttt < ans) {
                ans = ttt;
                sx = (*it).r1;
                sy = c1;
                ex = i;
                ey = c2;
              }
            }
            if (it != mt.begin()) {
              it--;
              int ttt = (*it).cost + dp2[i][c1][c2] + tmp - t;
              if (ttt < 0) ttt = -ttt;
              if (ttt < ans) {
                ans = ttt;
                sx = (*it).r1;
                sy = c1;
                ex = i;
                ey = c2;
              }
            }
          }
        }
      }
    printf("%d %d %d %d\n", sx, sy, ex, ey);
  }
  return 0;
}
