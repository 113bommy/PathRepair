#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const double pie = 2 * acos(0.0);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int total_drink = k * l / nl;
  int total_lime = c * d;
  int total_salt = p / np;
  int ans = min(total_salt, min(total_lime, total_drink));
  cout << ans / n;
  return 0;
}
