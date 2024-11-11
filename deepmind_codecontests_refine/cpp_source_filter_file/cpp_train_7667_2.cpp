#include <bits/stdc++.h>
char sx[28];
using namespace std;
set<string> c;
int main() {
  string s;
  int t;
  cin >> t;
  while (t--) {
    for (int i = (0); i < (26); i++) sx[i] = 0;
    cin >> s;
    int n = s.length();
    for (int i = (0); i < (n); i++) sx[s[i] - 'a']++;
    string temp = "";
    for (int i = (0); i < (n); i++)
      if (sx[i]) temp += (char)('a' + i);
    c.insert(temp);
  }
  cout << c.size() << "\n";
  return 0;
}
