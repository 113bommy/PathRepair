#include <bits/stdc++.h>
using namespace std;
int id, sum, n, m, w[501], a[502], k, temp, p[502], tot, x, y, d[501], xx[501];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 1; i <= m; i++) {
    cin >> d[i];
    if (p[d[i]] == 0) a[k++] = d[i], p[d[i]] = 1;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < k; j++) {
      if (a[j] == d[i]) {
        id = j;
        break;
      } else
        sum += w[a[j]];
    }
    for (int j = 0; j < id; j++) xx[j] = a[j];
    a[0] = a[id];
    for (int jj = 1; jj <= id; jj++) {
      a[jj] = xx[jj - 1];
    }
  }
  cout << sum << endl;
  return 0;
}
