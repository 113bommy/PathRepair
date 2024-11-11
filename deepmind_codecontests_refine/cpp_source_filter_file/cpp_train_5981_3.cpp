#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], s = 0, ans = 0, now = 0;
  for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
  s /= n;
  for (int i = 0; i < n; i++) now += a[i] - s, ans += now > 0 ? now : -now;
  cout << ans << endl;
}
