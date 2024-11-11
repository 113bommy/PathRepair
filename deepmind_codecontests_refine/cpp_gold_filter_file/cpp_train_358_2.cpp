#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000000;
int l[1000], c[1000];
int f[1000000];
int a[20];
int o[20];
int main() {
  int n, i, j, k, ans, m, t, p;
  o[0] = 1;
  for (i = 1; i < 20; i++) o[i] = o[i - 1] * 2;
  cin >> n;
  for (i = 0; i < n; i++) cin >> l[i];
  for (i = 0; i < n; i++) cin >> c[i];
  ans = MAX;
  for (i = 0; i < n; i++) {
    t = 0;
    p = l[i];
    for (j = 2; j < sqrt(double(l[i])) + 10; j++)
      if (p % j == 0) {
        a[t++] = j;
        while (p % j == 0) p /= j;
      }
    if (p != 1) a[t++] = j;
    m = o[t] - 1;
    for (j = 0; j < m; j++) f[j] = MAX;
    f[m] = c[i];
    for (j = 0; j < n; j++) {
      p = 0;
      for (k = 0; k < t; k++)
        if (l[j] % a[k] == 0) p += o[k];
      for (k = m; k >= 0; k--)
        if (f[k] + c[j] < f[k & p]) {
          f[k & p] = f[k] + c[j];
        }
    }
    if (f[0] < ans) ans = f[0];
  }
  if (ans == MAX)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
