#include <bits/stdc++.h>
using namespace std;
int cnt[100005];
int main() {
  int n, i, a, mx1 = 0, mx2 = 0, ans = 10000000;
  cin >> n;
  fill(cnt, cnt + 100005, 0);
  for (i = 0; i < n; i++) {
    cin >> a;
    if (a <= mx1) ans = min(ans, a);
    if (a < mx1 && a > mx2) cnt[mx1]++;
    if (a > mx1) {
      mx2 = mx1;
      mx1 = a;
    } else if (a > mx2)
      mx2 = a;
  }
  if (ans == 10000000) ans = 1;
  mx1 = 1;
  for (i = 1; i <= n; i++) {
    if (cnt[i] > mx1) {
      ans = i;
      mx1 = cnt[i];
    }
  }
  cout << ans << endl;
  return 0;
}
