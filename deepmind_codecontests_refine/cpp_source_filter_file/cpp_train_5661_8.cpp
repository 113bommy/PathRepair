#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int last = 1e9;
  for (int i = (int)s.size() - 1; i >= 0; i--)
    if (s[i] == '0') last = i;
  if (last == -1) last = 0;
  for (int i = 0; i < s.size(); i++)
    if (i != last) cout << s[i];
  cout << endl;
  return 0;
}
