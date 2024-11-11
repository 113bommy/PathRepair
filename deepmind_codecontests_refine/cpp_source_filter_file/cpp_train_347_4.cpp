#include <bits/stdc++.h>
template <typename T>
T inline SQR(const T &a) {
  return a * a;
}
template <typename T>
T inline ABS(const T &a) {
  return a < 0 ? -a : a;
}
const double EPS = 1e-9;
inline int SGN(double a) {
  return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0)));
}
inline int CMP(double a, double b) { return SGN(a - b); }
using namespace std;
int a[100000];
bitset<100000> _inc, _dec;
bitset<100000> _incr, _decr;
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  _inc[0] = true;
  _dec[0] = true;
  for (int i = 1; i <= n - 1; ++i) {
    _inc[i] = (_inc[i - 1] && (a[i - 1] <= a[i]));
    _dec[i] = (_dec[i - 1] && (a[i - 1] >= a[i]));
  }
  _incr[n - 1] = true;
  _decr[n - 1] = true;
  for (int i = n - 1; i >= 0; --i) {
    _incr[i] = (_incr[i + 1] && (a[i] <= a[i + 1]));
    _decr[i] = (_decr[i + 1] && (a[i] >= a[i + 1]));
  }
  int ii = -1, jj = -1;
  for (int i = 0; i < n - 2; ++i) {
    for (int x = 0; x < 3; ++x)
      for (int y = 0; y < 3; ++y) {
        if (a[i + x] != a[i + y]) {
          swap(a[i + x], a[i + y]);
          bool iin = (a[i] <= a[i + 1]) && (a[i + 1] <= a[i + 2]);
          bool din = (a[i] >= a[i + 1]) && (a[i + 1] >= a[i + 2]);
          if (!iin && !din) {
            ii = i + x + 1, jj = i + y + 1;
            goto hell;
          }
          bool bin = i ? (_inc[i - 1] && (a[i - 1] <= a[i])) : true;
          bool bdc = i ? (_dec[i - 1] && (a[i - 1] >= a[i])) : true;
          bool ain =
              ((i + 3) < n) ? (_incr[i + 3] && a[i + 2] <= a[i + 3]) : true;
          bool adc =
              ((i + 3) < n) ? (_decr[i + 3] && a[i + 2] >= a[i + 3]) : true;
          bool _incrsin = bin && iin && ain;
          bool _decrsin = bdc && din && adc;
          if (!_incrsin && !_decrsin) {
            ii = i + x + 1;
            jj = i + y + 1;
            goto hell;
          }
          swap(a[i + x], a[i + y]);
        }
      }
  }
hell:
  cout << ii;
  if (ii != -1) cout << " " << jj;
  cout << "\n";
  return 0;
}
