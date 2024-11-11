#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long N = 500 * 1000 + 13;
const long long p = 998244353;
long long n, m, d;
long long visited[200 + 1];
long long c[1009];
long long res[1009];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  t = 1;
  while (t--) {
    string s;
    cin >> s;
    long long dp[26] = {0};
    for (long long i = 0; i < s.length(); i++) {
      dp[s[i] - 'a']++;
    }
    long long val = 0;
    long long ind;
    for (long long i = 0; i < 26; i++) {
      if (dp[i] != 0) {
        val = dp[i];
        ind = i;
      }
    }
    string res = "";
    for (long long i = 0; i < val; i++) {
      res += ind + 'a';
    }
    cout << res << '\n';
  }
  return 0;
}
