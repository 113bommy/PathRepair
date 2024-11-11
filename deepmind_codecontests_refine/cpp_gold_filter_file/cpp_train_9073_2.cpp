#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const double pi = acos(-1.0);
const double inf = 1e12;
const double eps = 1e-9;
struct node {
  double l, r;
  bool operator<(node a) const { return r < a.r; }
  node operator+(double a) { return (node){l + a, r + a}; }
} dt[maxn];
int f[maxn][20], n, m;
double ang[maxn], X[maxn], Y[maxn], dis[maxn];
int tag;
bool check(double mid) {
  for (int i = 1; i <= n; i++) {
    double t = acos(mid / dis[i]);
    dt[i] = (node){ang[i] - t, ang[i] + t};
    if (dt[i].r > pi) dt[i] = dt[i] + (-2 * pi);
  }
  sort(dt + 1, dt + n + 1);
  for (int i = 1; i <= n; i++) dt[i + n] = dt[i] + 2 * pi;
  int N = 2 * n;
  for (int i = 1; i <= N; i++) {
    int cur = min(N, max(f[i - 1][0], i + 1));
    while (cur < min(N, i + n) && dt[cur].l <= dt[i].r) cur++;
    f[i][0] = cur;
    if (tag) cout << i << " " << f[i][0] << endl;
  }
  if (tag)
    for (int i = 1; i <= N; i++)
      cout << i << " " << dt[i].l << " " << dt[i].r << endl;
  for (int j = 1; j < 20; j++)
    for (int i = 1; i <= N; i++) {
      f[i][j] = f[f[i][j - 1]][j - 1];
    }
  for (int i = 1; i <= n; i++) {
    int cur = 0, id = i;
    for (int j = 19; j >= 0; j--) {
      if (f[id][j] < i + n) {
        cur += 1 << j;
        id = f[id][j];
      }
    }
    cur++;
    if (tag) cout << i << " " << cur << endl;
    if (cur <= m) return 1;
  }
  return 0;
}
int main() {
  scanf("%d %d", &n, &m);
  cout << setprecision(10);
  double l = 0, r = inf;
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    X[i] = x, Y[i] = y;
    dis[i] = sqrt(X[i] * X[i] + Y[i] * Y[i]), r = min(r, dis[i]),
    ang[i] = atan2(Y[i], X[i]);
  }
  while ((r - l) > eps) {
    double mid = (l + r) / 2;
    if (!check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r << endl;
}
