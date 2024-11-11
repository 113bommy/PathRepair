#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int now = a[n], ans = a[n];
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] >= now) {
      if (now == 0)
        break;
      else {
        now = now - 1;
        ans += now;
      }
    } else {
      now = a[i];
      ans += a[i];
    }
  }
  cout << ans;
  return 0;
}
