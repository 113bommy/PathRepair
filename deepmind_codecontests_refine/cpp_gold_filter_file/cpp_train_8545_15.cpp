#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1);
int sign(double k) {
  if (k > eps)
    return 1;
  else if (k < -eps)
    return -1;
  return 0;
}
int cmp(double k1, double k2) { return sign(k1 - k2); }
int inmid(double k1, double k2, double k3) {
  return sign(k1 - k3) * sign(k2 - k3) <= 0;
}
struct point {
  double x, y;
  point operator+(const point &k1) const { return (point){k1.x + x, k1.y + y}; }
  point operator-(const point &k1) const { return (point){x - k1.x, y - k1.y}; }
  point operator*(double k1) const { return (point){x * k1, y * k1}; }
  point operator/(double k1) const { return (point){x / k1, y / k1}; }
  int operator==(const point &k1) const {
    return cmp(x, k1.x) == 0 && cmp(y, k1.y) == 0;
  }
  double abs() { return sqrt(x * x + y * y); }
  double abs2() { return x * x + y * y; }
  double dis(point k1) { return ((*this) - k1).abs(); }
  point unit() {
    double w = abs();
    return (point){x / w, y / w};
  }
};
int inmid(point k1, point k2, point k3) {
  return inmid(k1.x, k2.x, k3.x) && inmid(k1.y, k2.y, k3.y);
}
double cross(point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }
double dot(point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }
point getLL(point k1, point k2, point k3, point k4) {
  double w1 = cross(k1 - k3, k4 - k3), w2 = cross(k4 - k3, k2 - k3);
  return (k1 * w2 + k2 * w1) / (w1 + w2);
}
struct Seg {
  int l, r;
} s[400005];
long long n, sy, a, b, sum[400005];
point L, R, k1, k2, k3;
int main() {
  cin >> sy >> a >> b >> n;
  L = (point){a * 1.0, sy * 1.0}, R = (point){b * 1.0, sy * 1.0};
  for (int i = 1; i <= n; i++) scanf("%d%d", &s[i].l, &s[i].r);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + s[i].r - s[i].l;
  int q;
  cin >> q;
  while (q--) {
    scanf("%lf%lf", &k1.x, &k1.y);
    k2 = getLL(k1, L, (point){-1, 0}, (point){1, 0});
    k3 = getLL(k1, R, (point){-1, 0}, (point){1, 0});
    if (k2.x >= s[n].r || k3.x <= s[1].l) {
      cout << 0 << '\n';
      continue;
    }
    int l = 1, r = n, mid, pos1 = n + 1;
    while (l <= r) {
      mid = l + r >> 1;
      if (s[mid].l >= k2.x)
        pos1 = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    l = 1, r = n;
    int pos2 = 0;
    while (l <= r) {
      mid = l + r >> 1;
      if (s[mid].r <= k3.x)
        pos2 = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    double len = 0;
    if (pos2 >= pos1) len += sum[pos2] - sum[pos1 - 1];
    if (pos1 == pos2 + 2) {
      len = k3.x - k2.x;
      printf("%.10lf\n", len / (k3.x - k2.x) * (b - a));
      continue;
    }
    if (pos1 > 1) len += max(0.0, s[pos1 - 1].r - k2.x);
    if (pos2 < n) len += max(0.0, k3.x - s[pos2 + 1].l);
    printf("%.10lf\n", len / (k3.x - k2.x) * (b - a));
  }
}
