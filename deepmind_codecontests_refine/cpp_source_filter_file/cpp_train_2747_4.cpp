#include <bits/stdc++.h>
using namespace std;
struct dot {
  double x, y;
  int id;
  dot(double xx = 0, double yy = 0) { x = xx, y = yy; };
};
dot operator-(dot a, dot b) { return dot(a.x - b.x, a.y - b.y); }
bool operator<(dot a, dot b) { return (a.x < b.x); }
double dist(dot a) { return sqrt(a.x * a.x + a.y * a.y); }
dot p[100008];
double ans;
int n;
int ck;
void calc() {
  int k;
  for (int i = 1; i <= n; i++)
    if (p[i].id == ck) k = i;
  for (int i = 1; i <= n; i++) {
    double res = 0;
    double r1 = 0, r2 = 0;
    r1 = dist(p[k] - p[1]) + dist(p[i] - p[n + 1]);
    r2 = dist(p[k] - p[i]) + dist(p[1] - p[n + 1]);
    res += min(r1, r2) + dist(p[1] - p[i]);
    if (i < n)
      res += min(dist(p[n] - p[n + 1]), dist(p[n + 1] - p[i + 1])) +
             dist(p[i + 1] - p[n]);
    ans = min(ans, res);
  }
}
int main() {
  cin >> n;
  cin >> ck;
  for (int i = 1; i <= n + 1; i++) scanf("%lf", &p[i].x), p[i].id = i;
  scanf("%lf", &p[n + 1].y);
  sort(p + 1, p + n + 1);
  if (ck == n + 1) {
    ans = dist(p[n + 1] - p[1]) + dist(p[n + 1] - p[n]) + dist(p[n] - p[1]);
    printf("%.15lf", ans);
    return 0;
  }
  ans = 1e15;
  calc();
  for (int i = 1; i <= n + 1; i++) p[i].x = -p[i].x;
  reverse(p + 1, p + n + 1);
  calc();
  printf("%.15lf", ans);
  return 0;
}
