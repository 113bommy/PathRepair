#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int a[20];
int n, l, r, x;
int cnt;
int ans;
void recur(int i, int cc, int sum, int minn, int maxn) {
  if (cc == cnt) {
    if (sum >= l && sum <= r && maxn - minn >= x) ++ans;
    return;
  }
  if (i >= n) return;
  recur(i + 1, cc + 1, sum + a[i], min(minn, a[i]), max(maxn, a[i]));
  recur(i + 1, cc, sum, minn, maxn);
}
int main() {
  cin >> n >> l >> r >> x;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 2; i <= n; ++i) {
    cnt = i;
    recur(0, 0, 0, 1e9, -1e9);
  }
  cout << ans << endl;
  return 0;
}
