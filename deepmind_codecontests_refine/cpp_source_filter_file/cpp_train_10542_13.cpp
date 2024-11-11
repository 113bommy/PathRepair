#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  bool operator<(const point &o) const { return x < o.x; }
} p1[501], p2[501];
int s[501][501], t[501];
bool cross(point a, point b, point c, point d) {
  return (long long)(b.x - a.x) * (d.y - c.y) -
             (long long)(b.y - a.y) * (d.x - c.x) >
         0;
}
int main() {
  int n, m, i, j, k, ans = 0;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d%d", &p1[i].x, &p1[i].y);
  for (i = 1; i <= m; i++) scanf("%d%d", &p2[i].x, &p2[i].y);
  sort(p1 + 1, p1 + n + 1);
  memset(s, 0, sizeof(s));
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++)
      for (k = 1; k <= m; k++)
        if (p1[i].x <= p2[k].x && p2[k].x <= p1[j].x)
          if (cross(p1[i], p1[j], p1[i], p2[k])) s[i][j]++;
  memset(t, 0, sizeof(t));
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (p1[i].x == p2[i].x && p1[i].y < p2[j].y) t[i]++;
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++)
      for (k = j + 1; k <= n; k++)
        if (s[i][j] + s[j][k] == s[i][k] + t[j]) ans++;
  printf("%d\n", ans);
  return 0;
}
