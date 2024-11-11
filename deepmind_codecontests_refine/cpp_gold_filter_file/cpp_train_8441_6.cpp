#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
  long double ang;
};
point p[4010], cur[4010];
bool cmp(point a, point b) { return a.ang < b.ang; }
point operator-(point a, point b) { return (point){a.x - b.x, a.y - b.y}; }
long long cross(point a, point b) { return a.x * b.y - a.y * b.x; }
long long C(long long x) { return x * (x - 1) / 2; }
int main() {
  long long res = 0;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d%I64d", &p[i].x, &p[i].y);
  for (int i = 1; i <= n; i++) {
    int tot = 0;
    for (int j = 1; j <= n; j++)
      if (j != i) {
        cur[++tot] = p[j] - p[i];
        cur[tot].ang = atan2(cur[tot].y, cur[tot].x);
      }
    sort(cur + 1, cur + tot + 1, cmp);
    for (int j = 1; j <= tot; j++) cur[j + tot] = cur[j];
    int righ = 1;
    for (int i = 1; i <= tot; i++) {
      if (righ < i) righ = i;
      while (righ < 2 * tot && cross(cur[i], cur[righ + 1]) > 0) righ++;
      if (cur[i].x > 0 || cur[i].x == 0 && cur[i].y > 0)
        res += C(righ - i) * C(n - 2 - (righ - i));
    }
  }
  printf("%I64d\n", res);
  return 0;
}
