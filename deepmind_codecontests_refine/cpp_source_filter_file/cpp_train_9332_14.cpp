#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long i, j, k;
  long long a[n], b[m];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  if (a[0] * b[0] > 0) {
    if (a[0] * b[0] > a[n - 1] * b[m - 1]) {
      cout << max(a[1] * b[0], a[n - 1] * b[m - 1]);
    } else {
      cout << max(a[0] * b[0], a[n - 2] * b[m - 1]);
    }
  } else {
    if (a[n - 1] * b[m - 1] < 0)
      cout << min(a[1] * b[m - 1], b[0] * a[n - 2]);
    else
      cout << a[n - 2] * b[m - 1];
  }
}
