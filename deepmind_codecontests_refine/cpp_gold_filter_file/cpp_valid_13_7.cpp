#include <bits/stdc++.h>
using namespace std;
char a[128][128];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int kv = n * m / 2 - k;
    if (n % 2 == 1) {
      k -= m / 2;
      if (k < 0) {
        cout << "NO\n";
        continue;
      }
      for (int i = 0; i < m / 2; i++)
        a[n - 1][2 * i] = a[n - 1][2 * i + 1] = ((i & 1) ? 'x' : 'y');
    } else if (m % 2 == 1) {
      kv -= n / 2;
      if (kv < 0) {
        cout << "NO\n";
        continue;
      }
      for (int i = 0; i < n / 2; i++)
        a[2 * i][m - 1] = a[2 * i + 1][m - 1] = ((i & 1) ? 'x' : 'y');
    }
    if ((k & 1) or (kv & 1)) {
      cout << "NO\n";
      continue;
    }
    for (int i = 0; i < n / 2; i++)
      for (int j = 0; j < m / 2; j++) {
        if (k) {
          k -= 2;
          a[2 * i][2 * j] = a[2 * i][2 * j + 1] = (((i + j) & 1) ? 'a' : 'b');
          a[2 * i + 1][2 * j] = a[2 * i + 1][2 * j + 1] =
              (((i + j) & 1) ? 'c' : 'd');
        } else {
          a[2 * i][2 * j] = a[2 * i + 1][2 * j] = (((i + j) & 1) ? 'a' : 'b');
          a[2 * i][2 * j + 1] = a[2 * i + 1][2 * j + 1] =
              (((i + j) & 1) ? 'c' : 'd');
        }
      }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      a[i][m] = 0;
      cout << a[i] << '\n';
    }
  }
  return 0;
}
