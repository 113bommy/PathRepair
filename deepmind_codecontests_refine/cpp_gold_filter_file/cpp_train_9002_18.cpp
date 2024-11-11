#include <bits/stdc++.h>
const int maxn = (int)1e2 + 100;
const int mod = (int)1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, ans = 0;
  cin >> n;
  int x, y, x1, y1;
  while (n--) {
    cin >> x >> y >> x1 >> y1;
    ans += ((x1 - x + 1) * (y1 - y + 1));
  }
  cout << ans;
  return 0;
}
