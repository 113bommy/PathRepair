#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  ll x, y, m, cnt, ans = -1;
  cin >> x >> y >> m;
  if (x >= m || y >= m) {
    ans = 0;
    cout << ans << endl;
    return 0;
  } else if (x > 0 || y > 0) {
    ans = 0;
    while (x < m || y < m) {
      if (x > y) swap(x, y);
      cnt = (y - x) / y;
      if (cnt < 1) cnt = 1;
      x += cnt * y;
      ans += cnt;
    }
    cout << ans << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
