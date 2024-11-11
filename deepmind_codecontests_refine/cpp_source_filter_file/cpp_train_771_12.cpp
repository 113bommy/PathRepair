#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
long long b = LLONG_MAX, c = -1, s = 0, sol = 1;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 0ll) {
      if (c >= 0ll) {
        if (b != LLONG_MAX) {
          if ((a[i] - a[c]) % (i - c) == 0ll) {
            if (b != (a[i] - a[c]) / (i - c)) {
              s = i;
              sol++;
              b = LLONG_MAX;
            }
          } else {
            s = i;
            sol++;
            b = LLONG_MAX;
          }
        } else {
          if ((a[i] - a[c]) % (i - c) == 0ll) {
            b = (a[i] - a[c]) / (i - c);
            if (a[i] - (i - s) * b <= 0ll) {
              s = c;
              sol++;
              b = LLONG_MAX;
            }
          } else {
            s = i;
            sol++;
          }
        }
      }
      c = i;
    } else {
      if (b != LLONG_MAX) {
        if (a[c] + (i - c) * b <= 0) {
          b = LLONG_MAX;
          s = i;
          c = -1ll;
          sol++;
        }
      }
    }
  }
  cout << sol;
  return 0;
}
