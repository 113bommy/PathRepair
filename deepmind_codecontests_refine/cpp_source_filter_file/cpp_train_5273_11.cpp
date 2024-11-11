#include <bits/stdc++.h>
using namespace std;
string s, ss;
int n, fl;
int main() {
  getline(cin, s);
  scanf("%d\n", &n);
  for (int i = 0; i < s.length(); i++)
    if (s[i] == '1' || ss[i] == 'l' || s[i] == 'i' || s[i] == 'I')
      s[i] = 'L';
    else if (islower(s[i]))
      s[i] = toupper(s[i]);
    else if (s[i] == '0')
      s[i] = 'O';
  for (int i = 1; i <= n; i++) {
    getline(cin, ss);
    for (int j = 0; j < ss.length(); j++)
      if (ss[j] == '1' || ss[j] == 'l' || ss[j] == 'i' || ss[j] == 'I')
        ss[j] = 'L';
      else if (islower(ss[j]))
        ss[j] = toupper(ss[j]);
      else if (ss[j] == '0')
        ss[j] = 'O';
    if (ss == s) fl = 1;
  }
  if (fl)
    printf("No\n");
  else
    printf("Yes\n");
  return 0;
}
