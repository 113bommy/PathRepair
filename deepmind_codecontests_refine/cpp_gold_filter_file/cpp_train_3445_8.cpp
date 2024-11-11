#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long a[n], b[m];
  long long x = 0, y = 0;
  for (long long i = 0; i < n; i++) cin >> a[i], x ^= a[i];
  for (long long i = 0; i < m; i++) cin >> b[i], y ^= b[i];
  if (x != y) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    long long ans[n][m];
    memset(ans, 0, sizeof(ans));
    long long X = 1e9;
    ;
    for (int i = 0; i < n; i++) {
      if (i == n - 1) {
        for (int j = 0; j < m; j++) ans[i][j] = b[j];
        continue;
      }
      for (int j = 0; j + 1 < m; j++) {
        long long p = rand();
        ans[i][j] = (p * 2 * (X - 1)) % X;
        a[i] ^= ans[i][j];
        b[j] ^= ans[i][j];
      }
      ans[i][m - 1] = a[i];
      b[m - 1] ^= ans[i][m - 1];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << ans[i][j] << " ";
      cout << "\n";
    }
  }
  return 0;
}
