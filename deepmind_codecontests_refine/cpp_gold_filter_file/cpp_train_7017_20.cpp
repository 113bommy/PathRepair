#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i;
  cin >> n >> m;
  int a[n + 1];
  int p, q, r;
  for (i = 0; i <= n; i++) a[i] = -1;
  for (int i = 0; i < m; i++) {
    cin >> p >> q >> r;
    if (a[p] != -1) {
      a[q] = (a[p] + 1) % 3;
      a[r] = (a[p] + 2) % 3;
    } else if (a[q] != -1) {
      a[p] = (a[q] + 1) % 3;
      a[r] = (a[q] + 2) % 3;
    } else if (a[r] != -1) {
      a[p] = (a[r] + 1) % 3;
      a[q] = (a[r] + 2) % 3;
    } else {
      a[p] = 0;
      a[q] = 1;
      a[r] = 2;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] + 1 << " ";
  }
  return 0;
}
