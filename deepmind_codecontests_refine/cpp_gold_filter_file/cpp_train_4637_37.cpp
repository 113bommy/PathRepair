#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1.0);
long double fRand(long double fMin, long double fMax) {
  long double f = (long double)rand() / RAND_MAX;
  return fMin + f * (fMax - fMin);
}
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
struct pt {
  long double x, y, z;
  pt operator+(pt p) { return {x + p.x, y + p.y, z + p.z}; }
  pt operator-(pt p) { return {x - p.x, y - p.y, z - p.z}; }
  pt operator*(long double k) { return {x * k, y * k, z * k}; }
  pt operator/(long double k) { return {x / k, y / k, z / k}; }
  friend istream& operator>>(istream& is, pt& p) {
    is >> p.x >> p.y >> p.z;
    return is;
  }
  friend ostream& operator<<(ostream& os, const pt& p) {
    os << p.x << " " << p.y << " " << p.z;
    return os;
  }
};
long double mag(pt v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }
const int MAXN = 1e4 + 5;
const long double oo = 1e9 + 7;
const long double EPS = 1e-9;
int n;
pt s[MAXN], p, ans;
long double vp, vs, len[MAXN], sumT;
bool Check(long double x) {
  long double curX = x;
  pt posS = s[n];
  for (int i = (0); i <= (n - 1); ++i) {
    long double t = len[i] / vs;
    if (t < curX)
      curX -= t;
    else {
      posS = s[i] + (s[i + 1] - s[i]) * curX / t;
      break;
    }
  }
  if (mag(posS - p) < x * vp + EPS) {
    ans = posS;
    return true;
  }
  return false;
}
int main() {
  cin >> n;
  for (int i = (0); i <= (n); ++i) cin >> s[i];
  cin >> vp >> vs;
  cin >> p;
  for (int i = (0); i <= (n - 1); ++i) {
    len[i] = mag(s[i] - s[i + 1]);
    sumT += len[i] / vs;
  }
  long double lo = 0, hi = sumT, res = oo;
  for (int iter = (0); iter <= (100); ++iter) {
    long double mid = (lo + hi) / 2;
    if (Check(mid))
      res = hi = mid;
    else
      lo = mid;
  }
  if (res == oo)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    cout << setprecision(69) << res << endl;
    cout << ans << endl;
  }
  return 0;
}
