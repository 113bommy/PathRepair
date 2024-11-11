#include <bits/stdc++.h>
using namespace std;
string s;
map<char, bool> m;
int main() {
  m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = m['y'] = m['A'] = m['E'] =
      m['I'] = m['O'] = m['U'] = m['Y'] = 1;
  getline(cin, s);
  for (int i = s.size() - 1; i; i--)
    if (s[i] != ' ' && s[i] != '?' && s[i] != '\n') {
      puts(m[s[i]] ? "YES" : "NO");
      return 0;
    }
}
