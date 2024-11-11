#include <bits/stdc++.h>
using namespace std;
struct node {
  double t, v, ans;
  int id;
} c[100005];
bool cmp(node a, node b) { return a.t < b.t; }
bool CMP(node a, node b) { return a.id < b.id; }
int main() {
  int n;
  double a, d;
  scanf("%d%lf%lf", &n, &a, &d);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &c[i].t, &c[i].v);
    c[i].id = i;
  }
  sort(c, c + n, cmp);
  for (int i = 0; i < n; i++) {
    double tt = c[i].v / a;
    if (tt * c[i].v * 0.5 > d)
      c[i].ans = sqrt(d * 2 / a) + c[i].t;
    else
      c[i].ans = (d - tt * c[i].v * 0.5) / c[i].v + c[i].t + tt;
  }
  sort(c, c + n, CMP);
  printf("%.10lf\n", c[0].ans);
  for (int i = 1; i < n; i++) {
    if (c[i].ans < c[i - 1].ans) {
      c[i].ans = c[i - 1].ans;
      printf("%.10lf\n", c[i].ans);
    } else
      printf("%.10lf\n", c[i].ans);
  }
  return 0;
}
