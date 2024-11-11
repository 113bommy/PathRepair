#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
bool all_9(const string& s) {
  bool flag = true;
  for (char ch : s)
    if (ch != '9') flag = false;
  return flag;
}
int main() {
  long long p, d;
  cin >> p >> d;
  string s = to_string(p), ans;
  if (all_9(s)) {
    cout << s << '\n';
    return 0;
  }
  ans = s;
  int i = s.size() - 1;
  while (i > 0 && s[i] == '9') --i;
  for (; i > 0; --i) {
    s[i] = '9';
    if (s[i - 1] == '0') continue;
    s[i - 1] = (s[i - 1] - '0' - 1) + '0';
    if (p - stoll(s) <= d) ans = s;
  }
  i = 0;
  while (s[i] == '0') ++i;
  cout << ans.substr(i) << '\n';
}
