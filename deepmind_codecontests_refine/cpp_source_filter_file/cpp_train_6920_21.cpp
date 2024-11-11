#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 9;
const long long N = 500500;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  cout << fixed;
  int n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (m >= 2 * n) {
    cout << n << '\n';
    return 0;
  }
  int ans = m - n, rem = 2 * n - m;
  if (rem % 3 == 0) {
    ans += (rem / 3) * 2;
  } else if (rem % 3 == 1) {
    ans += (rem / 3) * 2;
  } else
    ans += (rem - 2 / 3) * 2 + 1;
  cout << ans << '\n';
  return 0;
}
