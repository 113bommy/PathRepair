#include <bits/stdc++.h>
using namespace std;
int ans[600909], v = 0, a[600099], b[600099];
int main() {
  int i, l, r, n, q;
  cin >> n >> q;
  for (i = 0; n > i; i++) cin >> a[i];
  for (i = 0; q > i; i++) {
    cin >> l >> r;
    l--;
    r--;
    b[l]++;
    if (r < n - 1) b[r + 1]--;
  }
  for (i = 0; n > i; i++) {
    v += b[i];
    ans[i] = v;
  }
  long long res = 0;
  sort(a, a + n);
  sort(ans, ans + n);
  for (i = 0; n > i; i++) {
    res += a[i] * 1ll * ans[i];
  }
  cout << res << endl;
  return 0;
}
