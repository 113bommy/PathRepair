#include <bits/stdc++.h>
using namespace std;
const int N = 6005;
const double INF = 1e9;
int n;
double q, A, B;
double x[N];
double opt[N];
struct Func {
  double l, r, a, b;
  Func() {}
  Func(double l, double r, double a, double b) : l(l), r(r), a(a), b(b) {}
  pair<double, double> find() {
    pair<double, double> ret;
    ret.second = max(l, min(r, b / a));
    ret.first = ret.second * a - b;
    return ret;
  }
};
struct Vector {
  int sz;
  Func v[N * 2];
  Vector() { sz = 0; }
  void add(Func x) { v[sz++] = x; }
  void clear() { sz = 0; }
};
double find(Vector& der) {
  pair<double, double> ret = make_pair(INF, 0);
  for (int i = 0; i < der.sz; ++i) {
    Func cur = der.v[i];
    pair<double, double> tmp = cur.find();
    if (fabs(tmp.first) < fabs(ret.first)) ret = tmp;
  }
  return ret.second;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> q >> A >> B;
  for (int i = 0; i < n; ++i) cin >> x[i];
  Vector der;
  der.add(Func(1, q, 2, 2 * x[0]));
  for (int i = 1; i < n; ++i) {
    double k = opt[i - 1] = find(der);
    Vector left, right;
    for (int j = 0; j < der.sz; ++j) {
      Func cur = der.v[j];
      if (cur.r < k)
        left.add(cur);
      else if (cur.l > k)
        right.add(cur);
      else {
        left.add(Func(cur.l, k, cur.a, cur.b));
        right.add(Func(k, cur.r, cur.a, cur.b));
      }
    }
    der.clear();
    for (int j = 0; j < left.sz; ++j) {
      Func cur = left.v[j];
      cur.l += A, cur.r += A;
      if (cur.l > q) continue;
      cur.r = min(cur.r, q);
      cur.b += A * cur.a + 2 * x[i];
      cur.a += 2;
      der.add(cur);
    }
    if (k + A <= q) {
      der.add(Func(k + A, min(k + B, q), 2, x[i] * 2));
    }
    for (int j = 0; j < right.sz; ++j) {
      Func cur = right.v[j];
      cur.l += B, cur.r += B;
      if (cur.l > q) continue;
      cur.r = min(cur.r, q);
      cur.b += B * cur.a + 2 * x[i];
      cur.a += 2;
      der.add(cur);
    }
  }
  opt[n - 1] = find(der);
  for (int i = n - 1; i > 0; --i) {
    if (opt[i] - opt[i - 1] < A)
      opt[i - 1] = opt[i] - A;
    else if (opt[i] - opt[i - 1] > B)
      opt[i - 1] = opt[i] - B;
  }
  double res = 0;
  for (int i = 0; i < n; ++i) {
    res += (opt[i] - x[i]) * (opt[i] - x[i]);
  }
  cout << fixed << setprecision(6);
  for (int i = 0; i < n; ++i) {
    cout << opt[i] << ' ';
  }
  cout << '\n' << res;
}
