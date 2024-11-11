#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << "\b\b]\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H << ", ";
  dbg_out(T...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> A(n), cnts(m);
  vector<bool> dp(m, false);
  for (int &i : A) {
    cin >> i;
    i = i % m;
    cnts[i]++;
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 1; j < cnts[i]; ++j) {
      dp[(i * j) % m] = true;
    }
  }
  for (int i = 0; i < m; ++i) {
  }
  for (int i = 1; i < m; ++i) {
    if (!cnts[i]) continue;
    dp[i] = true;
    vector<bool> dp_curr(m, false);
    for (int j = 0; j < m; ++j) {
      if (dp[j]) {
        dp_curr[i] = true;
        dp_curr[(i + j) % m] = true;
      }
    }
    dp = dp_curr;
  }
  for (int i = 0; i < m; ++i) {
  }
  cout << (dp[0] ? "YES" : "NO");
  return 0;
}
