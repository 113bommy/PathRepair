#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, m, n, q, p;
int a[105][105], b[105];
int main() {
  cin >> n;
  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j) cin >> a[i][j];
  for (i = 0; i < n; ++i) {
    k = 0;
    for (j = 0; j < n; ++j) {
      if (a[i][j] != 2 && a[i][j] != 3) k++;
    }
    if (k == n) m++, b[i] = 1;
  }
  cout << m << endl;
  for (i = 0; i < n; ++i)
    if (b[i] == 1) cout << i + 1 << " ";
  return 0;
}
