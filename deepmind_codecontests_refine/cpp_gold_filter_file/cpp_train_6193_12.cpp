#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long double eps = 1e-22;
struct point {
  long double x, y;
  int s, r;
  point(long double x = 0, long double y = 0) : x(x), y(y) {}
  inline point operator-(const point &p) const {
    return point(x - p.x, y - p.y);
  }
  inline long double operator*(const point &p) const {
    return x * p.y - y * p.x;
  }
  inline bool operator<(const point &p) const {
    return s > p.s || (s == p.s && r > p.r);
  }
};
inline int convex(int n, point p[], point q[]) {
  if (n < 3) {
    memcpy(q, p, sizeof(point) * n);
    return n;
  } else {
    int c;
    sort(p, p + n);
    for (int i = c = 0; i < n; q[c++] = p[i++]) {
      for (; c > 1 && (q[c - 1] - q[c - 2]) * (p[i] - q[c - 1]) < 0 - eps; --c)
        ;
    }
    for (int i = n - 2, j = c; i >= 0; q[c++] = p[i--]) {
      for (; c > j && (q[c - 1] - q[c - 2]) * (p[i] - q[c - 1]) < 0 - eps; --c)
        ;
    }
    return c - 1;
  }
}
int n, s[N], r[N];
point p[N], q[N];
map<pair<int, int>, vector<int> > mp;
int find(point &x) {
  for (int i = 0; i < n; ++i) {
    if (x * (q[i + 1] - q[i]) > 0 + eps &&
        (q[i] - q[(i + n - 1) % n]) * x > 0 - eps)
      return i;
  }
}
int find2(point &x) {
  for (int i = 0; i < n; ++i) {
    if (x * (q[i + 1] - q[i]) > 0 - eps &&
        (q[i] - q[(i + n - 1) % n]) * x > 0 + eps)
      return i;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", s + i, r + i);
    mp[make_pair(s[i], r[i])].push_back(i + 1);
  }
  n = 0;
  for (auto &t : mp) {
    p[n].x = 1.0 / t.first.first;
    p[n].y = 1.0 / t.first.second;
    p[n].s = t.first.first;
    p[n].r = t.first.second;
    n++;
  }
  n = convex(n, p, q);
  point a(0, -1), b(1, 0);
  int bg = find(a);
  int ed = find2(b);
  if (ed < bg) ed += n;
  if (n == 1 || n == 2) {
    bg = 0, ed = n - 1;
  }
  vector<int> v;
  for (int i = bg; i <= ed; ++i) {
    auto t = make_pair(q[i % n].s, q[i % n].r);
    for (int j : mp[t]) {
      v.push_back(j);
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); ++i) {
    printf("%d%c", v[i], " \n"[i == (int)v.size() - 1]);
  }
  return 0;
}
