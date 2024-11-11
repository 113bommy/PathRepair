#include <bits/stdc++.h>
using namespace std;
int inmid(long long k1, long long k2, long long k3) {
  return (k1 - k3) * (k2 - k3) <= 0;
}
struct point {
  long long x, y;
  point operator+(const point &k1) const { return (point){k1.x + x, k1.y + y}; }
  point operator-(const point &k1) const { return (point){x - k1.x, y - k1.y}; }
  point operator*(long long k1) const { return (point){x * k1, y * k1}; }
  point operator/(long long k1) const { return (point){x / k1, y / k1}; }
  int operator==(const point &k1) const { return x == k1.x && y == k1.y; }
};
int inmid(point k1, point k2, point k3) {
  return inmid(k1.x, k2.x, k3.x) && inmid(k1.y, k2.y, k3.y);
}
long long cross(point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }
long long dot(point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }
struct line {
  point p[2];
  line(point k1, point k2) {
    p[0] = k1;
    p[1] = k2;
  }
  point &operator[](int k) { return p[k]; }
};
long long cross(line a, line b) { return cross(a[1] - a[0], b[1] - b[0]); }
long long dot(line a, line b) { return dot(a[1] - a[0], b[1] - b[0]); }
int t;
point p[7];
vector<line> l;
bool check(long long x, long long y) {
  if (x * 5 < y) return 0;
  if (x * 5 > y * 4) return 0;
  return 1;
}
bool slove(line a, line b, line c) {
  if (a[1] == b[1]) swap(a[0], a[1]), swap(b[0], b[1]);
  if (a[1] == b[0]) swap(a[0], a[1]);
  if (a[0] == b[1]) swap(b[0], b[1]);
  if (!(a[0] == b[0])) return 0;
  if (cross(a, b) == 0) return 0;
  if (dot(a, b) <= 0) return 0;
  if (cross(a[1] - a[0], c[1] - a[0]) == 0 &&
      cross(b[1] - b[0], c[0] - b[0]) == 0) {
  } else
    swap(c[0], c[1]);
  if (!(cross(a[1] - a[0], c[1] - a[0]) == 0 &&
        cross(b[1] - b[0], c[0] - b[0]) == 0))
    return 0;
  if (!inmid(a[0], a[1], c[1])) return 0;
  if (!inmid(b[0], b[1], c[0])) return 0;
  if (!check(abs(a[0].x - c[1].x), abs(a[1].x - a[0].x))) return 0;
  if (!check(abs(a[0].y - c[1].y), abs(a[1].y - a[0].y))) return 0;
  if (!check(abs(b[0].x - c[0].x), abs(b[0].x - b[1].x))) return 0;
  if (!check(abs(b[0].y - c[0].y), abs(b[0].y - b[1].y))) return 0;
  return 1;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    l.clear();
    for (int i = 1; i <= 6; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
    l.push_back({p[1], p[2]});
    l.push_back({p[3], p[4]});
    l.push_back({p[5], p[6]});
    if (slove(l[0], l[1], l[2]))
      cout << "YES" << endl;
    else if (slove(l[0], l[2], l[1]))
      cout << "YES" << endl;
    else if (slove(l[1], l[2], l[0]))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
