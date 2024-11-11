#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
constexpr long long INF = 1e18, MOD = 1000000007, N = 200000;
long long n, m, l, k;
signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> l >> k;
  long long res =
      (n + 2) * (m + 1) + (l + 2) * (k + 1) - n * m - l * k + abs(n - l);
  cout << res;
}
