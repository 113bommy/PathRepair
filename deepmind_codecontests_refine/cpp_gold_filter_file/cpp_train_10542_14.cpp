#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
  friend long long cross(point a, point b, point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
  }
  friend bool operator<(point a, point b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
  }
  void init() { scanf("%I64d%I64d", &x, &y); }
} red[510], blue[510];
long long f[510][510];
long long n, m, ans;
int main() {
  scanf("%I64d%I64d", &n, &m);
  for (long long i = 0; i < n; i++) red[i].init();
  for (long long i = 0; i < m; i++) blue[i].init();
  sort(red, red + n);
  for (long long i = 0; i < n; i++)
    for (long long j = i + 1; j < n; j++)
      if (red[i].x < red[j].x)
        for (long long k = 0; k < m; k++)
          if (blue[k].x >= red[i].x && blue[k].x < red[j].x)
            f[i][j] += (cross(red[i], red[j], blue[k]) > 0LL);
  for (long long i = 0; i < n; i++)
    for (long long j = i + 1; j < n; j++)
      for (long long k = j + 1; k < n; k++)
        if (f[i][j] + f[j][k] == f[i][k]) ans++;
  printf("%I64d\n", ans);
  return 0;
}
