#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int c[n];
  int f[n];
  int mx = 0, ans = 1;
  for (int i = 0; i <= n; i++) {
    c[i] = 0;
    f[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    int col;
    cin >> col;
    c[f[col]]--;
    f[col]++;
    c[f[col]]++;
    mx = mx > f[col] ? mx : f[col];
    int fl = 0;
    if (c[1] == i)
      fl = 1;
    else if (c[i] == 1)
      fl = 1;
    else if (c[1] == 1 && c[mx] * mx == i - 1)
      fl = 1;
    else if (c[mx - 1] * (mx - 1) == i - mx && c[mx] == 1)
      fl = 1;
    if (fl) ans = i;
  }
  cout << ans;
  return 0;
}
