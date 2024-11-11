#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y, z;
  bool operator<(const P &a) const { return y > a.y; }
};
vector<int> v[11];
int a, i, b, n, d, c, m, k;
int o[1];
int l[1];
int j[1];
int e;
int dx[10] = {2, 2, -2, -2, 1, 1, -1, -1},
    dy[10] = {1, -1, 1, -1, 2, -2, 2, -2};
long long mod = 1000000007, mod2 = 1000000009, mod3 = 2017;
long long x, z, y;
double pi = 3.14159265;
P u[1];
stack<int> s;
queue<int> q;
bool as(P a, P b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y > b.y;
}
double f(double n, double m) { return max(n - m, m - n); }
double xx(double y) { return (double)(c - y * b) / a; }
double yy(double x) { return (double)(c - x * a) / b; }
double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
  scanf("%d %d %d", &a, &b, &c);
  c *= -1;
  scanf("%d %d %d %d", &n, &m, &d, &e);
  if (a == 0 || b == 0) {
    x = max(n - d, d - n);
    x += max(m - e, e - m);
    printf("%lld", x);
    return 0;
  }
  double x = (f(n, d) + f(m, e));
  x = min(x, f(n, xx(m)) + dis(xx(m), m, d, yy(d)) + f(yy(d), e));
  x = min(x, f(n, xx(m)) + dis(xx(m), m, xx(e), e) + f(xx(e), d));
  x = min(x, f(yy(n), m) + dis(n, yy(n), d, yy(d)) + f(yy(d), e));
  x = min(x, f(yy(n), m) + dis(n, yy(n), xx(e), e) + f(xx(e), d));
  printf("%.9lf", x);
}
