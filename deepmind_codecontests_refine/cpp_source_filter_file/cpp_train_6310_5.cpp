#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
struct point {
  int x, y;
  double k;
  point(int x = 0, int y = 0) : x(x), y(y) { k = atan2(y, x); }
  point operator-(const point &A) const { return point(x - A.x, y - A.y); }
  long long operator%(const point &A) const {
    return 1ll * x * A.y - 1ll * y * A.x;
  }
  bool operator<(const point &A) const { return k < A.k; }
} a[N], p[N];
int n, m, tt;
long long f[N][N][55], mx[55], ans = 0;
queue<int> q[N];
vector<int> E[N], G[N];
void add(int x, int y) {
  while (!q[x].empty() && (p[q[x].front()] - p[x]) % (p[y] - p[x]) < 0)
    add(q[x].front(), y), q[x].pop();
  G[x].push_back(y), E[y].push_back(x), q[y].push(x);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) a[i].x = gi(), a[i].y = gi();
  for (int s = 1; s <= n; s++) {
    tt = 0;
    for (int i = 1; i <= n; i++)
      if (a[i].x > a[s].x || (a[i].x == a[s].x && a[i].y > a[s].y))
        p[++tt] = a[i] - a[s];
    sort(p + 1, p + tt + 1);
    for (int i = 1; i <= tt; i++) {
      E[i].clear(), G[i].clear();
      while (!q[i].empty()) q[i].pop();
    }
    for (int i = 1; i < tt; i++) add(i, i + 1);
    memset(f, 0, sizeof(f));
    for (int i = tt; i; i--) {
      memset(mx, 0, sizeof(mx));
      reverse(E[i].begin(), E[i].end());
      int cur = G[i].size() - 1;
      for (auto j : E[i]) {
        f[i][j][1] = p[j] % p[i];
        while (~cur && (p[j] - p[i]) % (p[G[i][cur]] - p[i]) < 0) {
          for (int k = 1; k < m; k++) mx[k] = max(mx[k], f[G[i][cur]][i][k]);
          --cur;
        }
        for (int k = 1; k < m; k++) f[i][j][k + 1] = mx[k] + p[j] % p[i];
      }
    }
    for (int i = 1; i <= tt; i++)
      for (auto j : E[i]) ans = max(ans, f[i][j][m - 2]);
  }
  printf("%.2lf\n", 1.0 * ans / 2);
  return 0;
}
