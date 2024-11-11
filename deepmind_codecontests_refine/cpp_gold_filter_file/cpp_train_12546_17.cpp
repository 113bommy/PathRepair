#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, m = -1, n, k, a[100010], b[100010], sum = 0;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (i = 0; i < n; i++)
    if (a[i] % 2 == 0 && a[i] > 0) sum += a[i];
  for (i = n - 1; i >= 0; i--)
    if (a[i] % 2) b[++m] = a[i];
  k = 0;
  for (i = 0; i <= m; i++)
    if (b[i] > 0) k++;
  if (!(k % 2)) {
    for (i = 0; i <= k - 1; i++) sum += b[i];
    cout << sum << endl;
  } else {
    if (m == k - 1) {
      if (k != 1)
        for (i = 0; i <= k - 2; i++) sum += b[i];
      cout << sum << endl;
    } else {
      if (k != 1)
        for (i = 0; i <= k - 2; i++) sum += b[i];
      if (b[k - 1] + b[k] > 0) sum += b[k - 1] + b[k];
      cout << sum << endl;
    }
  }
  return 0;
}
