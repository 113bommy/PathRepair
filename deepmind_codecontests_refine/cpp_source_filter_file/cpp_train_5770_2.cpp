#include <bits/stdc++.h>
using namespace std;
long a[1004];
int main() {
  long n, k, l, r, total, sumk, i, sum = 0, remaining;
  cin >> n >> k >> l >> r >> total >> sumk;
  if (total == n * r) {
    for (i = 0; i < n; i++) cout << r << " ";
    return 0;
  }
  for (i = 0; i < n; i++) a[i] = l;
  for (i = 0; i < k; i++) a[i] = r;
  sum = k * r;
  while (sum != sumk) {
    for (i = k - 1; i >= 0; i--) {
      a[i]--;
      sum--;
      if (sum == sumk) break;
    }
  }
  sum += n - k;
  while (sum != total) {
    for (i = k; i < n; i++) {
      a[i]++;
      sum++;
      if (sum == total) break;
    }
  }
  for (i = 0; i < n; i++) cout << a[i] << " ";
}
