#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i, j, k, l, n, m;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int p[n], c[n];
    for (i = 0; i < n; i++) cin >> p[i] >> c[i];
    int fl = 1;
    for (i = 0; i < n; i++) {
      if (c[i] > p[i]) {
        fl = 0;
        break;
      }
    }
    for (i = 0; i < n; i++) {
      if (p[i] < p[i - 1] || c[i] < c[i - 1]) {
        fl = 0;
        break;
      }
    }
    for (i = 1; i < n; i++) {
      k = p[i] - p[i - 1];
      l = c[i] - c[i - 1];
      if (k < l) {
        fl = 0;
        break;
      }
    }
    if (fl)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
