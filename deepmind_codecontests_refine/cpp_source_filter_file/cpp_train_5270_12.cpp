#include <bits/stdc++.h>
using namespace std;
bool sogl(char c) {
  string gl = "aeiou";
  for (auto g : gl) {
    if (c == g) return 0;
  }
  return 1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  string s;
  cin >> s;
  long long n = s.size();
  vector<long long> ans(n);
  long long odin = 1;
  long long k = 0;
  for (long long i = 0; i < n; i++) {
    if (!sogl(s[i])) {
      k = 0;
      odin = 1;
    } else {
      if (k < 2) {
        if (k != 0 && s[i] != s[i - 1]) odin = 0;
        k++;
      } else if (s[i] == s[i - 1] && odin) {
        k++;
      } else {
        ans[i] = 1;
        k = 0;
        odin = 1;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    if (ans[i]) cout << " ";
    cout << s[i];
  }
}
