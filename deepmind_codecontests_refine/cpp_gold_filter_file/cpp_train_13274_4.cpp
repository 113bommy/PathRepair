#include <bits/stdc++.h>
using namespace std;
long long k, m, n;
bool a[1000][1000];
long long mx(long long a, long long b) { return a < b ? b : a; }
int main() {
  a[0][0] = 1;
  a[0][1] = 1;
  a[1][0] = 1;
  a[1][1] = 0;
  cin >> k;
  if (k == 0) {
    cout << "+" << endl;
    return 0;
  } else
    for (int i = 2; i <= k; i++) {
      n = 1 << i;
      n /= 2;
      bool b[1000][1000];
      for (int u = 0; u < n; u++)
        for (int y = 0; y < n; y++) b[u][y] = a[u][n - y - 1];
      for (int j = n; j < 2 * n; j++)
        for (int u = 0; u < n; u++) a[j][u] = a[j - n][u];
      for (int j = 0; j < n; j++)
        for (int u = n; u < 2 * n; u++) a[j][u] = !b[j][u - n];
      for (int j = n; j < 2 * n; j++)
        for (int u = n; u < 2 * n; u++) a[j][u] = b[j - n][u - n];
    }
  for (int i = 0; i < (1 << k); i++) {
    for (int j = 0; j < (1 << k); j++) cout << (a[i][j] == 0 ? '+' : '*');
    cout << endl;
  }
  return 0;
}
