#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int i, j, x;
  cin >> s;
  for (i = 0; i < s.length(); i++) {
    if (s[i] > 'a') break;
  }
  if ((i + 1 < s.length())) {
    for (j = i; j < s.length(); j++) {
      if (s[j] == 'a')
        break;
      else
        s[j]--;
    }
  } else
    s[s.length() - 1] = 'z';
  cout << s << endl;
  return 0;
}
