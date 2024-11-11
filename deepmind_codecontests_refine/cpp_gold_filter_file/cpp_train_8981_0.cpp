#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, i, j, m, p, s, k;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    p = INT_MAX, k = 0, s = 0;
    long long a[n][m];
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] < 0) {
          a[i][j] = a[i][j] * -1;
          k++;
        }
        s = s + a[i][j];
        p = min(p, a[i][j]);
      }
    }
    if (k % 2 != 0) s = s - (p * 2);
    cout << s << endl;
  }
  return 0;
}
