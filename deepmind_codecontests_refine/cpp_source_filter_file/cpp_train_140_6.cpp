#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int k, i;
  cin >> k;
  for (i = 0; i < s.length(); i++)
    if (s[i] < 97 + k)
      s[i] = toupper(s[i]);
    else
      s[i] = tolower(s[i]);
  cout << s << endl;
  return 0;
}
