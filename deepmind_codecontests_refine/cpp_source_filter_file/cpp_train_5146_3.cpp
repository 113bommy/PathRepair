#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
using pii = pair<long long, long long>;
void xmax(long long& a, long long b) { a = max(a, b); }
void xmin(long double& a, long double b) { a = min(a, b); }
void print(vc<long long>& a, string second) {
  cerr << "prinitng " << second << ": ";
  for (long long i = 0; i < a.size(); i++) {
    cerr << a[i] << " ";
  }
  cerr << endl;
}
long double sump = 0, sumq = 0, sumq2 = 0, sump2 = 0;
long long m;
long double n;
long double calc_val(long double x, long double y) {
  return x * (n * x - 2 * sump) + sump2 + y * (n * y - 2 * sumq) + sumq2;
}
vc<long double> a, b;
long double ccw(long double a, long double b, long double c, long double d) {
  return a * d - b * c;
}
bool inside(long double x, long double y) {
  for (long long i = 0; i < m; i++) {
    if (ccw(a[i] - x, b[i] - y, a[i] - a[(i + 1) % m], b[i] - b[(i + 1) % m]) <
        0)
      return false;
  }
  return true;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vc<long double> p(n);
  vc<long double> q(n);
  for (long long i = 0; i < n; i++) {
    cin >> p[i] >> q[i];
  }
  cin >> m;
  a = vc<long double>(m);
  b = vc<long double>(m);
  for (long long j = 0; j < m; j++) {
    cin >> a[j] >> b[j];
  }
  long double mini = 1e18;
  for (long long i = 0; i < n; i++) {
    sump += p[i];
    sumq += q[i];
    sump2 += p[i] * p[i];
    sumq2 += q[i] * q[i];
  }
  for (long long i = 0; i < m; i++) {
    xmin(mini, calc_val(a[i], b[i]));
  }
  for (long long i = 0; i < m; i++) {
    if (a[i] == a[(i + 1) % m]) {
      long double x = a[i];
      long double y = sumq / n;
      if ((b[i] < y && y < b[(i + 1) % m]) || (b[(i + 1) % m] < y && y < b[i]))
        xmin(mini, calc_val(x, y));
      continue;
    }
    long double mm = (b[i] - b[(i + 1) % m]) / (a[i] - a[(i + 1) % m]);
    long double c = b[i] - mm * a[i];
    if (mm == -1) continue;
    long double x = (sump + mm * sumq - n * mm + c) / (n * (mm * mm + 1));
    long double y = mm * x + c;
    if (a[i] < x && x < a[(i + 1) % m] || a[(i + 1) % m] < x && x < a[i])
      xmin(mini, calc_val(x, y));
  }
  long double x = sump / n;
  long double y = sumq / n;
  cerr << x << " " << y << endl;
  if (inside(x, y)) xmin(mini, calc_val(x, y));
  cout << setprecision(10) << mini << "\n";
}
