#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
long long int maxx(long long int a, long long int b) { return a > b ? a : b; }
long long int minn(long long int a, long long int b) { return a > b ? b : a; }
using namespace std;
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1, 0};
int dy[] = {-1, 0, 1, 1, -1, 0, 1, -1, 0};
void boostIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int poww(long long int base, long long int exp) {
  base %= 1000000007;
  long long int result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % 1000000007;
    base = (base * base) % 1000000007;
    exp >>= 1;
  }
  return result;
}
vector<pair<pair<double, double>, pair<double, double>>> p;
double rx, ry, vx, vy;
int n, x, y, x2, y2;
pair<double, double> x_axis() {
  pair<double, double> ret;
  if (vx == 0) {
    return make_pair(0, 1e18);
  } else if (vx > 0) {
    ret.first = (x - rx) / vx;
    ret.second = (x2 - rx) / vx;
  } else {
    ret.first = (x2 - rx) / vx;
    ret.second = (x - rx) / vx;
  }
  return ret;
}
pair<double, double> y_axis() {
  pair<double, double> ret;
  if (vy == 0) {
    return make_pair(0, 1e18);
  } else if (vy > 0) {
    ret.first = (y - ry) / vy;
    ret.second = (y2 - ry) / vy;
  } else {
    ret.first = (y2 - ry) / vy;
    ret.second = (y - ry) / vy;
  }
  return ret;
}
int main() {
  boostIO();
  cin >> n >> x >> y >> x2 >> y2;
  for (int i = 0; i < n; i++) {
    cin >> rx >> ry >> vx >> vy;
    if (vx == 0 && !(x < rx && x2 > rx)) {
      cout << -1 << endl;
      return 0;
    }
    if (vy == 0 && !(y < ry && y2 > ry)) {
      cout << -1 << endl;
      return 0;
    }
    p.push_back(make_pair(x_axis(), y_axis()));
    if ((x < rx && x2 > rx)) p.back().first.first = 0;
    if (y < ry && y2 > ry) p.back().second.first = 0;
  }
  double in = -1e18, out = 1e18;
  for (int i = 0; i < n; i++) {
    in = max(in, max(p[i].first.first, p[i].second.first)),
    out = min(out, min(p[i].first.second, p[i].second.second));
  }
  if (in > out || out <= 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << setprecision(20) << in << endl;
  return 0;
}
