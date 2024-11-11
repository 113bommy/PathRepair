#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
using ll = long long;
struct Point {
  int x, y;
};
inline Point operator+(const Point &a, const Point &b) {
  return {a.x + b.x, a.y + b.y};
}
inline Point operator-(const Point &a, const Point &b) {
  return {a.x - b.x, a.y - b.y};
}
inline ll cross(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}
inline ll dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
const int N = 205;
int n, m;
Point a[N], p[N];
queue<int> q[N];
vector<int> v[N], g[N];
void add(int x, int y) {
  while (!q[x].empty() && cross(p[q[x].front()] - p[x], p[y] - p[x]) < 0)
    add(q[x].front(), y), q[x].pop();
  g[x].push_back(y);
  v[y].push_back(x);
  q[y].push(x);
}
ll dp[N][N][55], mx[55];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
  ll ans = 0;
  for (int s = 1; s <= n; s++) {
    int idx = 0;
    for (int i = 1; i <= n; i++)
      if (a[i].x > a[s].x || (a[i].x == a[s].x && a[i].y > a[s].y))
        p[++idx] = a[i] - a[s];
    sort(p + 1, p + idx + 1, [](const Point &a, const Point &b) {
      return atan2(a.y, a.x) < atan2(b.y, b.x);
    });
    for (int i = 1; i <= idx; i++) {
      v[i].clear();
      g[i].clear();
      while (!q[i].empty()) q[i].pop();
    }
    for (int i = 1; i < idx; i++) add(i, i + 1);
    memset(dp, 191, sizeof(dp));
    for (int i = idx; i > 0; --i) {
      memset(mx, 191, sizeof(mx));
      reverse(v[i].begin(), v[i].end());
      int cur = g[i].size() - 1;
      for (auto &j : v[i]) {
        dp[i][j][1] = cross(p[j], p[i]);
        while (cur >= 0 && cross(p[j] - p[i], p[g[i][cur]] - p[i]) < 0) {
          for (int k = 1; k < m; k++) mx[k] = max(mx[k], dp[g[i][cur]][i][k]);
          --cur;
        }
        for (int k = 1; k < m; k++) dp[i][j][k + 1] = mx[k] + cross(p[j], p[i]);
      }
    }
    for (int i = 1; i <= idx; i++)
      for (auto &j : v[i]) ans = max(ans, dp[i][j][m - 2]);
  }
  cout << ans / 2 << (ans % 2 ? ".5" : "") << endl;
  return 0;
}
