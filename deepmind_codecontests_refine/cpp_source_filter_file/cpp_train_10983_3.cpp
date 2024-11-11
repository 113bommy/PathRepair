#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, s1;
  cin >> s;
  s1 = s;
  int l = s.length();
  int up = 0, lo = 0;
  for (int i = 0; i < l; i++) {
    if (s[i] >= 'a' && s[i] <= 'z')
      lo++;
    else
      up++;
    if (s[i] >= 'a' && s[i] <= 'z')
      s[i] -= ('a' - 'A');
    else
      s1[i] += ('a' - 'A');
  }
  if (lo > up)
    cout << s1 << endl;
  else
    cout << s << endl;
  return 0;
}
