#include <bits/stdc++.h>
using namespace std;
long long a[200009];
int main() {
  long long i, j, k, l, c, v, b, n, m;
  while (cin >> n >> m) {
    for (i = 1; i <= m; i++) cin >> a[i];
    for (i; i <= n; i++) {
      cin >> a[i];
      a[i] = a[i] + a[i - m];
    }
    k = n - m;
    c = 10000000;
    for (k = k + 1; k <= n; k++) {
      if (a[k] <= c) {
        j = k;
        c = a[k];
      }
    }
    if (j % m == 0)
      j = m;
    else
      j = j % m;
    cout << j << endl;
  }
}
