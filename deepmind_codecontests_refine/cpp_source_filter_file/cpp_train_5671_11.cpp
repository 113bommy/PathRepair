#include <bits/stdc++.h>
using namespace std;
long long a[2000000], us[2000000], m;
int main() {
  long long n, t, s, q, x, y, i, ans = -1;
  cin >> n >> m >> t >> q;
  x = 0, y = 0;
  for (i = 1; i <= n; i++) {
    a[x] = y;
    x += t, y += q;
    x %= n, y %= n;
  }
  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    t = (a[x] - y + n) % n;
    us[t]++;
    if (ans < us[t]) ans = us[t], s = t;
  }
  cout << 0 << ' ' << s;
}
