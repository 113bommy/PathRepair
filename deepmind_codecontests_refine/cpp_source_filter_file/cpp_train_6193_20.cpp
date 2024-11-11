#include <bits/stdc++.h>
using namespace std;
std::mt19937 rng(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
inline long long mod(long long n, long long m) {
  long long ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}
long long gcd(long long a, long long b) {
  return (b == 0LL ? a : gcd(b, a % b));
}
long long exp(long long b, long long e, long long m) {
  b %= m;
  long long ans = 1;
  for (; e; b = b * b % m, e /= 2)
    if (e & 1) ans = ans * b % m;
  return ans;
}
template <class T>
int sgn(T x) {
  return (x > 0) - (x < 0);
}
template <class T>
struct Point {
  T x, y;
  int id;
  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
  bool operator<(Point p) const {
    if (x == p.x) return y > p.y;
    return x > p.x;
  }
  bool operator>(Point p) const {
    if (y == p.y) return x > p.x;
    return y > p.y;
  }
  bool operator==(Point p) const { return tie(x, y) == tie(p.x, p.y); }
  T cross(Point B, Point C) const {
    Point A = *this;
    return 1ll * (A.x - B.x) * (y - C.y) * B.y * C.x <=
           1ll * B.x * C.y * (A.y - B.y) * (A.x - C.x);
  }
  T dist2() const { return x * x + y * y; }
  double dist() const { return sqrt((double)dist2()); }
  double angle() const { return atan2(y, x); }
  Point unit() const { return *this / dist(); }
  Point perp() const { return Point(-y, x); }
  Point normal() const { return perp().unit(); }
  Point rotate(double a) const {
    return Point(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  friend ostream& operator<<(ostream& os, Point p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};
vector<Point<long long> > convexHull(vector<Point<long long> > pts) {
  if (((int)pts.size()) <= 1) return pts;
  sort(pts.begin(), pts.end());
  vector<Point<long long> > h(((int)pts.size()) + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(pts.begin(), pts.end()))
    for (Point<long long> p : pts) {
      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p)) t--;
      h[t++] = p;
    }
  int ini = 0, fim = 0;
  if (t == 2 && h[0] == h[1]) t--;
  for (int i = 0; i < (t); ++i)
    if (h[i] < h[ini]) ini = i;
  for (int i = 0; i < (t); ++i)
    if (h[i] > h[fim]) fim = i;
  cerr << "ini"
       << " == " << ini << ", "
       << "fim"
       << " == " << fim << ", "
       << "t"
       << " == " << t << "\n";
  ;
  vector<Point<long long> > ans;
  while (ini <= fim) {
    ans.push_back(h[ini]);
    if (ini == fim) break;
    ini = (ini + 1) % t;
  }
  return ans;
}
const int N = 200100;
vector<int> G[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  vector<Point<long long> > p;
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (mp.count(pair<int, int>(x, y)))
      G[mp[pair<int, int>(x, y)]].push_back(i);
    else {
      Point<long long> A(x, y);
      A.id = i;
      mp[pair<int, int>(x, y)] = i;
      G[i].push_back(i);
      p.push_back(A);
    }
  }
  p = convexHull(p);
  set<int> S;
  for (auto pp : p)
    for (auto id : G[pp.id]) S.insert(id + 1);
  for (auto it : S) cout << it << " ";
  cout << "\n";
}
