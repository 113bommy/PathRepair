#include <bits/stdc++.h>
using namespace std;
const int N = 20010;
const long double eps = 1e-13;
struct P {
  long double x, y;
} pb[N], pr[N], ipb[N], ipr[N], hb[N], o;
long double ms = 1e9, ml = 0;
int n, m, hbt, hrt;
P operator-(P a, P b) {
  P c;
  c.x = a.x - b.x;
  c.y = a.y - b.y;
  return c;
}
P operator+(P a, P b) {
  P c;
  c.x = a.x + b.x;
  c.y = a.y + b.y;
  return c;
}
double operator*(P a, P b) { return a.x * b.y - a.y * b.x; }
double operator^(P a, P b) { return a.x * b.x + a.y * b.y; }
double dis2(P a, P b) {
  P c = a - b;
  return c ^ c;
}
P inv(P a, P b) {
  P c = a - b;
  long double d = c ^ c;
  c.x = c.x * 400 / d;
  c.y = c.y * 400 / d;
  c = b + c;
  return c;
}
bool operator<(P a, P b) {
  long double s = (a - o) * (b - o);
  return fabs(s) < eps ? dis2(a, o) < dis2(b, o) : s > 0;
}
void graham(P p[], P h[], int n, int &ht) {
  int i, k = 1;
  ht = 0;
  for (i = 1; i <= n; i++)
    if (p[i].y < p[k].y || (p[i].y == p[k].y && p[i].x < p[k].x)) k = i;
  swap(p[1], p[k]);
  o = p[1];
  sort(p + 1, p + n + 1);
  for (i = 1; i <= n; i++) {
    while (ht > 1) {
      if ((h[ht] - h[ht - 1]) * (p[i] - h[ht]) > 0)
        break;
      else
        ht--;
    }
    h[++ht] = p[i];
  }
}
void mainmin(long double s, long double l) {
  if (ms * ms * l > s * s * ml) ms = s, ml = l;
}
void rc() {
  int i, j;
  long double s;
  P l, r, p;
  for (i = 1; i <= hbt; i++) {
    l = hb[(i + 1) % hbt + 1] - hb[i % hbt + 1];
    r = hb[i % hbt + 1] - hb[(i - 1) % hbt + 1];
    for (j = 1; j <= n; j++) {
      p = ipr[j] - hb[i % hbt + 1];
      if (p * l > -eps) {
        s = (l * (o - hb[i % hbt + 1]));
        mainmin(s, l ^ l);
        if (r * p > -eps) {
          s = (p * (o - hb[i % hbt + 1]));
          mainmin(s, p ^ p);
        }
      }
    }
  }
}
int main() {
  int i, j;
  double x, y;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%lf%lf", &x, &y);
    pr[i].x = x;
    pr[i].y = y;
  }
  for (i = 1; i <= m; i++) {
    scanf("%lf%lf", &x, &y);
    pb[i].x = x;
    pb[i].y = y;
  }
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) ipr[j] = inv(pr[j], pb[i]);
    for (j = 1; j <= m; j++)
      if (j != i) ipb[j] = inv(pb[j], pb[i]);
    ipb[i] = ipb[m];
    graham(ipb, hb, m - 1, hbt);
    o = pb[i];
    rc();
  }
  if (ms <= 0 || m < 3)
    printf("-1\n");
  else
    printf("%.8lf\n", (double)((sqrt(ml) * 400) / (2 * ms)));
  return 0;
}
