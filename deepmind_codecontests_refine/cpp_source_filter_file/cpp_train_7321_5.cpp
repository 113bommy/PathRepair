#include <bits/stdc++.h>
using namespace std;
class Point {
 public:
  int x, y, id;
  Point() {}
  Point(int _x, int _y, int _id) : x(_x), y(_y), id(_id) {}
  friend bool operator<(Point me, Point arg0) { return me.y > arg0.y; }
};
const int N = 100010;
Point a[N];
Point b[N];
Point pre[N][2][2];
long long dp[100010][2][2];
map<int, int> ma;
int match[N];
void get_ans(int n, int x, int y) {
  if (n > 1) get_ans(n - 1, pre[n][x][y].x, pre[n][x][y].y);
  match[n] = pre[n][x][y].id;
}
int main() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) dp[i][j][k] = -1 * (1LL << 60);
  dp[0][0][0] = 0;
  int n, m;
  scanf("%n", &n);
  for (int i = 1; i <= n; i++) {
    a[i].id = i;
    scanf("%n%n", &a[i].x, &a[i].y);
  }
  scanf("%n", &m);
  for (int i = 1; i <= m; i++) {
    b[i].id = i;
    scanf("%n%n", &b[i].x, &b[i].y);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) ma[a[i].y] = i;
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= m; i++) {
    if (i > 1 && b[i].y == b[i - 1].y) {
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++) {
          pre[i][j][k] = Point(j, k, 0);
          dp[i][j][k] = dp[i - 1][j][k];
        }
      if (ma.count(b[i].y)) {
        int id = ma[b[i].y];
        if (dp[i][0][1] < dp[i - 1][0][0] + a[id].x && a[id].x <= b[i].x) {
          dp[i][0][1] = dp[i - 1][0][0] + a[id].x;
          pre[i][0][1] = Point(0, 0, id);
        }
        if (dp[i][1][1] < dp[i - 1][1][0] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][1] = dp[i - 1][1][0] + a[id].x;
          pre[i][1][1] = Point(1, 0, id);
        }
      }
      if (ma.count(b[i].y + 1)) {
        int id = ma[b[i].y + 1];
        if (dp[i][1][0] < dp[i - 1][0][0] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][0] = dp[i - 1][0][0] + a[id].x;
          pre[i][1][0] = Point(0, 0, id);
        }
        if (dp[i][1][1] < dp[i - 1][0][1] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][1] = dp[i - 1][0][1] + a[id].x;
          pre[i][1][1] = Point(0, 1, id);
        }
      }
    } else if (i > 1 && b[i].y == b[i - 1].y - 1) {
      dp[i][0][0] = max(dp[i - 1][1][0], dp[i - 1][0][0]);
      if (dp[i][0][0] == dp[i - 1][1][0])
        pre[i][0][0] = Point(1, 0, 0);
      else
        pre[i][0][0] = Point(0, 0, 0);
      dp[i][1][0] = max(dp[i - 1][1][1], dp[i - 1][0][1]);
      if (dp[i][1][0] == dp[i - 1][1][1])
        pre[i][1][0] = Point(1, 1, 0);
      else
        pre[i][1][0] = Point(0, 1, 0);
      if (ma.count(b[i].y)) {
        int id = ma[b[i].y];
        if (dp[i][0][1] < dp[i - 1][1][0] + a[id].x && a[id].x <= b[i].x) {
          dp[i][0][1] = dp[i - 1][1][0] + a[id].x;
          pre[i][0][1] = Point(1, 0, id);
        }
        if (dp[i][0][1] < dp[i - 1][0][0] + a[id].x && a[id].x <= b[i].x) {
          dp[i][0][1] = dp[i - 1][0][0] + a[id].x;
          pre[i][0][1] = Point(0, 0, id);
        }
        if (dp[i][1][1] < dp[i - 1][1][1] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][1] = dp[i - 1][1][1] + a[id].x;
          pre[i][1][1] = Point(1, 1, id);
        }
        if (dp[i][1][1] < dp[i - 1][0][1] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][1] = dp[i - 1][0][1] + a[id].x;
          pre[i][1][1] = Point(0, 1, id);
        }
      }
      if (ma.count(b[i].y + 1)) {
        int id = ma.at(b[i].y + 1);
        if (dp[i][1][0] < dp[i - 1][0][0] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][0] = dp[i - 1][0][0] + a[id].x;
          pre[i][1][0] = Point(0, 0, id);
        }
        if (dp[i][1][0] < dp[i - 1][1][0] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][0] = dp[i - 1][1][0] + a[id].x;
          pre[i][1][0] = Point(1, 0, id);
        }
      }
    } else {
      dp[i][0][0] = max(max(dp[i - 1][0][0], dp[i - 1][0][1]),
                        max(dp[i - 1][1][0], dp[i - 1][1][1]));
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
          if (dp[i][0][0] == dp[i - 1][j][k]) pre[i][0][0] = Point(j, k, 0);
      if (ma.count(b[i].y)) {
        int id = ma.at(b[i].y);
        int x = pre[i][0][0].x, y = pre[i][0][0].y;
        if (dp[i][0][1] < dp[i - 1][x][y] + a[id].x && a[id].x <= b[i].x) {
          dp[i][0][1] = dp[i - 1][x][y] + a[id].x;
          pre[i][0][1] = Point(x, y, id);
        }
      }
      if (ma.count(b[i].y + 1)) {
        int id = ma.at(b[i].y + 1);
        int x = pre[i][0][0].x, y = pre[i][0][0].y;
        if (dp[i][1][0] < dp[i - 1][x][y] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][0] = dp[i - 1][x][y] + a[id].x;
          pre[i][1][0] = Point(x, y, id);
        }
      }
    }
  }
  long long maxn = -1 * (1LL << 60);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) maxn = max(maxn, dp[m][i][j]);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (maxn == dp[m][i][j]) {
        get_ans(m, i, j);
        cout << maxn << endl;
        int total = 0;
        for (int k = 1; k <= m; k++)
          if (match[k] != 0) total++;
        printf("%d\n", total);
        for (int k = 1; k <= m; k++)
          if (match[k] != 0) {
            printf("%d %d\n", b[k].id, a[match[k]].id);
          }
        return 0;
      }
    }
  }
  return 0;
}
