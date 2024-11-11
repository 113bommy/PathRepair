#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 100, m, n, i, j, k, cost, mn;
  while (t--) {
    cin >> m;
    int q[m];
    mn = INT_MAX;
    for (i = 0; i < m; i++) {
      cin >> q[i];
      mn = min(q[i], mn);
    }
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    cost = 0;
    for (i = n - 1; i >= 0;) {
      for (j = i, k = 0; k < mn && j >= 0; k++, j--) {
        cost += a[j];
      }
      j -= 2;
      i = j;
    }
    cout << cost << "\n";
  }
  return 0;
}
