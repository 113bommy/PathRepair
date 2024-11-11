#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int mod = 1e9 + 7;
const long long N = 2e5 + 5, K = 105;
const long long oo = 1e18 + 5;
const int si = (1 << 20);
const int INF = (1 << 30);
const long long M = 1e3 + 5;
const double INFdb = 1e10;
struct Point {
  long long x, y;
  Point() { this->x = this->y = 0; }
  Point(long long x, long long y) : x(x), y(y) {}
  Point operator-(const Point& b) const {
    return Point(this->x - b.x, this->y - b.y);
  }
  long long operator*(const Point& a) const {
    return this->x * a.y - this->y * a.x;
  }
  bool isUpper() const { return y > 0 || (y == 0 || x > 0); }
};
Point a[N];
bool cmp(const Point& a, const Point& b) {
  if (a.isUpper() != b.isUpper()) return a.isUpper();
  return (a * b) > 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  long long ans = 0;
  long long choose4 = 1ll * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
  for (int i = 1; i <= n; ++i) {
    vector<Point> p;
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      p.push_back(a[j] - a[i]);
    }
    sort((p).begin(), (p).end(), cmp);
    int sizee = p.size();
    for (int j = 0; j < sizee; ++j) {
      p.push_back(p[j]);
    }
    long long num = 0;
    for (int k = 0, d = 0; k < sizee; ++k) {
      if (d <= k) d = k + 1;
      while (p[k] * p[d] > 0) ++d;
      int diff = d - k;
      num += 1ll * (diff - 1) * (diff - 2) * (diff - 3) / 6;
    }
    ans += (choose4 - num);
  }
  cout << ans;
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
