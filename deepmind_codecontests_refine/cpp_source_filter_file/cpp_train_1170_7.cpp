#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const long long int mx = 200005;
int main() {
  long long int i, j, k, l, m, q, n, t, x, y;
  cin >> t;
  while (t--) {
    cin >> n >> m >> x >> y;
    string a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long int p = 0;
    long long int q = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (j < m - 1 && (a[i][j] == '.') && (a[i][j + 1] == '.')) {
          q++;
          j = j + 2;
        } else if (a[i][j] == '.') {
          p++;
        }
      }
    }
    long long int ans = 0;
    if ((2 * x) > y)
      ans = (p * x) + (q * y);
    else {
      ans = ((2 * p) + q) * x;
    }
    cout << ans << endl;
  }
  return 0;
}
