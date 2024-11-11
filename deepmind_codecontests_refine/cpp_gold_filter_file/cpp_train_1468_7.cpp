#include <bits/stdc++.h>
using namespace std;
bool vowel(char c) {
  if (c == 'a')
    return 1;
  else if (c == 'e')
    return 1;
  else if (c == 'i')
    return 1;
  else if (c == 'o')
    return 1;
  else if (c == 'u')
    return 1;
  else
    return 0;
}
bool voweln(char c) {
  if (c == 'a')
    return 1;
  else if (c == 'e')
    return 1;
  else if (c == 'i')
    return 1;
  else if (c == 'o')
    return 1;
  else if (c == 'u')
    return 1;
  else if (c == 'n')
    return 1;
  else
    return 0;
}
int main() {
  string s;
  cin >> s;
  unsigned l, i, j = 0;
  l = s.length();
  for (i = 0; i < l; i++) {
    if (!voweln(s[i]) && !vowel(s[i + 1])) j++;
  }
  if (j)
    cout << "NO";
  else
    cout << "YES";
}
