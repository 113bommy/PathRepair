#include <bits/stdc++.h>
using namespace std;
int n, a[1000000 + 5], f[1000000 + 5], maxl, ans;
string s;
stack<int> stk;
int main() {
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(')
      stk.push(i);
    else if (s[i] == ')' && !stk.empty())
      a[i] = a[stk.top()] = 1, stk.pop();
  }
  f[0] = a[0];
  for (int i = 1; i < n; ++i)
    f[i] = (a[i] ? f[i - 1] + 1 : 0), maxl = max(maxl, f[i]);
  if (maxl == 0) {
    cout << "0 1" << endl;
    return 0;
  }
  for (int i = 0; i < n; ++i) ans += (f[i] == maxl);
  cout << maxl << " " << ans << endl;
  return 0;
}
