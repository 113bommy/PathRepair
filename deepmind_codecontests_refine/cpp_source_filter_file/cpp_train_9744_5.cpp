#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, d, ans = 0;
  cin >> n >> k;
  while (n--) cin >> d, ans += 2 * (k - 0.5 - d);
  cout << ans;
  return 0;
}
