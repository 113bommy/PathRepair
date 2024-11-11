#include <bits/stdc++.h>
using namespace std;
long long ans[1000];
signed main() {
  std::ios::sync_with_stdio(false);
  long long n, m, q, i, l, r, x = 0, j;
  cin >> n >> m;
  long long a[n + 4], b[m + 4];
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= m; i++) cin >> b[i];
  for (i = 1; i <= n; i++) x ^= a[i];
  for (i = 1; i <= m; i++) x ^= b[i];
  if (x != 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  if (m >= n) {
    for (i = 1; i < n; i++) {
      for (j = 1; j <= m; j++) {
        if (j == i)
          cout << a[i] << " ";
        else
          cout << 0 << " ";
      }
      cout << endl;
    }
    for (i = 1; i < n; i++) cout << (a[i] ^ b[i]) << " ";
    for (i = n; i <= m; i++) cout << b[i] << " ";
  } else {
    long long curr = 1;
    for (i = 1; i < n; i++) {
      for (j = 1; j <= m; j++) {
        if (j == curr) {
          ans[curr] ^= a[i];
          cout << a[i] << " ";
        } else
          cout << "0 ";
      }
      curr++;
      if (curr == m + 1) curr = 1;
      cout << endl;
    }
    for (i = 1; i <= m; i++) {
      cout << (b[i] ^ ans[i]) << " ";
    }
  }
  return 0;
}
