#include <bits/stdc++.h>
using namespace std;
int n, a, ans;
int main() {
  cin >> n;
  int sq;
  ans = 1e9;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a < 0) {
      ans = min(ans, a);
      continue;
    }
    sq = sqrt(a);
    if (sq * sq != a) {
      ans = min(ans, a);
    }
  }
  cout << ans << endl;
  return 0;
}
