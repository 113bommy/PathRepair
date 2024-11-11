#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  int t = 0;
  int k, a, p = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> k >> a;
    if (a == 1) k++;
    while (a > 1) {
      a = (a + 3) / 4;
      k++;
    }
    ans = max(ans, k);
  }
  cout << ans;
  return 0;
}
