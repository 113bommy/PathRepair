#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k, ans;
    cin >> n >> m >> k;
    int x = n / k;
    if (m > x) {
      m = m - x;
      int c = ceil(float(m) / float(k - 1));
      ans = x - c;
    } else
      ans = m;
    cout << ans << endl;
  }
  return 0;
}
