#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, l, n, k, c, c2, count, m, x, y, f, i, j, r, z, d, p, s;
  cin >> n;
  long long int a[2 * n];
  for (long long int i = 0; i < 2 * n; i++) cin >> a[i];
  l = 0;
  for (i = 0; i < 2 * n; i += 2) {
    s = 0;
    if (a[i] != a[i + 1]) {
      z = a[i + 1];
      for (j = i + 1; j < 2 * n; j++) {
        if (z != a[i]) {
          s++;
          p = a[j + 1];
          a[j + 1] = z;
          z = p;
        } else {
          a[i + 1] = z;
          break;
        }
      }
    }
    l += s;
  }
  cout << l << "\n";
  return 0;
}
