#include <bits/stdc++.h>
using namespace std;
struct _ {
  ios_base::Init i;
  _() {
    cin.sync_with_stdio(0);
    cin.tie(0);
  }
} _;
int n, m;
string s;
bool check() {
  int dog = s.find('@');
  if (dog <= 0 || dog == s.size() - 1 || dog > 16) return false;
  for (int i = 0; i < dog; ++i)
    if (!isalnum(s[i]) && s[i] != '_') return false;
  int slash = s.find('/');
  if (slash >= 0 && (s.size() - (slash + 1) > 16 || slash == s.size() - 1 ||
                     slash - (dog + 1) > 32 || slash - dog <= 1))
    return false;
  if (slash == -1) slash = s.size();
  int k = 0;
  for (int i = dog + 1; i < slash; ++i) {
    if (!isalnum(s[i]) && s[i] != '_') {
      if (s[i] != '.') return false;
      k = 0;
      if (s[i - 1] == '.') return false;
      if (i == slash - 1 || i == dog + 1) return false;
    } else
      ++k;
    if (k > 16) return false;
  }
  if (slash != s.size()) {
    for (int i = slash + 1; i < s.size(); ++i) {
      if (!(isalnum(s[i]) || s[i] == '_')) return false;
    }
  }
  return true;
}
int main() {
  cin >> s;
  if (check())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
