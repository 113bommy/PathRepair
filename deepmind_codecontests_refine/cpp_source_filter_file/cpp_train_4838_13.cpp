#include <bits/stdc++.h>
using namespace std;
void setup() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
}
struct super_string {
  string s;
  super_string(string _s) { s = _s; };
  super_string() {}
  vector<long long> pref_function() {
    vector<long long> res(s.size(), 0);
    for (long long i = 1; i < s.size(); ++i) {
      res[i] = res[i - 1];
      while (res[i] > 0 && s[i] != s[res[i]]) res[i] = res[res[i] - 1];
      if (s[i] == s[res[i]]) ++res[i];
    }
    return res;
  }
  vector<long long> z_function() {
    vector<long long> res(s.size(), s.size());
    long long l = 0, r = 0;
    for (long long i = 1; i < s.size(); ++i) {
      res[i] = max((long long)0, min(r - i, res[i - l]));
      while (res[i] + i < s.size() && s[res[i]] == s[res[i] + i]) ++res[i];
      if (res[i] + i > r) r = res[i] + i, l = i;
    }
    return res;
  }
};
const long long MOD = 1e9 + 7;
const long long N = 1e5 + 228;
long long dp[N][2];
signed main() {
  setup();
  string s, t;
  cin >> s >> t;
  super_string O(t + "$" + s);
  auto z = O.z_function();
  vector<long long> good(s.size() + 10);
  for (long long i = 0; i < s.size(); ++i) {
    if (z[i + t.size() + 1] == t.size()) {
      good[i + 1] = 1;
    }
  }
  for (long long i = 0; i < N - 1; ++i) {
    dp[i][1] = 0;
    dp[i][0] = 1;
  }
  if (good[0] && t.size() == 1) dp[1][1] = 1;
  vector<long long> pref(s.size() + 1, 1);
  for (long long i = 1; i <= s.size(); ++i) {
    pref[i] = pref[i - 1];
    if (i < t.size()) {
      pref[i] = (pref[i] + dp[i][0] + dp[i][1]) % MOD;
      continue;
    }
    if (good[i - t.size() + 1]) {
      dp[i][1] = ((pref[i - t.size()] - dp[i - 1][1]) % MOD + MOD) % MOD;
    }
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    dp[i][1] = (dp[i][1] + dp[i - 1][1]) % MOD;
    pref[i] = (pref[i] + dp[i][0] + dp[i][1]) % MOD;
  }
  cout << dp[s.size()][0] + dp[s.size()][1] - 1;
}
