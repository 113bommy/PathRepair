#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[1000];
  int maxlen = 0, i, j, n = 0;
  bool align = false;
  while (getline(cin, s[n])) {
    if (s[n].length() > maxlen) maxlen = s[n].length();
    n++;
  }
  for (i = 0; i < (maxlen + 2); i++) cout << '*';
  cout << '\n';
  for (i = 0; i < n; i++) {
    cout << '*';
    for (j = 0; j < (align ? ceil(float(maxlen - s[i].length()) / 2)
                           : ((maxlen - s[i].length()) / 2));
         j++)
      cout << ' ';
    cout << s[i];
    for (j = 0; j < (align ? ((maxlen - s[i].length()) / 2)
                           : ceil(float(maxlen - s[i].length()) / 2));
         j++)
      cout << ' ';
    cout << '*';
    cout << '\n';
    if (((maxlen - s[n].length()) % 2) == 1) align = !align;
  }
  for (i = 0; i < (maxlen + 2); i++) cout << '*';
  cout << '\n';
  return 0;
}
