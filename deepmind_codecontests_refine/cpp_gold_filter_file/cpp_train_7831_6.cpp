#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long inf = 1e18 + 5;
int _;
void solve() {
  string s;
  cin >> s;
  int o = count(s.begin(), s.end(), '1');
  int z = count(s.begin(), s.end(), '0');
  string s_new = "";
  if (o == 0 || z == 0)
    cout << s << endl;
  else {
    if (s[0] == '1')
      s_new += "1";
    else
      s_new += "0";
    for (int i = 1; i < 2 * s.size(); ++i) {
      if (s_new[i - 1] == '1')
        s_new += "0";
      else
        s_new += "1";
    }
    cout << s_new << endl;
  }
}
int main() {
  scanf("%d", &_);
  while (_--) {
    solve();
  }
}
