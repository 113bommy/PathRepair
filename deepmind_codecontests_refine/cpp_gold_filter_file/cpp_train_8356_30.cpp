#include <bits/stdc++.h>
using namespace std;
int f[1100], ans[10], pre[1100], t, n;
int main() {
  cin >> t;
  for (int o = 1; o <= t; o++) {
    cin >> n;
    memset(f, 0, sizeof f);
    f[0] = 1;
    memset(ans, 0, sizeof ans);
    for (int i = 3; i <= n; i++) {
      if (i >= 3 && f[i - 3]) f[i] = f[i - 3], pre[i] = 3;
      if (i >= 5 && f[i - 5]) f[i] = f[i - 5], pre[i] = 5;
      if (i >= 7 && f[i - 7]) f[i] = f[i - 7], pre[i] = 7;
    }
    if (!f[n]) {
      cout << -1 << endl;
      continue;
    }
    int now = n;
    while (now) {
      ans[pre[now]]++;
      now -= pre[now];
    }
    cout << ans[3] << ' ' << ans[5] << ' ' << ans[7] << endl;
  }
}
