#include <bits/stdc++.h>
using namespace std;
const long long N = 200001;
int main() {
  long long t;
  cin >> t;
  long long pt[61];
  pt[0] = 1;
  for (long long i = 1; i < 61; i++) pt[i] = pt[i - 1] * 2;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
      string s;
      cin >> s;
      long long x = 0;
      for (long long j = 0; j < m; j++) {
        if (s[j] == '1') {
          x |= pt[m - 1 - j];
        }
      }
      v[i] = x;
    }
    long long k = pt[m] - n;
    long long rq = (k + 1) / 2;
    long long lo = 0, hi = pt[m] - 1;
    long long ans = hi;
    while (lo <= hi) {
      long long mi = (lo + hi) / 2;
      long long cur = mi + 1;
      for (long long i : v) {
        if (i <= mi) cur--;
      }
      if (cur >= rq) {
        ans = mi;
        hi = mi - 1;
      } else
        lo = mi + 1;
    }
    for (long long i = m - 1; i >= 0; i--) {
      long long bit = ans & (1 << i);
      if (bit != 0)
        cout << "1";
      else
        cout << "0";
    }
    cout << endl;
  }
}
