#include <bits/stdc++.h>
using namespace std;
constexpr long long INF = 0x1fffffffffffffff;
constexpr int inf = 0x3fffffff;
constexpr double inf_l = 1e18;
constexpr long long MOD = 1000000007LL;
constexpr int mod = 1000000007;
vector<long long> f(100001), w(100001);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> f[i];
  for (int i = 0; i < n; ++i) cin >> w[i];
  int limit = 0;
  while (1LL << limit <= k) ++limit;
  vector<vector<long long>> dps(limit + 1, vector<long long>(n, 0)),
      dpm(limit + 1, vector<long long>(n, INF)),
      dpto(limit + 1, vector<long long>(n, 0));
  for (int i = 0; i < n; ++i) {
    dps[0][i] = w[i];
    dpm[0][i] = w[i];
    dpto[0][i] = f[i];
  }
  for (int i = 1; i <= limit; ++i) {
    for (int j = 0; j < n; ++j) {
      dps[i][j] = dps[i - 1][j] + dps[i - 1][dpto[i - 1][j]];
      dpm[i][j] = min(dpm[i - 1][j], dpm[i - 1][dpto[i - 1][j]]);
      dpto[i][j] = dpto[i - 1][dpto[i - 1][j]];
    }
  }
  vector<int> e;
  for (int i = 0; 1LL << i <= k; ++i) {
    if ((1LL << i) & k) {
      e.emplace_back(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    long long sum = 0, mn = INF;
    int p = i;
    for (int j = 0; j < e.size(); ++j) {
      sum += dps[e[j]][p];
      mn = min(mn, dpm[e[j]][p]);
      p = dpto[e[j]][p];
    }
    cout << sum << ' ' << mn << endl;
  }
}
