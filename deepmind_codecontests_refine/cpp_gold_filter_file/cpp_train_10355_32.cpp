#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 3e5 + 10;
long long pow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
long long y[5], m[5];
long long h, a, d;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (long long i = 1; i <= 3; i++) {
    cin >> y[i];
  }
  for (long long i = 1; i <= 3; i++) {
    cin >> m[i];
  }
  cin >> h >> a >> d;
  long long mn = 1e18;
  for (long long i = y[1]; i <= 1000; i++) {
    for (long long j = y[2]; j <= 201; j++) {
      for (long long k = y[3]; k <= 201; k++) {
        long long z = (i - y[1]) * h + (j - y[2]) * a + (k - y[3]) * d;
        if (j <= m[3]) {
          continue;
        } else if (k >= m[2]) {
          mn = min(mn, z);
        } else {
          long long sec_to_take_yong =
              (m[1] / (j - m[3])) + (m[1] % (j - m[3]) != 0);
          long long sec_to_take_m = (i / (m[2] - k)) + (i % (m[2] - k) != 0);
          if (sec_to_take_yong < sec_to_take_m) mn = min(mn, z);
        }
      }
    }
  }
  cout << mn << endl;
}
