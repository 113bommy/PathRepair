#include <bits/stdc++.h>
constexpr long long mod = 1e9 + 7;
long long data[2000006][2];
int dlt[2000006];
long long get(int n) {
  if (dlt[n] > 0) {
    return data[n][1];
  } else {
    return data[n][0];
  }
}
void solve() {
  int n;
  std::cin >> n;
  std::cout << ((get(n) * 4LL) % mod) << '\n';
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  data[3][1] = 1;
  dlt[3] = 1;
  data[4][0] = data[4][1] = 1;
  dlt[4] = 0;
  for (int i = 5; i <= (2e6); i++) {
    data[i][1] = (2 * data[i - 2][0]) + data[i - 1][0] + 1;
    {
      int d(-1);
      if (dlt[i - 2] > 0) {
        d += 2 * dlt[i - 1];
      }
      if (dlt[i - 2] > 0) {
        d += dlt[i - 2];
      }
      dlt[i] = d;
    }
    data[i][0] = (2 * get(i - 2)) + get(i - 1);
    data[i][0] %= mod;
    data[i][1] %= mod;
  }
  int t(1);
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
