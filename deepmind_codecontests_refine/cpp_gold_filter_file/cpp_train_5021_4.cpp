#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int bal = 0, ans = 0, start = 0;
  for (auto c : s) {
    bal += (c == '(' ? 1 : -1);
  }
  if (bal != 0) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    bal += (s[i] == '(' ? 1 : -1);
    if (bal == -1 && s[i] == ')') {
      start = i;
    } else if (bal == 0 && s[i] == '(') {
      ans += i - start + 1;
    }
  }
  if (bal < 0) {
    ans += n - start;
  }
  cout << ans;
  return 0;
}
