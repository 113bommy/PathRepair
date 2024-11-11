#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!(ch >= '0' && ch <= '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * f;
}
const int N = 1005;
const double Pi = 3.1415926535897932384626;
const double eps = 1e-12;
const double INF = 1e16;
inline int dcmp(double x) {
  if (fabs(x) <= eps) return 0;
  return (x > eps) ? 1 : -1;
}
int n;
int fa[N];
vector<int> e[N];
struct Circle {
  int x, y, r;
  double s;
} c[N];
inline bool cmp(const Circle &c1, const Circle &c2) { return c1.r > c2.r; }
inline bool inC(int a, int b) {
  double dis = (c[a].x - c[b].x) * (c[a].x - c[b].x) +
               (c[a].y - c[b].y) * (c[a].y - c[b].y);
  double tmp = (c[b].r - c[a].r) * (c[b].r - c[a].r);
  if (dcmp(tmp - dis) >= 0) return true;
  return false;
}
double ans = 0;
double dp[N][2][2];
void DP(int x) {
  for (int i = 0; i <= 1; i++) dp[x][0][i] = -c[x].s;
  for (int i = 0; i <= 1; i++) dp[x][1][i] = c[x].s;
  for (int i = 0; i < (int)e[x].size(); i++) {
    int v = e[x][i];
    DP(v);
    for (int j = 0; j <= 1; j++)
      for (int k = 0; k <= 1; k++)
        dp[x][j][k] += max(dp[v][j ^ 1][k], dp[v][k][j ^ 1]);
  }
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    c[i].x = read(), c[i].y = read(), c[i].r = read();
    c[i].s = Pi * c[i].r * c[i].r;
  }
  sort(c + 1, c + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    fa[i] = 0;
    for (int j = i - 1; j >= 1; j--)
      if (inC(i, j)) {
        fa[i] = j;
        break;
      }
    e[fa[i]].push_back(i);
  }
  c[0].s = 0;
  DP(0);
  printf("%.9lf\n", dp[0][0][1]);
  return 0;
}
