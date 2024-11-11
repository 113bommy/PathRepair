#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x, p, q, ans = 0, cnt = 0;
  ;
  cin >> n >> k >> x;
  int a[n + 5];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << k << endl;
    return 0;
  }
  for (int i = n; i > 1; i--) {
    if (a[i] >= a[i - 1] && cnt < k) {
      cnt++;
      ans += x;
    } else
      ans += a[i];
  }
  if (cnt < k && a[1] <= a[2])
    cnt += x;
  else
    ans += a[1];
  cout << ans << endl;
}
