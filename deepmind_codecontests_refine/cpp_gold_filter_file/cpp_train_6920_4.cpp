#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const int MOD = 1e9 + 7;
const int N = 100;
int n, m;
int main() {
  int ans = 0;
  cin >> n >> m;
  for (int x = 0; x <= (n + m) / 3; x++) {
    int cn = n - x, cm = m - 2 * x;
    if (cn < 0 || cm < 0) continue;
    ans = max(ans, x + min(cn / 2, cm));
  }
  cout << ans;
}
