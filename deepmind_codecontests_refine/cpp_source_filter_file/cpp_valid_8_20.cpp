#include <bits/stdc++.h>
using namespace std;
int t, n;
long long fn;
long long f(long long x) { return fabs(fn - 3.0 * x); }
void out_pair(long long x) {
  cout << (int)(fn - 2.0 * x) << ' ' << (int)x << '\n';
  return;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    fn = (long long)n;
    if (n % 3 == 0) {
      out_pair(fn / 3.0);
    } else {
      if (ceil(fn / 3.0) < fn / 2.0) {
        if (f(ceil(fn / 3.0)) < f(floor(fn / 3.0))) {
          out_pair(ceil(fn / 3.0));
        } else
          out_pair(floor(fn / 3.0));
      } else
        out_pair(floor(fn / 3.0));
    }
  }
  return 0;
}
