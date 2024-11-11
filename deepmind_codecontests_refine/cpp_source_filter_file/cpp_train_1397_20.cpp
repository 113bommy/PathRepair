#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[105], b[105], c[105];
  int n, k;
  const int mitad = 10000;
  long long pd[2 * mitad];
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) c[i] = a[i] - b[i] * k;
  for (int i = 0; i < 2 * mitad; ++i) pd[i] = -1;
  pd[mitad] = 0;
  for (int i = 1; i <= n; i++) {
    if (c[i] >= 0) {
      for (int j = 2 * mitad; j >= 0; j--)
        if (j + c[i] <= 2 * mitad && pd[j] != -1) {
          pd[j + c[i]] = max(pd[j] + a[i], pd[j + c[i]]);
        }
    } else {
      for (int j = 0; j <= 2 * mitad; j++)
        if (j + c[i] >= 0 && pd[j] != -1)
          pd[j + c[i]] = max(pd[j] + a[i], pd[j + c[i]]);
    }
  }
  if (pd[mitad] == 0)
    cout << -1;
  else
    cout << pd[mitad];
  return 0;
}
