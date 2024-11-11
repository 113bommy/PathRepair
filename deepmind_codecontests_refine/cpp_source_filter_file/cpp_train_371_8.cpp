#include <bits/stdc++.h>
using namespace std;
int n, q, dp[26][1500];
string s;
int main() {
  cin >> n >> s >> q;
  for (int c = 0; c < 26; ++c) {
    for (int i = 0; i < n; ++i) {
      int rep = 0;
      for (int j = i; j < n; ++j) {
        if (s[j] != c + 'a') ++rep;
        dp[c][rep] = max(dp[c][rep], j - i + 1);
      }
    }
    for (int i = 0; i < n; ++i) dp[c][i] = max(dp[c][i], dp[c][i - 1]);
  }
  int mi;
  char ci;
  while (q--) {
    cin >> mi >> ci;
    cout << dp[ci - 'a'][mi] << "\n";
  }
}
