#include <bits/stdc++.h>
using namespace std;
int n, pw;
bool dp[5010];
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s;
  n = s.length();
  for (; 1 << (pw + 1) < n; ++pw)
    ;
  for (int i = 0; i < (1 << pw); ++i) {
    dp[i] = 1;
  }
  for (int i = 0; i < n - (1 << pw) + 1; ++i) {
    char c = 100;
    for (int j = 0; j < 1 << pw; ++j) {
      if (!dp[j]) {
        continue;
      }
      c = min(c, s[i + j]);
    }
    cout << c;
    for (int j = 0; j < 1 << pw; ++j) {
      dp[j] &= (s[i + j] == c);
    }
    for (int j = 0; j < 1 << pw; ++j) {
      for (int k = 0; k < pw; ++k) {
        dp[j | (1 << k)] |= dp[j];
      }
    }
  }
}
