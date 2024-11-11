#include <bits/stdc++.h>
using namespace std;
string pal(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  s = s + "#" + t;
  long long int l = s.length();
  long long int a[l + 1], c = 0;
  a[0] = 0;
  for (int i = 1; i < l; i++) {
    while (c != 0 && s[c] != s[i]) c = a[c - 1];
    if (s[c] == s[i]) c++;
    a[i] = c;
  }
  return s.substr(0, c);
}
void solve() {
  string s, t;
  cin >> s;
  t = s;
  reverse(t.begin(), t.end());
  string a, b;
  long long int i = 0;
  for (i = 0; i < s.length() - i - 1; i++)
    if (s[i] != s[s.length() - 1 - i]) break;
  if (i > 0) cout << s.substr(0, i);
  if (2 * i < s.length()) {
    a = pal(s.substr(i, s.length() - 2 * i));
    b = pal(t.substr(i, t.length() - 2 * i));
    if (a.length() >= b.length())
      cout << a;
    else
      cout << b;
  }
  if (i > 0) cout << s.substr(s.length() - i, i);
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
