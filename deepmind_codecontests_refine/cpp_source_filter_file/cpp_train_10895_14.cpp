#include <bits/stdc++.h>
using namespace std;
int const M = 1e6 + 10, mod = 1e9 + 7;
int ans[M], vis[M], a[M];
vector<int> good;
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  good.push_back(0);
  vis[0] = 1;
  ans[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (!vis[a[i]]) {
      int en = (int)good.size();
      for (int j = 0; j < en; j++)
        good.push_back(good[j] xor a[i]), vis[good[j] xor a[i]] = i;
      ans[i] = ans[i - 1];
    } else {
      ans[i] = ans[i - 1] * 2;
      ans[i] %= mod;
    }
  }
  for (int i = 1; i <= q; i++) {
    int l, x;
    cin >> l >> x;
    if (vis[x] && vis[x] <= l) {
      cout << ans[l] << "\n";
    } else
      cout << 0 << "\n";
  }
}
