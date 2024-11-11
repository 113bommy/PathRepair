#include <bits/stdc++.h>
using namespace std;
string removeA(string s) {
  string ret = "";
  for (char c : s)
    if (c != 'a') ret += c;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  string s2 = removeA(s);
  if (s2.length() % 2) {
    cout << ":(";
    return 0;
  } else if (s2 == "") {
    cout << s;
    return 0;
  }
  string ps2 = s2.substr(0, s2.length() / 2);
  string ps3 = s2.substr((s2.length() / 2));
  if (ps2.compare(ps3) != 0) {
    cout << ":(";
    return 0;
  }
  if (s2.compare(s) == 0) {
    cout << ps2;
    return 0;
  }
  string t = s;
  string rev = ps2;
  reverse(t.begin(), t.end());
  reverse(rev.begin(), rev.end());
  bool ok = true;
  int i = 0;
  while (i < rev.size() && ok) {
    ok = t[i] == rev[i];
    i++;
  }
  t.erase(0, i);
  reverse(t.begin(), t.end());
  if (ok && s.compare(t + ps2) == 0)
    cout << t << endl;
  else
    cout << ":(";
  return 0;
}
