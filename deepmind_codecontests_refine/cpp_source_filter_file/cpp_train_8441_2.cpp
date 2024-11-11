#include <bits/stdc++.h>
const long long INF = 1e18L + 1;
const int IINF = 1e9 + 1;
using namespace std;
template <class TH>
void _dbg(const char* sdbg, TH h) {
  cerr << sdbg << '=' << h << endl;
}
template <class TH, class... TA>
void _dbg(const char* sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << '=' << h << ',';
  _dbg(sdbg + 1, a...);
}
static bool whateverb;
const long long eps = 1e-12;
bool eq(long long r1, long long r2) { return abs(r1 - r2) < eps; }
bool eq(complex<long long> c1, complex<long long> c2) {
  return eq(c1.real(), c2.real()) and eq(c1.imag(), c2.imag());
}
long long dot(complex<long long> c1, complex<long long> c2) {
  return c1.real() * c2.real() + c1.imag() * c2.imag();
}
long long det(complex<long long> c1, complex<long long> c2) {
  return c1.real() * c2.imag() - c1.imag() * c2.real();
}
bool an_cmp(const complex<long long>& c1, const complex<long long>& c2) {
  bool b1 = (c1.real() > 0) || (c1.real() == 0 && c1.imag() > 0);
  bool b2 = (c2.real() > 0) || (c2.real() == 0 && c2.imag() > 0);
  if (b1 == b2)
    return det(c1, c2) > 0;
  else
    return b1 > b2;
}
const int N = 2000;
complex<long long> pts[N + 1], c_pts[N + 1];
int n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long i = (long long)0; i < (long long)n; i++) {
    long long t1, t2;
    cin >> t1 >> t2;
    pts[i] = complex<long long>(t1, t2);
  }
  int res = 0;
  for (long long i = (long long)0; i < (long long)n; i++) {
    for (long long j = (long long)0; j < (long long)n; j++) {
      c_pts[j] = pts[j];
    }
    swap(c_pts[i], c_pts[n - 1]);
    for (long long j = (long long)0; j < (long long)n - 1; j++) {
      c_pts[j] -= c_pts[n - 1];
    }
    sort(c_pts, c_pts + n - 1, an_cmp);
    int k = 0;
    for (long long j = (long long)0; j < (long long)n - 1; j++) {
      while (det(c_pts[j], c_pts[(k + 1) % (n - 1)]) > 0) {
        k++;
      }
      long long c1 = k - j, c2 = n - 1 - (k - j) - 1;
      res += c1 * (c1 - 1) / 2 * c2 * (c2 - 1) / 2;
      (j, k, c_pts[j], c_pts[k % (n - 1)], c1, c2, res);
      if (k == j) {
        k++;
      }
    }
  }
  (res);
  cout << res / 2 << "\n";
  return 0;
}
