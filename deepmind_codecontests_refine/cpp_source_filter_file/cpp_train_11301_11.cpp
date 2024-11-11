#include <bits/stdc++.h>
using namespace std;
int solve() {
  long long l1, r1, l2, r2, k;
  cin >> l1 >> r1 >> l2 >> r2 >> k;
  if (l2 > r1 || r2 < l1) {
    cout << 0;
    return 0;
  }
  long long res = r1 + 1 - max(l2, l1) - (r1 - min(r1, r2));
  if (k >= l2 && k <= min(r1, r2)) res -= 1;
  cout << res;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
