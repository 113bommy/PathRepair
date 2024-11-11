#include <bits/stdc++.h>
using namespace std;
const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int DY[] = {0, 1, 0, -1, 1, -1, -1, 1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long sqr(long long x) { return x * x; }
long long sqr(int x) { return (long long)x * x; }
double sqr(double x) { return x * x; }
long double sqr(long double x) { return x * x; }
mt19937 mmtw(960172);
long long rnd(long long x, long long y) {
  static uniform_int_distribution<long long> d;
  return d(mmtw) % (y - x + 1) + x;
}
const int N = 1111;
struct Vec2 {
  long long x, y;
  Vec2() {}
  Vec2(long long nx, long long ny) : x(nx), y(ny) {}
  Vec2 operator+(const Vec2& b) const { return {x + b.x, y + b.y}; }
  Vec2 operator-(const Vec2& b) const { return {x - b.x, y - b.y}; }
  Vec2 operator-() const { return {-x, -y}; }
  Vec2 operator*(long long b) const { return {x * b, y * b}; }
  Vec2& operator+=(const Vec2& b) {
    x += b.x;
    y += b.y;
    return *this;
  }
  Vec2& operator-=(const Vec2& b) {
    x -= b.x;
    y -= b.y;
    return *this;
  }
  Vec2& operator*=(long long b) {
    x *= b;
    y *= b;
    return *this;
  }
  bool operator==(const Vec2& b) const { return x == b.x && y == b.y; }
  bool operator!=(const Vec2& b) const { return x != b.x && y != b.y; }
  bool operator<(const Vec2& b) const { return x == b.x ? y < b.y : x < b.x; }
  bool operator<=(const Vec2& b) const { return x == b.x ? y <= b.y : x < b.x; }
  bool operator>(const Vec2& b) const { return x == b.x ? y > b.y : x > b.x; }
  bool operator>=(const Vec2& b) const { return x == b.x ? y >= b.y : x > b.x; }
};
istream& operator>>(istream& in, Vec2& v) { return in >> v.x >> v.y; }
ostream& operator<<(ostream& out, const Vec2& v) {
  return out << v.x << " " << v.y;
}
Vec2 operator*(long long b, const Vec2& a) { return {b * a.x, b * a.y}; }
long long dot(const Vec2& a, const Vec2& b) { return a.x * b.x + a.y * b.y; }
long long cross(const Vec2& a, const Vec2& b) { return a.x * b.y - a.y * b.x; }
long long length2(const Vec2& a) { return a.x * a.x + a.y * a.y; }
double length(const Vec2& a) { return sqrt(a.x * a.x + a.y * a.y); }
int n;
Vec2 p[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  Vec2 psum = {0, 0};
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    psum += p[i];
    p[i] *= n;
  }
  for (int i = 0; i < n; ++i) p[i] -= psum;
  set<Vec2> ps;
  for (int i = 0; i < n; ++i) {
    if (p[i] == Vec2(0, 0)) continue;
    if (ps.count(-p[i]))
      ps.erase(-p[i]);
    else
      ps.insert(p[i]);
  }
  if (ps.empty()) {
    cout << "-1\n";
    return 0;
  }
  n = 0;
  for (Vec2 x : ps) p[n++] = x;
  vector<Vec2> ans;
  for (int ii = 0; ii < n; ++ii) {
    Vec2 v = (p[0] + p[ii]);
    bool ok = true;
    for (Vec2 v1 : ans)
      if (cross(v1, v) == 0) {
        ok = false;
        break;
      }
    if (!ok) continue;
    vector<long long> xx;
    for (int i = 0; i < n; ++i) xx.push_back(cross(p[i], v));
    sort((xx).begin(), (xx).end());
    ok = 1;
    for (int i = 0; i < n; ++i)
      if (xx[i] != -xx[n - 1 - i]) {
        ok = false;
        break;
      }
    if (ok) ans.push_back(v);
  }
  cout << ((int)((ans).size())) << "\n";
  return 0;
}
