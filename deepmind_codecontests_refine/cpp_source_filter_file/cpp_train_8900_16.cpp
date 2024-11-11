#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ma = 0, i, n, k = 1, m = 10000000000, t = 0;
  cin >> n;
  long long a[n], b[n], c[n];
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = n; i >= 1; i--) {
    if (m > a[i]) m = a[i];
    b[i] = m;
  }
  for (i = 1; i <= n; i++) {
    if (ma < a[i]) ma = a[i];
    c[i] = ma;
  }
  for (i = 1; i < n; i++) {
    if (b[i + 1] > c[i]) k++;
  }
  cout << k;
  return 0;
}
