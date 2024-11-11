#include <bits/stdc++.h>
using namespace std;
const double eps = 1E-9;
const double inf = 10000000;
const double PI = acos(-1);
int dblcmp(double d) {
  if (fabs(d) < eps) return 0;
  return (d > 0) ? 1 : -1;
}
struct point {
  double x, y;
  point() {}
  point(double _x, double _y) : x(_x), y(_y) {}
  void input() { scanf("%lf%lf", &x, &y); }
  bool operator<(const point &A) const {
    if (dblcmp(x - A.x) == 0) return dblcmp(y - A.y) < 0;
    return (dblcmp(x - A.x) < 0);
  }
  bool operator==(const point &A) const {
    return dblcmp(x - A.x) == 0 && dblcmp(y - A.y) == 0;
  }
  void normal(const point &p1, const point &p2) {
    x = p1.y - p2.y;
    y = p2.x - p1.x;
  }
  double operator&(const point &p) const { return x * (p.x) + y * (p.y); }
  void diff(const point &p1, const point &p2) {
    x = p1.x - p2.x;
    y = p1.y - p2.y;
  }
};
const point reg[] = {point(3.830127018922193, 3.366025403784439),
                     point(-3.601321235851749, 10.057331467373021),
                     point(0.466045194906253, 19.192786043799030),
                     point(10.411264148588986, 18.147501411122495),
                     point(12.490381056766580, 8.366025403784439)};
point go, ans[1000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 5; ++i) ans[i] = reg[i];
  go = point(reg[3].x - reg[0].x, reg[3].y - reg[0].y);
  for (int i = 1; i < n; ++i)
    for (int j = i * 4 + 1; j <= i * 4 + 4; ++j)
      ans[j] = point(ans[j - 4].x + go.x, ans[j - 4].y + go.y);
  printf("%d\n", 4 * n + 1);
  for (int i = 0; i < 4 * n + 1; ++i)
    printf("%.15lf %.15lf\n", ans[i].x, ans[i].y);
  printf("1 2 3 4 5\n");
  for (int i = 1; i < n; ++i)
    printf("%d %d %d %d %d\n", i * 4, i * 4 + 2, i * 4 + 3, i * 4 + 4,
           i * 4 + 5);
  printf("1 3 5 2 4");
  for (int i = 1; i < n; ++i)
    printf(" %d %d %d %d", i * 4 + 3, i * 4 + 5, i * 4 + 2, i * 4 + 4);
  for (int i = n - 1; i >= 1; --i) printf(" %d", i * 4);
  printf(" 1\n");
}
