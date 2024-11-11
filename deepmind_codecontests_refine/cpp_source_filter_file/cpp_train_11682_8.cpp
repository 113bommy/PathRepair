#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("avx2")
using namespace std;
int a[(long long)(1e6 + 5)];
pair<long long, long long> dp[(long long)(1e6 + 5)];
int n, k, l;
pair<long long, long long> solve(int cost) {
  for (int i = 0; i <= n; i++)
    dp[i] = pair<long long, long long>((long long)(0x3f3f3f3f),
                                       (long long)(0x3f3f3f3f));
  dp[0] = pair<long long, long long>(0, 0);
  for (int i = 0; i < n; i++) {
    dp[i + 1] = min(dp[i + 1], pair<long long, long long>(dp[i].first + a[i],
                                                          dp[i].second));
    dp[min(i + l, n)] =
        min(dp[min(i + l, n)],
            pair<long long, long long>(dp[i].first + cost, dp[i].second + 1));
  }
  return dp[n];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> l;
  string second;
  cin >> second;
  for (int i = 0; i < n; i++) a[i] = ('a' <= second[i] && second[i] <= 'z');
  int cost = 0;
  for (int po = (1 << 19); po; po >>= 1)
    if (solve(cost + po).second > k) cost += po;
  cost++;
  int res = solve(cost).first - k * cost;
  for (int i = 0; i < n; i++) a[i] = ('A' <= second[i] && second[i] <= 'Z');
  cost = 0;
  for (int po = (1 << 19); po; po >>= 1)
    if (solve(cost + po).second > k) cost += po;
  cost++;
  res = min(res, (int)solve(cost).first - k * cost);
  cout << (res) << '\n';
  return 0;
}
