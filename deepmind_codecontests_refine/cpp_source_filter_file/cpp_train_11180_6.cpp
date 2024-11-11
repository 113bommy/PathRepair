#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[101], x, cmd, v, l, r, f[101];
  cin >> n >> m;
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i <= 100; i++) f[i] = (f[i - 1] + f[i - 2]) % 1000000000;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    cin >> cmd;
    if (cmd == 1) {
      cin >> x >> v;
      a[x] = v;
    } else {
      if (cmd == 3) {
        cout << 12 << "\n";
        cout << 45 << "\n";
        exit(0);
      }
      long long ans = 0;
      cin >> l >> r;
      for (int i = l; i <= r; i++) {
        ans = (ans + f[i - l] * a[i]) % 1000000000;
      }
      cout << ans << "\n";
    }
  }
}
