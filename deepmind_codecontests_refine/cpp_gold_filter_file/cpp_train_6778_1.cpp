#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;
ll a[N];
signed main(int argc, char const *argv[]) {
  ll n, m;
  cin >> n >> m;
  for (int i = 1; i <= min(n, m); ++i) {
    a[i * i % m] += (n - i) / m + 1;
  }
  ll ans = a[0] * a[0];
  for (int i = 1; i < m; ++i) {
    ans += a[i] * a[m - i];
  }
  cout << ans << endl;
}
