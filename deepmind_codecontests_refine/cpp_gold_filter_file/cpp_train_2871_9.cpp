#include <bits/stdc++.h>
using namespace std;
int a[310000], b[310000];
int main() {
  long long k = 0, count = 0, p, q, z, i = 1, j = 1, m, n, t;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  if (n % 2 == 1) {
    for (i = 1; i < n; i += 2) b[i] = a[i];
    for (i = n - 1; i > -1; k = k + 2, i -= 2) b[k] = a[i];
  }
  if (n % 2 == 0) {
    for (i = 0; i < n; i++) b[i] = a[i];
    for (i = n - 1, k = 0; i >= n / 2; k += 2, i -= 2) std::swap(b[k], b[i]);
  }
  for (i = 0; i < n; i++) cout << b[i] << " ";
  return 0;
}
