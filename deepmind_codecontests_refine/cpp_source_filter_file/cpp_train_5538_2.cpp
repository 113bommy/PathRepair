#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
const long long INF = 1e18;
const long long inf = -1e18;
const long long MOD = 1e9 + 7;
const long long base = 1000 * 1000 * 1000;
long long n, m, h, a[N], ans;
void solve() {
  ans = 0;
  cin >> h >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  n++;
  a[n] = INF;
  for (int i = 2; i < n; i += 1) {
    if (a[i] - a[i + 1] + 1 > 2)
      ans++;
    else {
      i++;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
