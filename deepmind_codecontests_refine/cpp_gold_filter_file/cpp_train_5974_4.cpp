#include <bits/stdc++.h>
using namespace std;
long long a[100001], b[100001], n, m, i, j, k, p, q, l, r;
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  p = n;
  for (i = 1; i <= n; i++) {
    if (b[i] == 0) {
      k = m * a[i];
      l = i + 1;
      r = n + 1;
      while (l < r - 1) {
        q = (l + r) / 2;
        if (a[q] > k)
          r = q;
        else
          l = q;
      }
      if (a[l] == k) {
        p--;
        b[l] = 1;
      }
    }
  }
  cout << p;
  return 0;
}
