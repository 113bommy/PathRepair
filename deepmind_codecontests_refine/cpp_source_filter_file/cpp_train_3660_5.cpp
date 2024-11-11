#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
const double pi = acos(-1.0);
int sign(double k) {
  if (k > eps)
    return 1;
  else if (k < -eps)
    return -1;
  return 0;
}
int cmp(double k1, double k2) { return sign(k1 - k2); }
struct point {
  double x, y;
  int id;
  point() {}
  point(double x_, double y_) : x(x_), y(y_) {}
  point(double x_, double y_, int id_) : x(x_), y(y_), id(id_) {}
  point operator+(const point& k) const { return point(k.x + x, k.y + y); }
  point operator-(const point& k) const { return point(x - k.x, y - k.y); }
  point operator*(double k) const { return point(x * k, y * k); }
  point operator/(double k1) const { return point(x / k1, y / k1); }
  point turn(double k1) {
    return point(x * cos(k1) - y * sin(k1), x * sin(k1) + y * cos(k1));
  }
  point turn90() { return point(-y, x); }
  double len() { return sqrt(x * x + y * y); }
  double len2() { return x * x + y * y; }
  double dis(point rhs) { return ((*this) - rhs).len(); }
  point unit() {
    double d = len();
    return point(x / d, y / d);
  }
  bool operator<(const point& k) const { return x == k.x ? y < k.y : x < k.x; }
  bool getP() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) == -1); }
} triangleVertex[3];
double cross(point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }
double dot(point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }
double rad(point k1, point k2) { return atan2(cross(k1, k2), dot(k1, k2)); }
int compareangle(point k1, point k2) {
  return k1.getP() < k2.getP() ||
         (k1.getP() == k2.getP() && sign(cross(k1, k2)) > 0);
}
point proj(point k1, point k2, point q) {
  point k = k2 - k1;
  return k1 + k * (dot(q - k1, k) / k.len2());
}
point reflect(point k1, point k2, point q) { return proj(k1, k2, q) * 2 - q; }
int clockwise(point k1, point k2, point k3) {
  return sign(cross(k2 - k1, k3 - k1));
}
int checkLL(point k1, point k2, point k3, point k4) {
  return cmp(cross(k3 - k1, k4 - k1), cross(k3 - k2, k4 - k2)) != 0;
}
double deg(point k1, point k2) {
  return asin(cross(k1, k2) / k1.len() / k2.len());
}
struct line {
  point p[2];
  line() {}
  line(point k1, point k2) { p[0] = k1, p[1] = k2; }
  point& operator[](int k) { return p[k]; }
  point dir() { return p[1] - p[0]; }
  bool include(point k) { return sign(cross(p[1] - p[0], k - p[0])) > 0; }
  line push(double len) {
    point delta = (p[1] - p[0]).turn90().unit() * len;
    return line(p[0] - delta, p[1] - delta);
  }
} triangle[3];
bool parallel(line k1, line k2) { return sign(cross(k1.dir(), k2.dir())) == 0; }
bool sameDir(line k1, line k2) {
  return parallel(k1, k2) && sign(dot(k1.dir(), k2.dir())) == 1;
}
bool operator<(line k1, line k2) {
  if (sameDir(k1, k2)) return k2.include(k1[0]);
  return compareangle(k1.dir(), k2.dir());
}
point getLL(point k1, point k2, point k3, point k4) {
  double w1 = cross(k1 - k3, k4 - k3), w2 = cross(k4 - k3, k2 - k3);
  return (k1 * w2 + k2 * w1) / (w1 + w2);
}
point getLL(line k1, line k2) { return getLL(k1[0], k1[1], k2[0], k2[1]); }
bool checkpos(line k1, line k2, line k3) { return k3.include(getLL(k1, k2)); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<point> p(n);
  vector<bool> vis(n, false);
  vector<int> ans;
  for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y, p[i].id = i;
  sort(p.begin(), p.end());
  ans.emplace_back(p[0].id);
  vis[p[0].id] = true;
  string s;
  cin >> s;
  sort(p.begin() + 1, p.end(), [&](point& i, point& j) {
    return atan2(i.y - p[0].y, i.x - p[0].x) <
           atan2(j.y - p[0].y, j.x - p[0].x);
  });
  point pre = p[0], now;
  if (s[0] == 'L') {
    ans.emplace_back(p[1].id);
    vis[p[1].id] = true;
    now = p[1];
  } else {
    ans.emplace_back(p[n - 1].id);
    vis[p[n - 1].id] = true;
    now = p[n - 1];
  }
  for (int i = 1; i < s.length(); ++i) {
    if (s[i] == 'L') {
      if (s[i - 1] == 'R') {
        double angle = 2.0 * pi + 1.0;
        int id;
        for (int j = 1; j < n; ++j) {
          if (vis[p[j].id]) continue;
          double ta = fabs(rad(pre - now, p[j] - now));
          if (ta < angle) {
            angle = ta;
            id = j;
          }
        }
        ans.emplace_back(p[id].id);
        vis[p[id].id] = true;
        pre = now, now = p[id];
      } else {
        double angle = 0.0;
        int id;
        for (int j = 1; j < n; ++j) {
          if (vis[p[j].id]) continue;
          double ta = fabs(rad(pre - now, p[j] - now));
          if (ta > angle) {
            angle = ta;
            id = j;
          }
        }
        ans.emplace_back(p[id].id);
        vis[p[id].id] = true;
        pre = now, now = p[id];
      }
    } else {
      if (s[i - 1] == 'L') {
        double angle = 0.0;
        int id;
        for (int j = 1; j < n; ++j) {
          if (vis[p[j].id]) continue;
          double ta = fabs(rad(pre - now, p[j] - now));
          if (ta > angle) {
            angle = ta;
            id = j;
          }
        }
        ans.emplace_back(p[id].id);
        vis[p[id].id] = true;
        pre = now, now = p[id];
      } else {
        double angle = 2.0 * pi + 1.0;
        int id;
        for (int j = 1; j < n; ++j) {
          if (vis[p[j].id]) continue;
          double ta = fabs(rad(pre - now, p[j] - now));
          if (ta < angle) {
            angle = ta;
            id = j;
          }
        }
        ans.emplace_back(p[id].id);
        vis[p[id].id] = true;
        pre = now, now = p[id];
      }
    }
  }
  for (int i = 0; i < n; ++i)
    if (!vis[i]) ans.emplace_back(i);
  for (auto i : ans) cout << i + 1 << ' ';
  return 0;
}
