#include <bits/stdc++.h>
using namespace std;
const int MaxN = 301;
int n, T, a[MaxN], bit[MaxN], ans, res, f[MaxN];
void update(int x, int v) {
  for (; x <= n; x += x & -x) {
    bit[x] = max(bit[x], v);
  }
}
int query(int x) {
  int res = 0;
  for (; x > 0; x &= x - 1) res = max(res, bit[x]);
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> T;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int j = 1; j <= min(n, T); j++) {
    for (int i = 1; i <= n; i++) {
      f[i] = query(a[i]) + 1;
      update(a[i], f[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    ans = max(ans, f[i]);
  }
  if (n >= T) {
    cout << ans;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    f[i] = query(a[i]) + 1;
    update(a[i], f[i]);
    res = max(res, f[i]);
  }
  cout << ans + (T - n) * (res - ans);
  return 0;
}
