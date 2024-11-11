#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 5;
const long double EPS = 1e-18;
const long long INF = 1e18 + 7;
const long double PI = 3.14159265358979323;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  for (; t; t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (long long i = 0; i < n; i++) cin >> b[i];
    sort(b.begin(), b.end());
    long long sa = 0, sb = 0;
    long long i = n - 1, j = n - 1;
    bool p = 1;
    for (; i >= 0 && j >= 0;) {
      if (p) {
        p = 0;
        if (a[i] >= b[j]) {
          sa += a[i];
          i--;
        } else
          j--;
      } else {
        p = 1;
        if (a[i] <= b[j]) {
          sb += b[j];
          j--;
        } else
          i--;
      }
    }
    if (!p)
      i--;
    else
      j--;
    while (i >= 0) {
      sa += a[i];
      i -= 2;
    }
    while (j >= 0) {
      sb += b[j];
      j -= 2;
    }
    cout << sa - sb << "\n";
  }
  return 0;
}
