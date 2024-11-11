#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int n, cou;
string a, b, c;
void solve() {
  cin >> b;
  int ans = 0;
  string d = "";
  for (int i = 0; i < b.size(); i++) {
    if (b[i] == '&')
      ans--;
    else if (b[i] == '*')
      ans++;
    else
      d += b[i];
  }
  cou = mp[d];
  if (cou > 0)
    cou += ans;
  else
    cou = 0;
  b.clear();
}
int main() {
  std::ios::sync_with_stdio(false);
  mp["void"] = 1;
  cin >> n;
  while (n--) {
    cin >> a;
    if (a == "typedef") {
      solve();
      cin >> c;
      mp[c] = cou;
      c.clear();
    } else if (a == "typeof") {
      solve();
      if (--cou < 0)
        cout << "errtype" << endl;
      else {
        cout << "void";
        for (int i = 0; i < cou; i++) cout << "*";
        cout << endl;
      }
    }
    a.clear();
  }
}
