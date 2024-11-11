#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, i, j, k = 0, c;
  cin >> n;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  cin >> t;
  sort(a, a + n);
  for (i = 0; i < n - 1; i++) {
    c = 0;
    for (j = i; j <= n - 1; j++)
      if (abs(a[i] - a[j]) <= t) {
        c += 1;
        if (c > k) k = c;
      }
  }
  cout << k << "\n";
}
