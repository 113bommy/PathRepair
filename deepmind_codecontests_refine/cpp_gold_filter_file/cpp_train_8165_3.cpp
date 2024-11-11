#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
signed main() {
  long long n;
  cin >> n;
  vector<long long> c;
  for (long long i = 0; i < n; i++) {
    long long rt;
    cin >> rt;
    c.push_back(rt);
  }
  map<long long, long long> nombres;
  n++;
  for (long long i = 0; i < 1e5; i++) {
    nombres[n] = 0;
  }
  for (long long i = 0; i < n; i++) {
    nombres[c[i]]++;
  }
  vector<long long> dp(2, 0);
  nombres[0] = 0;
  dp[0] = nombres[0];
  dp[1] = nombres[1];
  for (long long i = 2; i < 1e5 + 10; i++) {
    dp.push_back(max(dp[i - 2] + (long long)nombres[i] * i, dp[i - 1]));
  }
  cout << dp.back();
  return 0;
}
