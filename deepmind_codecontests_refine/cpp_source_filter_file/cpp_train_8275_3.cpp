#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535897932384626433832795;
const double eps = 1e-12;
const int INF = 1 << 30;
const long long LINF = 1ll << 60;
const int BUFFER_SZ = 1 << 20;
const int MOD = 1000 * 1000 * 1000 + 7;
char BUFFER[BUFFER_SZ];
int gi() {
  int x;
  scanf("%d", &x);
  return x;
}
double gd() {
  double x;
  scanf("%lf", &x);
  return x;
}
long long gll() {
  long long x;
  scanf("%lld", &x);
  return x;
}
vector<int> gvi(int n) {
  vector<int> a;
  while (n-- > 0) a.push_back(gi());
  return a;
}
string gs() {
  scanf("%s", BUFFER);
  return string(BUFFER);
}
template <class T>
void print(vector<T> &x, string format) {
  format += "%c";
  for (int i = 0; i < x.size(); ++i)
    printf(format.c_str(), x[i], i + 1 == x.size() ? '\n' : ' ');
}
double solve(double a, double b, double c) {
  double D = b * b - 4.0 * a * c;
  if (D < 0.0) D = 0.0;
  double t1 = (-b - sqrt(D)) / 2.0 / a;
  double t2 = (-b + sqrt(D)) / 2.0 / a;
  if (t1 < 0) return t2;
  if (t2 < 0) return t1;
  return min(t1, t2);
}
void solve() {
  double a = gd();
  double v = gd();
  double l = gd();
  double d = gd();
  double w = gd();
  double t1 = w / a;
  if (w >= v || a * t1 * t1 / 2.0 > d) {
    double t = v / a;
    double s = a * t * t / 2.0;
    if (s < l) {
      l -= s;
      t += l / v;
    } else {
      t = sqrt(2.0 * l);
    }
    printf("%.20lf\n", t);
  } else {
    double res = t1;
    double rem = d - a * t1 * t1 / 2.0;
    double t2 = (v - w) / a;
    double s = a * t2 * t2 / 2.0 + t2 * w;
    if (s > rem / 2.0) {
      double t = solve(a, 2.0 * w, -rem);
      res += 2.0 * t;
    } else {
      res += t2 * t2;
      res += (rem - 2.0 * s) / v;
    }
    if (s > l - d) {
      res += solve(a, 2.0 * w, -2.0 * (l - d));
    } else {
      res += t2;
      res += (l - d - s) / v;
    }
    printf("%.20lf\n", res);
  }
}
int main() {
  solve();
  return 0;
}
