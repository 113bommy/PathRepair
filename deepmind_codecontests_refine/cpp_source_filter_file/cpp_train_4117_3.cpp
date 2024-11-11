#include <bits/stdc++.h>
using namespace std;
string t, s, res;
multiset<char> sc;
int main() {
  ios::sync_with_stdio(false);
  cin >> t >> s;
  for (int i = 0; i < t.size(); ++i) sc.insert(t[i]);
  for (int i = 0; i < s.size(); ++i) sc.erase(sc.find(s[i]));
  for (int i = 1; i <= 6; ++i) {
    int val = t.size() - i;
    if ((int)log10(val) + 1 == i) {
      while (val) {
        sc.erase(sc.find(val % 10 + '0'));
        val /= 10;
      }
      break;
    }
  }
  for (int i = '1'; i <= '9'; ++i) {
    if (sc.find(i) != sc.end()) {
      sc.erase(sc.find(i));
      res.push_back(i);
      break;
    }
  }
  for (multiset<char>::iterator it = sc.begin(); it != sc.end(); it++)
    res.push_back(*it);
  if (!res.size() || res[0] == '0') {
    cout << s << res;
    return 0;
  }
  int pos = 0;
  bool ok = 0;
  while (pos < min(s.size(), res.size()) - 1 && s[pos] == res[pos]) pos++;
  if (s[pos] <= res[pos] && s[0] != '0') {
    cout << s;
    for (int i = 1; i < res.size(); ++i) {
      if (res[i] >= res[0]) {
        cout << res[0];
        ok = 1;
      }
      cout << res[i];
    }
    if (!ok) cout << res[0];
    return 0;
  }
  ok = 0;
  pos = 1;
  while (pos < s.size() - 1 && s[pos] == s[pos - 1]) pos++;
  cout << res[0];
  for (int i = 1; i < res.size(); ++i) {
    if (!ok && (s[0] == res[i] && s[pos] < res[i] || s[0] < res[i])) {
      cout << s;
      ok = 1;
    }
    cout << res[i];
  }
  if (!ok) cout << s;
}
