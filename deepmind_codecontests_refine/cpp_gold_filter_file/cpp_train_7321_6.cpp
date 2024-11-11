#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;
const int N = 100010;
struct point {
  int x, y, id;
  void read(int _id) {
    id = _id;
    scanf("%d%d", &x, &y);
  }
  point() {}
  point(int x, int y, int id) : x(x), y(y), id(id) {}
  friend bool operator<(const point &p, const point &q) { return p.y > q.y; }
} a[N], b[N], pre[N][2][2];
long long dp[N][2][2];
map<int, int> ma;
int match[N];
void get_ans(int n, int x, int y) {
  if (n > 1) get_ans(n - 1, pre[n][x][y].x, pre[n][x][y].y);
  match[n] = pre[n][x][y].id;
}
int main() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) dp[i][j][k] = -oo;
  dp[0][0][0] = 0;
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) a[i].read(i);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) b[i].read(i);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) ma[a[i].y] = i;
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= m; i++) {
    if (i > 1 && b[i].y == b[i - 1].y) {
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++) {
          pre[i][j][k] = point(j, k, 0);
          dp[i][j][k] = dp[i - 1][j][k];
        }
      if (ma.count(b[i].y)) {
        int id = ma[b[i].y];
        if (dp[i][0][1] < dp[i - 1][0][0] + a[id].x && a[id].x <= b[i].x) {
          dp[i][0][1] = dp[i - 1][0][0] + a[id].x;
          pre[i][0][1] = point(0, 0, id);
        }
        if (dp[i][1][1] < dp[i - 1][1][0] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][1] = dp[i - 1][1][0] + a[id].x;
          pre[i][1][1] = point(1, 0, id);
        }
      }
      if (ma.count(b[i].y + 1)) {
        int id = ma[b[i].y + 1];
        if (dp[i][1][0] < dp[i - 1][0][0] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][0] = dp[i - 1][0][0] + a[id].x;
          pre[i][1][0] = point(0, 0, id);
        }
        if (dp[i][1][1] < dp[i - 1][0][1] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][1] = dp[i - 1][0][1] + a[id].x;
          pre[i][1][1] = point(0, 1, id);
        }
      }
    } else if (i > 1 && b[i].y == b[i - 1].y - 1) {
      dp[i][0][0] = max(dp[i - 1][1][0], dp[i - 1][0][0]);
      if (dp[i][0][0] == dp[i - 1][1][0])
        pre[i][0][0] = point(1, 0, 0);
      else
        pre[i][0][0] = point(0, 0, 0);
      dp[i][1][0] = max(dp[i - 1][1][1], dp[i - 1][0][1]);
      if (dp[i][1][0] == dp[i - 1][1][1])
        pre[i][1][0] = point(1, 1, 0);
      else
        pre[i][1][0] = point(0, 1, 0);
      if (ma.count(b[i].y)) {
        int id = ma[b[i].y];
        if (dp[i][0][1] < dp[i - 1][1][0] + a[id].x && a[id].x <= b[i].x) {
          dp[i][0][1] = dp[i - 1][1][0] + a[id].x;
          pre[i][0][1] = point(1, 0, id);
        }
        if (dp[i][0][1] < dp[i - 1][0][0] + a[id].x && a[id].x <= b[i].x) {
          dp[i][0][1] = dp[i - 1][0][0] + a[id].x;
          pre[i][0][1] = point(0, 0, id);
        }
        if (dp[i][1][1] < dp[i - 1][1][1] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][1] = dp[i - 1][1][1] + a[id].x;
          pre[i][1][1] = point(1, 1, id);
        }
        if (dp[i][1][1] < dp[i - 1][0][1] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][1] = dp[i - 1][0][1] + a[id].x;
          pre[i][1][1] = point(0, 1, id);
        }
      }
      if (ma.count(b[i].y + 1)) {
        int id = ma[b[i].y + 1];
        if (dp[i][1][0] < dp[i - 1][0][0] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][0] = dp[i - 1][0][0] + a[id].x;
          pre[i][1][0] = point(0, 0, id);
        }
        if (dp[i][1][0] < dp[i - 1][1][0] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][0] = dp[i - 1][1][0] + a[id].x;
          pre[i][1][0] = point(1, 0, id);
        }
      }
    } else {
      dp[i][0][0] = max(max(dp[i - 1][0][0], dp[i - 1][0][1]),
                        max(dp[i - 1][1][0], dp[i - 1][1][1]));
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
          if (dp[i][0][0] == dp[i - 1][j][k]) pre[i][0][0] = point(j, k, 0);
      if (ma.count(b[i].y)) {
        int id = ma[b[i].y];
        int x = pre[i][0][0].x, y = pre[i][0][0].y;
        if (dp[i][0][1] < dp[i - 1][x][y] + a[id].x && a[id].x <= b[i].x) {
          dp[i][0][1] = dp[i - 1][x][y] + a[id].x;
          pre[i][0][1] = point(x, y, id);
        }
      }
      if (ma.count(b[i].y + 1)) {
        int id = ma[b[i].y + 1];
        int x = pre[i][0][0].x, y = pre[i][0][0].y;
        if (dp[i][1][0] < dp[i - 1][x][y] + a[id].x && a[id].x <= b[i].x) {
          dp[i][1][0] = dp[i - 1][x][y] + a[id].x;
          pre[i][1][0] = point(x, y, id);
        }
      }
    }
  }
  long long maxn = -oo;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) maxn = max(maxn, dp[m][i][j]);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      if (maxn == dp[m][i][j]) {
        get_ans(m, i, j);
        cout << maxn << endl;
        int tot = 0;
        for (int k = 1; k <= m; k++)
          if (match[k]) tot++;
        cout << tot << endl;
        for (int k = 1; k <= m; k++)
          if (match[k]) printf("%d %d\n", b[k].id, a[match[k]].id);
        return 0;
      }
  return 0;
}
