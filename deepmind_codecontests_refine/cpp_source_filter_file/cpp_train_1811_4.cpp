#include <bits/stdc++.h>
using namespace std;
int T, J, m, n, i, I, j, k, s, A, d, dd, ds, dp, l, r, K, K0, x, y, first,
    second, xx, yy;
int a[1000111];
int b[10000];
bool c[1000111];
bool F(int x) {
  bool R = 1;
  int kk = 0;
  for (j = 1; j <= n; j++) {
    if (c[a[j] % x]) kk++;
    c[a[j] % x] = 1;
  }
  for (j = 1; j <= n; j++) c[a[j] % x] = 0;
  return (kk <= k);
}
int main() {
  cin >> n >> k;
  if (n - 1 <= k) {
    cout << 1 << endl;
    return 0;
  }
  for (i = 1; i <= n; i++) cin >> b[i];
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++) a[abs(b[i] - b[j])]++;
  for (i = 2; i <= 1000000; i++)
    for (j = 2; j * i <= 1000000; j++) a[i] += a[i * j];
  for (i = 2; i <= 1000000; i++)
    if (a[i] <= k * (k + 1) / 2)
      if (F(i)) {
        cout << i << endl;
        return 0;
      }
  return 0;
}
