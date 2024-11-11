#include <bits/stdc++.h>
using namespace std;
int n, ans;
bool found, c[26], fst = true;
char ch, sch;
string s;
void comp() {
  bool a[26] = {false};
  for (int i = 0; i < s.length(); ++i) a[s[i] - 'a'] = true;
  for (int i = 0; i < 26; ++i) {
    if (c[i] && !a[i]) c[i] = false;
  }
  return;
}
void update(bool flag) {
  for (int i = 0; i < s.length(); ++i) c[s[i] - 'a'] = c[s[i] - 'a'] && flag;
  if (flag) comp();
  return;
}
void check() {
  int count = 0;
  for (int i = 0; i < 26; ++i) {
    if (c[i]) {
      ++count;
      sch = 'a' + i;
    }
  }
  found = (count == 1);
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  memset(c, true, sizeof c);
  while (n--) {
    cin >> ch >> s;
    if (ch == '.')
      update(false);
    else if (ch == '!' && !found)
      update(true);
    else if (ch == '?' && !found)
      c[s[0] - 'a'] = false;
    else
      ++ans;
    if (!found) check();
  }
  if (found && s[0] == sch) --ans;
  cout << ans << endl;
  return 0;
}
