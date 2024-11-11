#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const double INF = 1e12;
int N;
int a[55];
double b[65], DP[65][65];
bool check(double mid) {
  map<int, vector<double>> group;
  for (int i = 1; i <= N; ++i) {
    group[a[i]].push_back(1.0 * a[i] - mid * b[i]);
  }
  vector<vector<double>> vec;
  for (auto& e : group) {
    sort(e.second.begin(), e.second.end());
    reverse(e.second.begin(), e.second.end());
    vec.push_back(e.second);
  }
  reverse(vec.begin(), vec.end());
  int n = vec.size();
  for (int i = 0; i < 65; ++i) {
    for (int j = 0; j < 65; ++j) {
      DP[i][j] = INF;
    }
  }
  DP[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= N; ++j) {
      if (DP[i][j] >= INF) continue;
      double go_second = 0, go_first = 0;
      int sz = vec[i].size();
      for (int k = 0; k < sz; ++k) {
        go_first += vec[i][k];
      }
      if (j + sz <= N) {
        DP[i + 1][j + sz] = min(DP[i + 1][j + sz], DP[i][j] + go_first);
      }
      for (int k = 0; k < sz && k + 1 <= j && j + sz - 2 * (k + 1) <= N &&
                      j + sz - 2 * (k + 1) >= 0;
           ++k) {
        go_second += vec[i][k];
        DP[i + 1][j + sz - 2 * (k + 1)] = min(DP[i + 1][j + sz - 2 * (k + 1)],
                                              DP[i][j] + go_first - go_second);
      }
    }
  }
  double ret = INF;
  for (int i = 0; i <= N / 2; ++i) {
    ret = min(ret, DP[n][i]);
  }
  return ret <= 0;
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= N; ++i) scanf("%lf", &b[i]);
  double L = 0, R = INF;
  while (R - L > eps) {
    double mid = (L + R) / 2;
    if (check(mid)) {
      R = mid;
    } else {
      L = mid;
    }
  }
  L *= 1000;
  long long ret = ceil(L);
  printf("%I64d\n", ret);
  return 0;
}
