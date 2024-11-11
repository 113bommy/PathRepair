#include <bits/stdc++.h>
using namespace std;
const int nax = 2 * (int)1e5 + 10;
const int INF = (int)1e9 + 47;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, a, b, c, d;
    cin >> n >> m >> a >> b >> c >> d;
    int ans = INF;
    if (a <= c) ans = min(ans, c - a);
    if (b <= d) ans = min(ans, d - b);
    if (a > c) ans = min(ans, (n - a) + (n - c));
    if (b > d) ans = min(ans, (m - b) + (m - d));
    cout << ans << '\n';
  }
}
