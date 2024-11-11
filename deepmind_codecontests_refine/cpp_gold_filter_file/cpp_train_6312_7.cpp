#include <bits/stdc++.h>
using namespace std;
int mod = (1e9) + 7;
int f(int b, int p) {
  if (p == 0) return 1;
  int x = f(b, p / 2);
  x = (1LL * x * x) % mod;
  if (p % 2) return (1LL * x * b) % mod;
  return x;
}
map<int, int> dp;
int main() {
  int x, y;
  cin >> x >> y;
  if (y % x) {
    puts("0");
    return 0;
  }
  y /= x;
  if (y == 1) {
    puts("1");
    return 0;
  }
  vector<int> v;
  for (int i = 2; i * i <= y; ++i) {
    if (y % i) continue;
    v.push_back(i);
    if (i * i != y) v.push_back(y / i);
  }
  v.push_back(y);
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); ++i) {
    dp[v[i]] = f(2, v[i] - 1) - 1;
    for (int j = 0; j < i && 1LL * v[j] * v[j] <= v[i]; ++j) {
      if (v[i] % v[j]) continue;
      dp[v[i]] = (dp[v[i]] + mod - dp[v[j]]) % mod;
      if (v[j] * v[j] != v[i])
        dp[v[i]] = (dp[v[i]] + mod - dp[v[i] / v[j]]) % mod;
    }
  }
  cout << dp[y] << endl;
  return 0;
}
