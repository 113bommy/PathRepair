#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  vector<long long> t((size_t)n + 1, 0);
  for (long long i = 1; i <= n; i++) {
    cin >> t[i];
  }
  vector<long double> pre((size_t)n + 1, 0);
  for (long long i = 1, j = 0; i <= n; i++) {
    j += t[i];
    pre[i] = pre[i - 1] + (long double)j / t[i];
  }
  vector<long long> sum = t;
  partial_sum(sum.begin(), sum.end(), sum.begin());
  vector<long double> rev((size_t)n + 1, 0);
  for (long long i = 1; i <= n; i++) {
    rev[i] = (long double)1 / t[i];
  }
  partial_sum(rev.begin(), rev.end(), rev.begin());
  auto vec_normal = [&](pair<long double, long double> x) {
    return pair<long double, long double>{-x.second, x.first};
  };
  auto vec_diff = [&](pair<long double, long double> x,
                      pair<long double, long double> y) {
    return pair<long double, long double>{x.first - y.first,
                                          x.second - y.second};
  };
  auto vec_dot = [&](pair<long double, long double> x,
                     pair<long double, long double> y) {
    return x.first * y.first + x.second * y.second;
  };
  auto vec_cross = [&](pair<long double, long double> x,
                       pair<long double, long double> y) {
    return x.first * y.second - x.second * y.first;
  };
  auto vec_cross_pos = [&](pair<long double, long double> x,
                           pair<long double, long double> y) {
    return vec_cross(x, y) > 0;
  };
  vector<pair<long double, long double>> cft_p, cft_n;
  auto cft_clear = [&]() {
    cft_p.clear();
    cft_n.clear();
  };
  auto cft_add = [&](pair<long double, long double> x) {
    while (
        !cft_n.empty() &&
        !vec_cross_pos(cft_n.back(), vec_normal(vec_diff(x, cft_p.back())))) {
      cft_p.pop_back();
      cft_n.pop_back();
    }
    if (!cft_p.empty()) {
      cft_n.push_back(vec_normal(vec_diff(x, cft_p.back())));
    }
    cft_p.push_back(x);
  };
  auto cft_query = [&](pair<long double, long double> x) {
    return cft_p.empty()
               ? (long double)1e30
               : vec_dot(x, cft_p[lower_bound(cft_n.begin(), cft_n.end(), x,
                                              vec_cross_pos) -
                                  cft_n.begin()]);
  };
  vector<vector<long double>> dp(
      (size_t)k + 1, vector<long double>((size_t)n + 1, (long double)1e30));
  dp[0][0] = 0;
  for (long long i = 1; i <= k; i++) {
    cft_clear();
    for (long long j = 0; j <= n; j++) {
      dp[i][j] = pre[j] + cft_query({-rev[j], 1});
      cft_add({sum[j], dp[i - 1][j] - pre[j] + rev[j] * sum[j]});
    }
  }
  cout << setprecision(100) << dp[k][n] << endl;
  return 0;
}
