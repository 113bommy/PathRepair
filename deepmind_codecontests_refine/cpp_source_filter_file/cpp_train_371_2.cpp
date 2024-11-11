#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
int main() {
  long long n, i, j;
  cin >> n;
  string s;
  cin >> s;
  long long len = s.length();
  long long dp[27][len + 1];
  memset(dp, 0, sizeof(dp));
  for (long long start = 0; start < 26; start++) {
    for (i = 0; i <= len - 1; i++) {
      long long rep = 0;
      for (j = i; j <= len - 1; j++) {
        if (s[j] != char('a' + start)) {
          ++rep;
        }
        dp[start][rep] = max(dp[start][rep], j - i + 1);
      }
    }
    for (i = 1; i <= len - 1; i++)
      dp[start][i] = max(dp[start][i], dp[start][i - 1]);
  }
  long long q;
  cin >> q;
  while (q--) {
    long long m;
    char c;
    cin >> m;
    cin >> c;
    cout << dp[c - 'a'][m] << '\n';
  }
  return 0;
}
