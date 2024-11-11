#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[105], n, ans = 0, t, c = 0;
  cin >> n >> t;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0, j = n - 1;;) {
    c++;
    if (c > n) break;
    if (a[i] <= t && a[j] <= t) {
      ans += 2;
      i++;
      j--;
    } else if (a[j] <= t) {
      ans++;
      --j;
    } else if (a[i] <= t) {
      ans++;
      i++;
    } else
      break;
  }
  cout << ans << endl;
}
