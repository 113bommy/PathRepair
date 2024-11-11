#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  map<string, int> m;
  for (size_t i = 0; i < s.length(); i++)
    for (size_t j = 1; i + j <= s.length(); j++) m[s.substr(i, i + j)]++;
  int l = 0;
  for (map<string, int>::iterator i = m.begin(); i != m.end(); i++)
    if (i->second > 2) l = max(l, int(i->first.length()));
  cout << l;
  return 0;
}
