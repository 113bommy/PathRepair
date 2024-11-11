#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[7];
  for (int i = 1; i <= 6; ++i) cin >> a[i];
  int ans = abs(a[2] - a[5]) * abs(a[2] - a[5] + 1) / 2;
  for (int i = 1; i < 6; i += 2) ans += 2 * (a[i] * a[i + 1]);
  cout << ans;
  return 0;
}
