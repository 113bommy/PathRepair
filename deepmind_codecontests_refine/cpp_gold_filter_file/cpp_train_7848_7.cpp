#include <bits/stdc++.h>
using namespace std;
;
struct _dbg {
  template <class T>
  _dbg& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  };
};
_dbg _d;
long long a[100100], N, s;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; };
int main() {
  cin >> N;
  for (int i = 0, _i = (N); i < _i; ++i) cin >> a[i];
  sort(a, a + N);
  for (int i = (1), _i = (N); i < _i; ++i)
    s += (a[i] - a[i - 1]) * i * (N - i) * 2;
  for (int i = 0, _i = (N); i < _i; ++i) s += a[i];
  auto g = gcd(s, N);
  cout << s / g << ' ' << N / g << endl;
};
