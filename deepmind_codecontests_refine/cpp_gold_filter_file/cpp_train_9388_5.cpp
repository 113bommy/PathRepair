#include <bits/stdc++.h>
using namespace std;
const long MaxN = 1e5 + 5;
long a[MaxN];
long a1[MaxN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long i = 0; i < t; i++) {
    long long n, x;
    cin >> n >> x;
    for (long i = 0; i < n; i++) {
      long long tmp, tmp1;
      cin >> a1[i] >> tmp;
      a[i] = a1[i] - tmp;
    }
    long m = -1;
    long M = -1;
    for (long i = 0; i < n; i++) M = max(M, a1[i]);
    for (long i = 0; i < n; i++) m = max(m, a[i]);
    if (m <= 0 && M < x) {
      cout << -1 << endl;
      continue;
    }
    long long res = 0;
    long long nd = M / m;
    if (M >= x) {
      x = 0;
      res += 1;
    } else {
      res += x / m - nd;
      x %= m;
      x += (m * nd);
    }
    while (x > 0) {
      if (M >= x) {
        x = 0;
        res += 1;
      } else {
        res += 1;
        x -= m;
      }
    }
    cout << res << endl;
  }
  return 0;
}
