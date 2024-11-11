#include <bits/stdc++.h>
using namespace std;
int dp[500005];
int main() {
  string a, ans;
  set<string> s;
  cin >> a;
  int len = a.length();
  dp[len] = 1;
  for (int i = len - 1; i > 4; i--) {
    for (int l = 2; l <= 3; l++) {
      if (dp[i + l]) {
        ans = a.substr(i, l);
        if (a.find(ans) != i + l || dp[i + 5]) {
          s.insert(ans);
          dp[i] = 1;
        }
      }
    }
  }
  printf("%d\n", s.size());
  for (set<string>::iterator its = s.begin(); its != s.end(); ++its) {
    cout << *its << "\n";
  }
  return 0;
}
