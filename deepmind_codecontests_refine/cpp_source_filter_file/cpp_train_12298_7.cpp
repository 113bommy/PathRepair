#include <bits/stdc++.h>
using namespace std;
int n, p1, p2, p3, t1, t2, ans = 0;
int l[110], r[110];
int main() {
  cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    ans += p1 * (r[i] - l[i]);
    if (i >= 2) {
      int x = l[i] - r[i - 1];
      if (x <= t1)
        ans += x * p1;
      else if (x <= t2 + t1)
        ans += t1 * p1 + (x - t1) * p2;
      else
        ans += t1 * p1 + t2 * p2 + (x - t1 - t2) * p3;
    }
  }
  cout << ans << endl;
  return 0;
}
