#include <bits/stdc++.h>
using namespace std;
const long long MX5 = 2 * 1e5 + 3;
const long long MX9 = 2 * 1e9 + 3;
int main() {
  int n = 0, ans = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(')
      n++;
    else {
      if (n) {
        ans++;
        n--;
      }
    }
  }
  cout << ans;
  return 0;
}
