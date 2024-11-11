#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using pii = pair<int, int>;
const bool debug = false;
long long dp[420][420];
void print_dp_table(long long a, long long b) {
  for (long long i = 0; i <= a; i++) {
    for (long long j = 0; j <= b; j++) {
      printf("%lld ", dp[i][j] >= 1000 ? -1 : dp[i][j]);
    }
    printf("\n");
  }
}
void solve() {
  long long n;
  string s, t;
  cin >> s >> t;
  vector<long long> letter_indexes[26];
  for (long long i = 0; i < 26; i++) letter_indexes[i].push_back(-1);
  for (long long i = 0; i < s.length(); i++) {
    letter_indexes[s[i] - 'a'].push_back(i + 1);
  }
  n = t.length();
  for (long long cut = 0; cut < n; cut++) {
    string left = t.substr(0, cut);
    string right = t.substr(cut, n - cut);
    if (debug) printf("CUT String as %s : %s\n", left.c_str(), right.c_str());
    memset(dp, 0x7f, sizeof(dp));
    dp[0][0] = 0;
    for (long long i = 1; i <= cut; i++) {
      long long cur_ind = dp[i - 1][0] + 1;
      if (cur_ind > letter_indexes[left[i - 1] - 'a'].back()) continue;
      long long u =
          *lower_bound(((letter_indexes[left[i - 1] - 'a']).begin()),
                       ((letter_indexes[left[i - 1] - 'a']).end()), cur_ind);
      dp[i][0] = u;
    }
    for (long long i = 1; i <= (n - cut); i++) {
      long long cur_ind = dp[0][i - 1] + 1;
      if (cur_ind > letter_indexes[right[i - 1] - 'a'].back()) continue;
      long long u =
          *lower_bound(((letter_indexes[right[i - 1] - 'a']).begin()),
                       ((letter_indexes[right[i - 1] - 'a']).end()), cur_ind);
      dp[0][i] = u;
    }
    if (debug) printf("Start filling inner table\n");
    for (long long i = 1; i <= cut; i++) {
      for (long long j = 1; j <= (n - cut); j++) {
        long long u1 = 0x7f7f7f7f7f7f7f7f;
        long long cur_ind = dp[i - 1][j] + 1;
        if (cur_ind <= letter_indexes[left[i - 1] - 'a'].back())
          u1 = *lower_bound(((letter_indexes[left[i - 1] - 'a']).begin()),
                            ((letter_indexes[left[i - 1] - 'a']).end()),
                            cur_ind);
        long long u2 = 0x7f7f7f7f7f7f7f7f;
        long long cur2_ind = dp[i][j - 1] + 1;
        if (cur2_ind <= letter_indexes[right[i - 1] - 'a'].back())
          u2 = *lower_bound(((letter_indexes[right[j - 1] - 'a']).begin()),
                            ((letter_indexes[right[j - 1] - 'a']).end()),
                            cur2_ind);
        dp[i][j] = min(min(u1, u2), dp[i][j]);
      }
    }
    if (debug) print_dp_table(cut, n - cut);
    long long best = dp[cut][n - cut];
    if (best <= s.length()) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
  return;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
