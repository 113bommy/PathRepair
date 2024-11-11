#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, a, b, inf = 10000000000009, ans = 0, imax, imin;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    if (i == 0) {
      if (b == 1) {
        imax = inf;
        imin = 1900;
      } else {
        imax = 1899;
        imin = -inf;
      }
      imax += a;
      imin += a;
      continue;
    }
    if (imax < imin) {
      cout << "Impossible";
      return 0;
    }
    if (b == 1) {
      if (imax < 1900) {
        cout << "Impossible";
        return 0;
      }
      imin = max(imin, (long long)1900) + a;
      imax += a;
    } else {
      if (imin > 1899) {
        cout << "Impossible";
        return 0;
      }
      imax = min(imax, (long long)1899) + a;
      imin += a;
    }
  }
  if (imax > 2000000000) {
    cout << "Infinity";
    return 0;
  }
  cout << imax;
}
