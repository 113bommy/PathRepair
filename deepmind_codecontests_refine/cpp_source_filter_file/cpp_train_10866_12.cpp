#include <bits/stdc++.h>
using namespace std;
int d[100005][17], a[100005], up[100005], down[100005];
int query(int l, int r) {
  int k = 0;
  while (2 * (1 << k) < r - l + 1) {
    k++;
  }
  return max(d[l][k], d[r - (1 << k) + 1][k]);
}
int main() {
  int i, j, k, l, n, m;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[0] = 0;
  a[n + 1] = 1000000005;
  ;
  up[0] = up[n] = down[0] = down[n] = 0;
  for (i = 1; i <= n; i++) {
    if (a[i] < a[i - 1]) {
      up[i] = 1;
    } else {
      up[i] = up[i - 1] + 1;
    }
  }
  for (i = n; i >= 1; i--) {
    if (a[i] < a[i + 1]) {
      down[i] = 1;
    } else {
      down[i] = down[i + 1] + 1;
    }
  }
  for (i = 1; i <= n; i++) {
    d[i][0] = up[i] + down[i];
  }
  k = 0;
  while ((1 << k) < n) {
    k++;
  }
  for (i = 1; i <= k; i++) {
    for (j = 1; j <= n - (1 << i) + 1; j++) {
      d[j][i] = max(d[j][i - 1], d[j + (1 << (i - 1))][i - 1]);
    }
  }
  for (i = 1; i <= m; i++) {
    cin >> j >> k;
    if (query(j, k) - up[j] - down[k] >= k - j - 1) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
