#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  string s;
  regex re1("[A-Za-z0-9_]{1,16}@[A-Za-z0-9_.]{1,32}(/[A-Za-z0-9_]{1,16})?");
  regex rrr(
      "[A-Za-z0-9_]{1,16}@[A-Za-z0-9_]{1,16}(.[A-Za-z0-9_]{1,16})*(/"
      "[A-Za-z0-9_]{1,16})?");
  cin >> s;
  if (regex_match(s, re1) || regex_match(s, rrr))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
