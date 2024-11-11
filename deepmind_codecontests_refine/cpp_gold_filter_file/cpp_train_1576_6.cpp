#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double n, k, i, j, mx = 0, t, e, m, x, ans, r;
  cin >> n >> r;
  x = (2 * 3.141592653589793) / (n);
  ans = (r / (sqrt(2 / (1 - cos(x))) - 1));
  cout << fixed << setprecision(7) << ans;
}
