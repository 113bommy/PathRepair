#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000;
const long double pi = acos(-1);
int n, m, dis[maxn + 5][maxn + 5];
struct Point {
  int x, y;
  long double ang;
} a[maxn + 5], p[maxn + 5];
long long ans;
inline bool operator<(const Point &a, const Point &b) { return a.ang < b.ang; }
inline Point operator-(const Point &a, const Point &b) {
  return (Point){a.x - b.x, a.y - b.y};
}
inline long long Cross(const Point &a, const Point &b) {
  return (long long)a.x * b.y - (long long)a.y * b.x;
}
inline long long Count(int A, int B) {
  int L = dis[A][B], R = n - 2 - L;
  return (long long)L * (L - 1) / 2 * R * (R - 1) / 2;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
  m = n - 1;
  for (int i = 1; i <= m; i++)
    for (int j = i; ((j) < m ? (j) + 1 : 1) != i; j = ((j) < m ? (j) + 1 : 1))
      dis[i][((j) < m ? (j) + 1 : 1)] = dis[i][j] + 1;
  for (int i = (m = 0, 1); i <= n; i++, m = 0) {
    for (int j = 1; j <= n; j++)
      if (i ^ j) {
        p[++m] = a[j];
        p[m].ang = atan2(a[j].y - a[i].y, a[j].x - a[i].x);
        if (p[m].ang < 0) p[m].ang += pi * 2;
      }
    sort(p + 1, p + 1 + m);
    int pos = 1;
    for (int j = 2; j <= m; j++)
      if (Cross(p[1] - a[i], p[j] - a[i]) > 0) pos = j;
    ans += Count(1, pos);
    for (int j = 2; j <= m; j++) {
      while (Cross(p[j] - a[i], p[((pos) < m ? (pos) + 1 : 1)] - a[i]) > 0)
        pos = ((pos) < m ? (pos) + 1 : 1);
      ans += Count(j, pos);
    }
  }
  return printf("%lld\n", ans >> 1), 0;
}
