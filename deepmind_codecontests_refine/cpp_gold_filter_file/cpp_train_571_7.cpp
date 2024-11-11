#include <bits/stdc++.h>
using namespace std;
struct P {
  double x, y;
} p[200500], o;
double mn, mx;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
P operator-(P x, P y) { return (P){x.x - y.x, x.y - y.y}; }
double dis(P x, P y) {
  P z = x - y;
  return sqrt(z.x * z.x + z.y * z.y);
}
int cmp(double x) {
  if (x < -1e-9) return -1;
  if (x > 1e-9) return 1;
  return 0;
}
double dot(P x, P y) { return x.x * y.x + x.y * y.y; }
double det(P x, P y) { return x.x * y.y - y.x * x.y; }
int main() {
  int n = read();
  scanf("%lf%lf", &o.x, &o.y);
  for (int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
  mn = mx = dis(p[1], o);
  p[n + 1] = p[1];
  for (int i = 1; i <= n; i++) {
    mn = min(mn, dis(p[i], o));
    mx = max(mx, dis(p[i], o));
    if (cmp(dot(o - p[i], p[i + 1] - p[i])) >= 0 &&
        cmp(dot(o - p[i + 1], p[i] - p[i + 1])) >= 0) {
      mn = min(mn, fabs(det(p[i + 1] - p[i], o - p[i])) / dis(p[i + 1], p[i]));
    }
  }
  printf("%.12lf\n", acos(-1.0) * (mx * mx - mn * mn));
  return 0;
}
