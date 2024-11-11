#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
long long int dp[3][1000100];
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> cnt(k, 0);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < n + k + 1; j++) dp[i][j] = (1LL << 50);
  for (int i = 0; i < k; i++) dp[0][i] = 0;
  string s;
  cin >> s;
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++)
      if (1)
        cout << "i"
             << "=" << i << " "
             << "j"
             << "=" << j << " "
             << "dp[j][i]"
             << "=" << dp[j][i] << " "
             << "s[i]"
             << "=" << s[i] << endl;
    ;
    chmin(dp[0][i + k], dp[0][i] + (s.at(i) == '1'));
    chmin(dp[1][i + k], dp[0][i] + (s.at(i) == '0'));
    chmin(dp[1][i + k], dp[1][i] + (s.at(i) == '0'));
    chmin(dp[2][i + k], dp[1][i] + (s.at(i) == '1'));
    chmin(dp[2][i + k], dp[2][i] + (s.at(i) == '1'));
    chmin(dp[2][i + k], dp[0][i] + (s.at(i) == '1'));
    cnt[i % k] += (s.at(i) == '1');
    sum += (s.at(i) == '1');
  }
  long long int ans = (1LL << 50);
  for (int i = n; i < n + k; i++) {
    long long int nowMin = (1LL << 50);
    for (int j = 0; j < 3; j++) {
      if (1)
        cout << "j"
             << "=" << j << " "
             << "i"
             << "=" << i << " "
             << "dp[j][i]"
             << "=" << dp[j][i] << " "
             << "sum - cnt[i % k]"
             << "=" << sum - cnt[i % k] << endl;
      ;
      chmin(nowMin, dp[j][i]);
    }
    chmin(ans, nowMin + sum - cnt[i % k]);
  }
  cout << ans << endl;
}
int main() {
  long long int q;
  cin >> q;
  while (q--) solve();
  return 0;
}
