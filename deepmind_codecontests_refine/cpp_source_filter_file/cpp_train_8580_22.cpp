#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j, a[1001], x, ans = 10010;
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    int s = 0, t = i;
    for (j = 1; j <= n; j++) {
      if (a[j] != t) s++;
      t = t + k;
    }
    if (ans > s) {
      x = i;
      ans = s;
    }
  }
  cout << ans << endl;
  int t = x;
  for (i = 1; i <= n; i++) {
    if (a[i] < t)
      cout << "+ " << i << " " << t - a[i] << endl;
    else if (a[i] > t)
      cout << "- " << i << " " << a[i] - t << endl;
    t = t + k;
  }
  return 0;
}
