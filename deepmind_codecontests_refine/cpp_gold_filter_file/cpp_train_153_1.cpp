#include <bits/stdc++.h>
using namespace std;
int main() {
  long long data = 0, ans = 0;
  string t, m;
  while (getline(cin, t)) {
    if (t[0] == '+')
      data++;
    else if (t[0] == '-')
      data--;
    else {
      m = "";
      for (int i = t.find(':') + 1; i < t.size(); i++) {
        m += t[i];
      }
      ans += m.size() * data;
    }
  }
  cout << ans;
  return 0;
}
