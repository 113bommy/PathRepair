#include <bits/stdc++.h>
using namespace std;
int t;
long long x, f[100], ok[100], d[100][2];
int main() {
  cin >> t;
  int i, ci;
  f[1] = 1;
  f[2] = 2;
  for (i = 3; i <= 88; i++) f[i] = f[i - 1] + f[i - 2];
  while (t--) {
    memset(ok, 0, sizeof(ok));
    memset(d, 0, sizeof(d));
    cin >> x;
    for (i = 88; i; i--)
      if (f[i] <= x) {
        ok[i] = 1;
        x -= f[i];
      }
    d[0][0] = 0;
    d[0][1] = 1;
    ci = 0;
    for (i = 1; i <= 88; i++)
      if (ok[i]) {
        d[i][1] = d[ci][0] + d[ci][1];
        d[i][0] = d[ci][1] * (i - ci - 1) / 2 + d[ci][0] * (i - ci) / 2;
        ci = i;
      }
    cout << d[ci][0] + d[ci][1] << "\n";
  }
  return 0;
}
