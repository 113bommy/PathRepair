#include <bits/stdc++.h>
using namespace std;
const int Nmax = 10000;
int a[Nmax], dp[Nmax];
int main() {
  string s;
  cin >> s;
  if (s == "0") {
    cout << "0";
    return 0;
  }
  if (s == "1") {
    cout << "1";
    return 0;
  }
  int cnt = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '0') {
      dp[i] = dp[i + 1] + 1;
    } else {
      cnt++;
      dp[i] = max(dp[i + 1], cnt);
    }
  }
  for (int i = 0; i <= s.size() - 2; i++) {
    if (dp[i] == dp[i + 1] + 1) {
      cout << "0";
    } else {
      cout << "1";
    }
  }
  cout << "0";
  return 0;
}
