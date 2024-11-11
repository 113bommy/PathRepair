#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Point {
 public:
  T x, y;
  Point() : x(0), y(0) {}
  Point(T x_, T y_) : x(x_), y(y_) {}
  template <typename U>
  explicit Point(const Point<U>& p) : x(p.x), y(p.y) {}
  Point(const std::pair<T, T>& p) : x(p.first), y(p.second) {}
  Point(const std::complex<T>& p) : x(real(p)), y(imag(p)) {}
  explicit operator std::pair<T, T>() const { return std::pair<T, T>(x, y); }
  explicit operator std::complex<T>() const { return std::complex<T>(x, y); }
  friend std::ostream& operator<<(std::ostream& o, const Point& p) {
    return o << '(' << p.x << ',' << p.y << ')';
  }
  friend std::istream& operator>>(std::istream& i, Point& p) {
    return i >> p.x >> p.y;
  }
  friend bool operator==(const Point& a, const Point& b) {
    return a.x == b.x && a.y == b.y;
  }
  friend bool operator!=(const Point& a, const Point& b) { return !(a == b); }
  friend bool operator<(const Point& a, const Point& b) {
    return (a.x != b.x ? a.x < b.x : a.y < b.y);
  }
  friend T norm(const Point& a) { return a.x * a.x + a.y * a.y; }
  friend T abs(const Point& p) { return std::hypot(p.x, p.y); }
  friend T unit(const Point& a) {
    if (a == Point()) return a;
    return a / abs(a);
  }
  friend Point conj(const Point& a) { return Point(a.x, -a.y); }
  friend Point perp(const Point& a) { return Point(-a.y, a.x); }
  friend long double arg(const Point& p) { return atan2(p.y, p.x); }
  friend Point dir(long double angle) { return Point(cos(angle), sin(angle)); }
  Point& operator+=(const Point& p) {
    x += p.x, y += p.y;
    return *this;
  }
  Point& operator-=(const Point& p) {
    x -= p.x, y -= p.y;
    return *this;
  }
  Point& operator*=(const T& t) {
    x *= t, y *= t;
    return *this;
  }
  Point& operator/=(const T& t) {
    x /= t, y /= t;
    return *this;
  }
  Point& operator*=(const Point& t) {
    Point res = Point(x, y) * t;
    x = res.x, y = res.y;
    return *this;
  }
  Point& operator/=(const Point& t) {
    Point res = Point(x, y) / t;
    x = res.x, y = res.y;
    return *this;
  }
  friend Point operator+(const Point& a, const Point& b) {
    return Point(a.x + b.x, a.y + b.y);
  }
  friend Point operator-(const Point& a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
  }
  friend Point operator*(const Point& a, const T& t) {
    return Point(a.x * t, a.y * t);
  }
  friend Point operator*(const T& t, const Point& a) {
    return Point(t * a.x, t * a.y);
  }
  friend Point operator/(const Point& a, const T& t) {
    return Point(a.x / t, a.y / t);
  }
  friend Point operator*(const Point& a, const Point& b) {
    return Point(a.x * b.x - a.y * b.y, a.y * b.x + a.x * b.y);
  }
  friend Point operator/(const Point& a, const Point& b) {
    return Point(a * conj(b) / norm(b));
  }
  friend T int_norm(const Point& a) { return __gcd(a.x, a.y); }
  friend T int_unit(const Point& a) {
    if (a == Point()) return a;
    return a / int_norm(a);
  }
  friend T cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
  }
  friend T dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
  friend T area(const Point& a, const Point& b, const Point& c) {
    return cross(b - a, c - a);
  }
  friend Point rotation(const Point& a, const Point& b) {
    return Point(dot(a, b), cross(a, b));
  }
  friend bool same_dir(const Point& a, const Point& b) {
    return cross(a, b) == 0 && dot(a, b) > 0;
  }
  friend bool is_reflex(const Point& a, const Point& b) {
    auto c = cross(a, b);
    return c ? (c < 0) : (dot(a, b) < 0);
  }
  friend bool angle_less(const Point& base, const Point& second,
                         const Point& t) {
    int r = is_reflex(base, second) - is_reflex(base, t);
    return r ? (r < 0) : (0 < cross(second, t));
  }
  friend bool angle_cmp(const Point& base) {
    return [base](const Point& second, const Point& t) {
      return angle_less(base, second, t);
    };
  }
  friend bool angle_cmp_center(const Point& center, const Point& dir) {
    return [center, dir](const Point& second, const Point& t) -> bool {
      return angle_less(dir, second - center, t - center);
    };
  }
  friend int angle_between(const Point& second, const Point& t,
                           const Point& p) {
    if (same_dir(p, second) || same_dir(p, t)) return 0;
    return angle_less(second, p, t) ? 1 : -1;
  }
};
int main() {
  int n;
  cin >> n;
  auto query = [&](int t, int x, int y, int z) {
    cout << t << " " << y + 1 << " " << z + 1 << " " << x + 1 << endl;
    long long ret;
    cin >> ret;
    return ret;
  };
  int e1 = 0;
  int e2 = 1;
  vector<int> L, R;
  vector<long long> A(n);
  for (int i = 2; i < n; i++) {
    if (query(2, e1, i, e2) > 0) {
      R.push_back(i);
    } else {
      L.push_back(i);
    }
  }
  int nl = (int)(L).size();
  int nr = (int)(R).size();
  for (int i = 2; i < n; i++) {
    A[i] = query(1, e1, e2, i);
  }
  vector<int> hull;
  hull.push_back(e2);
  {
    sort((L).begin(), (L).end(), [&](int x, int y) { return A[x] < A[y]; });
    deque<int> d;
    int big = -1;
    if ((int)(L).size()) big = L.back();
    while ((int)(L).size()) {
      int x = L.back();
      L.pop_back();
      if ((int)(d).size() == 0) {
        d.push_back(x);
      } else {
        if (query(2, e2, x, big) > 0) {
          d.push_front(x);
        } else {
          d.push_back(x);
        }
      }
    }
    for (int x : d) hull.push_back(x);
    hull.push_back(e1);
  }
  {
    sort((R).begin(), (R).end(), [&](int x, int y) { return A[x] < A[y]; });
    deque<int> d;
    int big = -1;
    if ((int)(R).size()) big = R.back();
    while ((int)(R).size()) {
      int x = R.back();
      R.pop_back();
      if ((int)(d).size() == 0) {
        d.push_back(x);
      } else {
        if (query(2, e1, x, big) > 0) {
          d.push_front(x);
        } else {
          d.push_back(x);
        }
      }
    }
    for (int x : d) hull.emplace_back(x);
  }
  cout << 0 << " ";
  vector<int> res;
  int id = 0;
  for (int i = 0; i < n; i++) {
    if (hull[i] == 0) id = i;
  }
  for (int i = 0; i < n; i++) {
    res.emplace_back(hull[(id + i) % n]);
  }
  for (int x : res) {
    cout << x + 1 << " ";
  }
  cout << endl;
  return 0;
}
