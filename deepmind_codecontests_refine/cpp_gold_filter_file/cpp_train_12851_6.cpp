#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a1, prev, a, i, ans;
  ios::sync_with_stdio(false);
  cin >> n >> m;
  prev = -1;
  for (i = 0; i < n; i++) {
    cin >> a;
    a1 = (a - 1) / m;
    if (a1 > prev) {
      ans = i + 1;
      prev = a1;
    } else if (a1 == prev) {
      ans = (i + 1);
    }
  }
  cout << ans << endl;
  return 0;
}
