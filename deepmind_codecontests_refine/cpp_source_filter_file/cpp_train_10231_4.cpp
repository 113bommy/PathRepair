#include <bits/stdc++.h>
using namespace std;
long long int recur(long long int index, long long int moves, long long int cnt,
                    string &s, string &t,
                    vector<vector<vector<long long int>>> &dp) {
  if (index == s.length()) return 0;
  if (dp[index][moves][cnt] != -1) return dp[index][moves][cnt];
  if (!moves)
    return dp[index][moves][cnt] =
               (s[index] == t[1] ? cnt : 0) +
               recur(index + 1, moves, cnt + s[index] == t[0], s, t, dp);
  if (s[index] == t[0])
    return dp[index][moves][cnt] =
               max(recur(index + 1, moves, cnt + 1, s, t, dp),
                   cnt + recur(index + 1, moves - 1, cnt, s, t, dp));
  if (s[index] == t[1])
    return dp[index][moves][cnt] =
               max(recur(index + 1, moves - 1, cnt + 1, s, t, dp),
                   cnt + recur(index + 1, moves, cnt, s, t, dp));
  return dp[index][moves][cnt] =
             max({recur(index + 1, moves - 1, cnt + 1, s, t, dp),
                  cnt + recur(index + 1, moves - 1, cnt, s, t, dp),
                  recur(index + 1, moves, cnt, s, t, dp)});
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n, k;
  string s, t;
  cin >> n >> k >> s >> t;
  if (t[0] != t[1]) {
    vector<vector<vector<long long int>>> dp(
        n,
        vector<vector<long long int>>(k + 1, vector<long long int>(n + 1, -1)));
    cout << recur(0, k, 0, s, t, dp);
  } else {
    long long int ans = k;
    for (long long int i = 0; i < s.length(); i++) {
      if (s[i] == t[0]) ans++;
    }
    ans = min(n, ans);
    cout << (ans * (ans - 1)) / 2;
  }
}
