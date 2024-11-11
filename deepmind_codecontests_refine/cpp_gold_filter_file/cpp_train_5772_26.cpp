#include <bits/stdc++.h>
using namespace std;
int a[20001][11], b, c, n, m, i, j, k, v[200005], p[200005], q;
int main() {
  cin >> n >> m >> k;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (i = 1; i <= k; i++) {
    cin >> b >> c;
    v[c]++;
    p[b]++;
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (a[i][j] == 1) q += v[j];
    }
    cout << q - p[i] << " ";
    q = 0;
  }
}
