#include <bits/stdc++.h>
using namespace std;
int n, m, a[101], b[101], z[101], x, s, k, i, j;
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= m; i++) {
    cin >> b[i];
    s += b[i];
  }
  for (i = 1; i <= n - s + 1; i++) {
    for (k = i; k <= i + s - 1; k++) z[a[k]]++;
    for (j = 1; j <= 100; j++)
      if (z[j] != b[j]) {
        x = 1;
        break;
      }
    if (x == 0) {
      cout << "YES";
      return 0;
    }
    x = 0;
    memset(z, 0, 101 * sizeof(int));
  }
  cout << "NO";
  return 0;
}
