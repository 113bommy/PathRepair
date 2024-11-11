#include <bits/stdc++.h>
using namespace std;
long long a[200002];
signed main() {
  long long n;
  cin >> n;
  long long b[(long long)(n / 2 + 4)];
  long long i, j, k;
  for (i = 1; i <= n / 2; ++i) cin >> b[i];
  long long c = 0, m = 0;
  for (i = 1; i <= n / 2 - 1; ++i) {
    j = n - i + 1;
    if (b[i] >= b[i + 1]) {
      a[i] += a[i - 1];
      a[j] = b[i] - a[i];
    } else {
      a[i] += a[i - 1];
      a[j] = b[i] - a[i];
      m = b[i + 1] - b[i];
      a[i + 1] += m;
    }
  }
  i = n / 2;
  a[i] += a[i - 1];
  a[i + 1] = b[i] - a[i];
  if (i > 2 && a[i + 1] > a[i + 2]) {
    k = a[i + 1] - a[i + 2];
    a[i + 1] -= k;
    a[i] += k;
  }
  for (i = 1; i <= n; ++i) cout << a[i] << " ";
  return 0;
}
