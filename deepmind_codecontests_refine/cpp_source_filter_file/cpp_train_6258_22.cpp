#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const double eps = 1e-8;
int n, top;
long long t;
double m;
struct node {
  int a, b;
  double p, e;
} a[N];
bool cmp(node a, node b) {
  return fabs(a.p - b.p) < eps ? a.e > b.e : a.p < b.p;
}
struct matrix {
  double f[3][3];
  void clear() {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) f[i][j] = 0;
  }
  matrix operator*(const matrix a) const {
    matrix c;
    c.clear();
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        for (int k = 0; k < 3; k++) c.f[i][k] += f[i][j] * a.f[j][k];
    return c;
  }
} d[110], s, p;
node st[N];
matrix init(node a) {
  matrix c;
  c.clear();
  c.f[0][0] = 1 - a.p;
  c.f[1][0] = a.p * m;
  c.f[2][0] = a.e;
  c.f[1][1] = c.f[2][1] = 1;
  c.f[2][2] = 1;
  return c;
}
bool check(node a, node b, node c) {
  return (b.p - a.p) * (c.e - a.e) - (c.p - a.p) * (b.e - a.e) > eps;
}
int main() {
  scanf("%d%lld", &n, &t);
  for (int i = 1; i <= n; i++)
    scanf("%d%d%lf", &a[i].a, &a[i].b, &a[i].p), a[i].e = a[i].a * a[i].p,
                                                 m = max(m, a[i].b * a[i].p);
  sort(a + 1, a + n + 1, cmp);
  st[++top] = a[1];
  for (int i = 2; i <= n; i++) {
    if (fabs(a[i].p - a[i - 1].p) < eps) continue;
    while (top > 1 && check(st[top - 1], st[top], a[i])) top--;
    st[++top] = a[i];
  }
  long long nt = 0;
  int now = 1;
  s.f[0][2] = 1;
  while (nt < t) {
    double k = s.f[0][0] - s.f[0][1] * m;
    while (now < top &&
           (st[now + 1].e - st[now].e) > k * (st[now + 1].p - st[now].p))
      now++;
    d[0] = init(st[now]);
    for (int i = 1; i <= 34; i++) d[i] = d[i - 1] * d[i - 1];
    for (int i = 34; i >= 0; i--)
      if (nt + (1ll << i) < t) {
        p = s * d[i];
        double kk = p.f[0][1] * m - p.f[0][0];
        if (now == top ||
            st[now].p * kk + st[now].e > st[now + 1].p * kk + st[now + 1].e)
          s = p, nt += 1ll << i;
      }
    s = s * d[0];
    nt++;
  }
  printf("%.10lf\n", s.f[0][0]);
  return 0;
}
