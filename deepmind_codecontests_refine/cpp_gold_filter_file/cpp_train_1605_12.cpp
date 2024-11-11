#include <bits/stdc++.h>
using namespace std;
int preSum[100005], endSum[100005], a[100005], n;
void init() {
  int i;
  preSum[0] = 0;
  for (i = 1; i <= n; i++) {
    preSum[i] = preSum[i - 1] + a[i];
  }
  endSum[n + 1] = 0;
  for (i = n; i > 0; i--) {
    endSum[i] = endSum[i + 1] + a[i];
  }
}
int main() {
  int l, r, ql, qr, i, mini, ans;
  cin >> n >> l >> r >> ql >> qr;
  for (i = 1; i <= n; i++) cin >> a[i];
  init();
  mini = 1000000000;
  for (i = 0; i <= n; i++) {
    ans = l * preSum[i] + r * endSum[i + 1];
    if (i > n - i) ans += (ql * (2 * i - n - 1));
    if (n - i > i) ans += (qr * (n - i - i - 1));
    mini = min(ans, mini);
  }
  cout << mini;
  return 0;
}
