#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3;
map<string, int> dp;
string f(string s) {
  int n = s.size();
  for (int i = 0; i < n; i++)
    if (17 <= (s[i] - '0') && (s[i] - '0') <= 42) {
      s[i] = char(s[i] + 32);
    }
  return s;
}
int n, mx;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2 >> s3;
    s1 = f(s1);
    s3 = f(s3);
    dp[s1] = dp[s3] + 1;
    mx = max(mx, dp[s1]);
  }
  cout << mx + 1;
}
