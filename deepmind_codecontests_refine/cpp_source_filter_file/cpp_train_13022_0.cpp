#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, t, f = 0, c = 0, j, i, x = 0, z = 0;
  cin >> n >> m;
  int l, r, a[100];
  for (i = 0; i < 100; i++) {
    a[i] = 0;
  }
  for (i = 0; i < n; i++) {
    cin >> l >> r;
    for (j = l; j <= r; j++) {
      a[j] = -1;
    }
  }
  for (i = 1; i <= m; i++) {
    if (a[i] == 0) c++;
  }
  cout << c << endl;
  for (i = 1; i <= m; i++) {
    if (a[i] == 0) cout << i << " ";
  }
  cout << endl;
}
