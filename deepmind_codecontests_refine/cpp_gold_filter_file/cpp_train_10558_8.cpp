#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t, l = "", r = "";
  int i;
  cin >> s >> t;
  for (i = 0; s[i] != '|'; i++) l += s[i];
  i++;
  for (; i < s.size(); i++) r += s[i];
  int sz = r.size() + l.size() + t.size();
  if ((sz) % 2 || l.size() > sz / 2 || r.size() > sz / 2)
    puts("Impossible");
  else {
    string res = l + t + r;
    for (i = 0; i < sz; i++) {
      if (i == sz / 2) cout << "|";
      cout << res[i];
    }
    puts("");
  }
  return 0;
}
