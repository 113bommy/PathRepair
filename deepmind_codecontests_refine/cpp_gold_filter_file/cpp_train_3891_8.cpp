#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, a[100005]{};
  int m, l, r;
  long long c = 0, p;
  cin >> n >> d;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 2; i++) {
    l = 0, r = n - 1, p = 0;
    while (l <= r) {
      m = (l + r) / 2;
      if (a[i] + d >= a[m]) {
        l = m + 1, p = m;
      } else {
        r = m - 1;
      }
    }
    p -= i;
    c += (p) * (p - 1) / 2;
  }
  cout << c << "\n";
  return 0;
}
