#include <bits/stdc++.h>
const long long INF = LLONG_MAX;
using namespace std;
int main() {
  long long n, l, r, test;
  cin >> n;
  vector<long long> a;
  a.resize(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  test = 0;
  long long mi = INF, ma = 0;
  for (long long i = 0; i < n; i++) {
    char cr = '0';
    if (i + 1 != n) cin >> cr;
    if (cr == '1' && (test == 0 || test == 2)) {
      test = 1;
      l = i;
    }
    if ((cr == '0' || i + 1 == n) && test == 1) {
      mi = min(mi, a[i]);
      ma = max(ma, a[i]);
      test = 2;
      r = i;
      if (l != 0) {
        if (a[l - 1] > mi) {
          cout << "NO";
          return 0;
        }
      }
      if (r + 1 != n) {
        if (a[r + 1] < ma) {
          cout << "NO";
          return 0;
        }
      }
      a[r] = ma;
      a[l] = mi;
      mi = INF, ma = 0;
    }
    if (test == 1) {
      mi = min(mi, a[i]);
      ma = max(ma, a[i]);
    }
    if (test == 0 || test == 2) {
      if (test == 2)
        test = 0;
      else if (i - 1 != -1) {
        if (a[i] < a[i - 1]) {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES";
}
