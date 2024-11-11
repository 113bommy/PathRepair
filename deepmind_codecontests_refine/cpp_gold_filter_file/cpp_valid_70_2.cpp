#include <bits/stdc++.h>
using namespace std;
int cntsrc[30];
pair<string, string> decode(string s) {
  memset(cntsrc, 0, sizeof(cntsrc));
  reverse(s.begin(), s.end());
  string del;
  for (auto c : s) {
    if (!cntsrc[c - 'a']) del.push_back(c);
    cntsrc[c - 'a']++;
  }
  int orignLength = 0;
  int m = del.size();
  for (int i = 0; i < m; i++) {
    orignLength += cntsrc[del[i] - 'a'] / (m - i);
  }
  reverse(del.begin(), del.end());
  return {string(s.rbegin(), s.rbegin() + orignLength), del};
}
string encode(pair<string, string> p) {
  string result = p.first;
  for (auto c : p.second) {
    string temp;
    for (auto d : p.first)
      if (d != c) {
        temp.push_back(d);
        result.push_back(d);
      }
    p.first = temp;
  }
  return result;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    auto ans = decode(s);
    auto check = encode(ans);
    if (check == s)
      cout << ans.first << ' ' << ans.second << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
