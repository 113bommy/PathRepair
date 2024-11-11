#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 29);
int GetT(int k, int lastT, int lastF, int t, int f) {
  int ret = INF;
  if (lastT <= k) {
    int tables = lastT + t;
    int sep = (tables + k - 1) / k - 1;
    if (tables % k == 0)
      sep = tables / k - 1;
    else
      sep = tables / k;
    if (f == sep)
      ret = min(ret, tables - sep * k);
    else if (f > sep && f <= 1LL * tables * k)
      ret = 1;
  }
  if (lastF <= k) {
    int tables = t;
    int sep = (tables + k - 1) / k - 1;
    if (f == sep)
      ret = min(ret, tables - sep * k);
    else if (f > sep && f < k - lastF + 1LL * (tables - 1) * k)
      ret = 1;
  }
  return ret;
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i];
  for (int i = 0; i < n; ++i) cin >> y[i];
  int dp[2][2];
  int current = 0, last = 1;
  dp[current][0] = GetT(k, 0, 0, x[0], y[0]);
  dp[current][1] = GetT(k, 0, 0, y[0], x[0]);
  for (int i = 1; i < n; ++i) {
    swap(current, last);
    dp[current][0] = GetT(k, dp[last][0], dp[last][1], x[i], y[i]);
    dp[current][1] = GetT(k, dp[last][1], dp[last][0], y[i], x[i]);
  }
  if (dp[current][0] <= k || dp[current][1] <= k)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
