#include <bits/stdc++.h>
using namespace std;
int a[1000000], pre[1000000], suf[1000000];
char st[1000000];
int main() {
  int n, i, j;
  cin >> n;
  int ans = 0;
  pre[0] = 0;
  suf[n + 1] = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
  }
  scanf("%s", st);
  for (i = n; i >= 1; i--) {
    if (st[i - 1] == '1') {
      suf[i] = suf[i + 1] + a[i];
      ans += a[i];
    } else
      suf[i] = suf[i + 1];
  }
  for (i = n; i >= 1; i--) {
    if (st[i - 1] == '1') ans = max(ans, pre[i - 1] + suf[i + 1]);
  }
  cout << ans << endl;
  return 0;
}
