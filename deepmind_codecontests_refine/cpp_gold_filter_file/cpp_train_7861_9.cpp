#include <bits/stdc++.h>
using namespace std;
long long n, sum;
long double ansn, b;
struct Po {
  long double x, y;
} a[100010], z, y;
Po operator-(Po x, Po y) { return (Po){x.x - y.x, x.y - y.y}; }
Po operator+(Po x, Po y) { return (Po){x.x + y.x, x.y + y.y}; }
Po operator*(Po x, long double y) { return (Po){x.x * y, x.y * y}; }
long double operator*(Po x, Po y) { return x.x * y.y - x.y * y.x; }
long double operator^(Po x, Po y) { return x.x * y.x + x.y * y.y; }
long double dis(Po x, Po y) {
  return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}
Po get(long double x, long double y) { return (Po){x * cosl(y), x * sinl(y)}; }
bool comp(const Po &a, const Po &b) {
  return abs(dis(a, y) - dis(a, z)) < abs(dis(b, y) - dis(b, z));
}
int main() {
  cin >> n >> b;
  ansn = b * 2;
  z = (Po){-b, 0};
  y = (Po){b, 0};
  for (int i = 1; i <= n; i++) scanf("%Lf %Lf", &a[i].x, &a[i].y);
  sort(a + 1, a + n + 1, comp);
  int m = min(n, 50000000 / n);
  for (int i = 1; i < m; i++) {
    for (int j = i + 1; j <= n; j++) {
      long double q = (a[i].x - a[j].x) * (a[i].x - a[j].x) +
                      (a[i].y - a[j].y) * (a[i].y - a[j].y);
      Po x = (a[j] - a[i]) * (((a[j] - a[i]) ^ (y - a[i])) / q);
      ansn = min(ansn, dis(a[i] + a[i] + x + x - y, z));
    }
  }
  printf("%.10Lf\n", ansn);
  return 0;
}
