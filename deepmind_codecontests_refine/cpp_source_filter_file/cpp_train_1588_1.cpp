#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  ;
  while (t--) {
    long double n;
    cin >> n;
    long double pi = acos(-1), ans = 1, ans1,
                angle = (pi * (2 * n - 2)) / (2 * n),
                cur = (pi * (2 * n - 2)) / (2 * n);
    for (int i = 0; i < (n - 2); i++) {
      ans = sqrt(1 + ans * ans - 2 * ans * cos(cur));
      cur = angle - asin(sin(cur) * (ans1 / ans));
      ans1 = ans;
    }
    cout << fixed << setprecision(30) << ans << '\n';
  }
  return 0;
}
