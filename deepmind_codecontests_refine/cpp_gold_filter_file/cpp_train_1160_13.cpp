#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
const char E = '\n';
const int N = 105;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll x, y = 0, n, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x >= y) {
      ans += (x - y) * (n - x + 1);
    } else {
      ans += (y - x) * x;
    }
    y = x;
  }
  cout << ans;
  return 0;
}
