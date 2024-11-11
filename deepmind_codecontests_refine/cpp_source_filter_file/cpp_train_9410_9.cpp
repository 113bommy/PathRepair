#include <bits/stdc++.h>
const long long MaxN = 1e3 + 10;
const long long mod = 1e9 + 7;
using namespace std;
string s, res;
int kt;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> s;
  if (s.size() < 3 || s[0] == '@' || s[s.size() - 1] == '@') {
    cout << "No solution";
    return 0;
  }
  string res = "";
  res += s[0];
  for (int i = 1; i < s.size(); i++) {
    res += s[i];
    if ((s[i] == s[i + 1] || s[i] == s[i + 2]) && s[i] == '@') {
      cout << "No solution";
      return 0;
    }
    if (s[i - 1] == '@') {
      res += ',';
      kt = 1;
    }
  }
  for (int i = res.size() - 1; i >= 0; i--) {
    if (res[i] == '@') break;
    if (res[i] == ',') res.erase(i, 1);
  }
  if (!kt)
    cout << res;
  else
    cout << "No solution";
  return 0;
}
