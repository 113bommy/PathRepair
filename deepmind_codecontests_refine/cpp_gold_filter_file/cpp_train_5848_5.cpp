#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[16];
int n, f[1 << 15][226][4], t;
const int MOD = 1e9 + 7;
void solve() {
  for (int i = 0; i < n; ++i) f[1 << i][a[i + 1].first][a[i + 1].second] = 1;
  for (int mask = 1; mask < (1 << n); ++mask)
    for (int time = 0; time <= t; ++time)
      for (int x = 1; x <= n; ++x)
        if (((mask >> (x - 1)) & 1) == 1)
          for (int j = 1; j < 4; ++j)
            if (j != a[x].second && time >= a[x].first)
              f[mask][time][a[x].second] =
                  (f[mask][time][a[x].second] +
                   f[mask ^ (1 << (x - 1))][time - a[x].first][j]) %
                  MOD;
}
void output() {
  long long sum = 0;
  for (int mask = 1; mask < (1 << n); ++mask)
    for (int j = 1; j < 4; ++j) sum = (sum + f[mask][t][j] % MOD) % MOD;
  cout << sum;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> t;
  for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
  solve();
  output();
  return 0;
}
