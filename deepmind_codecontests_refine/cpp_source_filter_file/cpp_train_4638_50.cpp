#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2e5 + 10;
const long long MOD = 1e9 + 7;
const long long INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-7;
const long double PI = acos(-1);
bool eq(long double a, long double b) { return fabs(a - b) <= EPS; }
struct point {
  long double x, y, z;
  point(long double x = 0, long double y = 0, long double z = 0)
      : x(x), y(y), z(z) {}
  point operator+(const point &o) const { return {x + o.x, y + o.y, z + o.z}; }
  point operator-(const point &o) const { return {x - o.x, y - o.y, z - o.z}; }
  point operator*(long double t) const { return {x * t, y * t, z * t}; }
  point operator/(long double t) const { return {x / t, y / t, z / t}; }
  bool operator==(const point &o) const {
    return eq(x, o.x) and eq(y, o.y) and eq(z, o.z);
  }
  long double operator*(const point &o) const {
    return x * o.x + y * o.y + z * o.z;
  }
  point operator^(const point &o) const {
    return point(y * o.z - z * o.y, z * o.x - x * o.z, x * o.y - y * o.x);
  }
};
long double norm(point a) { return sqrt(a * a); }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cout << fixed << setprecision(12);
  long long n, vh, vs;
  cin >> n;
  vector<point> p(n + 1);
  point h;
  for (long long i = 0; i < n + 1; i++) cin >> p[i].x >> p[i].y >> p[i].z;
  cin >> vh >> vs;
  cin >> h.x >> h.y >> h.z;
  vector<long double> time(n + 1, 0);
  for (long long i = 1; i < n + 1; i++)
    time[i] = time[i - 1] + norm(p[i] - p[i - 1]) / vs;
  for (long long i = 1; i < n + 1; i++) {
    if (time[i] >= norm(p[i] - h) / vh) {
      cout << "YES\n";
      long long limit = 1e9;
      long long l = 0, r = limit;
      point ans;
      long double ansTime = 0;
      while (l <= r) {
        long long m = (l + r) / 2;
        point pmid = p[i - 1] + (p[i] - p[i - 1]) * m / limit;
        long double midTime = norm(p[i - 1] - pmid) / vs;
        if (time[i - 1] + midTime >= norm(pmid - h) / vh) {
          ansTime = time[i - 1] + midTime;
          ans = pmid;
          r = m - 1;
        } else
          l = m + 1;
      }
      cout << ansTime << '\n';
      cout << ans.x << " " << ans.y << " " << ans.z << '\n';
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
