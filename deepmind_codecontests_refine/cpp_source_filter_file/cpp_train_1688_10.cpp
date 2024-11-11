#include <bits/stdc++.h>
using namespace std;
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % (long long int)1e9 + 7;
    ;
    a = (a * a) % (long long int)1e9 + 7;
    ;
    b = b >> 1;
  }
  return res % (long long int)1e9 + 7;
  ;
}
void solve() {
  string s, t;
  cin >> s;
  cin >> t;
  vector<long long int> dd(26, 0);
  for (long long int i = 0; i < s.size(); i++) {
    dd[s[i] - 'a']++;
  }
  long long int dp[t.size() + 1][26];
  for (long long int i = 0; i < 26; i++) {
    dp[0][i] = 0;
  }
  for (long long int i = 0; i < t.size(); i++) {
    if (i != 0) {
      for (long long int j = 0; j < 26; j++) {
        dp[i][j] = dp[i - 1][j];
      }
    }
    dp[i][t[i] - 'a']++;
  }
  for (long long int i = 0; i < t.size(); i++) {
    for (long long int j = i + 1; j < t.size(); j++) {
      vector<long long int> cc(26, 0);
      long long int check = 0;
      for (long long int k = 0; k < 26; k++) {
        cc[k] = dp[j][k];
        if (i != 0) {
          cc[k] -= dp[i - 1][k];
        }
        if (cc[k] != dd[k]) {
          check = 1;
          break;
        }
      }
      if (check == 0) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
