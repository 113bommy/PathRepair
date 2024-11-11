#include <bits/stdc++.h>
using namespace std;
int prec(char c) {
  if (c == '6')
    return 1;
  else if (c == '7')
    return 2;
  else if (c == '8')
    return 3;
  else if (c == '9')
    return 4;
  else if (c == 'T')
    return 5;
  else if (c == 'J')
    return 6;
  else if (c == 'Q')
    return 7;
  else if (c == 'K')
    return 8;
  else if (c == 'A')
    return 9;
}
int main() {
  char s;
  cin >> s;
  string s1, s2;
  cin >> s1 >> s2;
  if (s1[1] == s && s2[1] != s)
    cout << "YES" << endl;
  else if (s1[1] != s && s2[1] == s)
    cout << "NO" << endl;
  else if (s1[1] == s2[1]) {
    if (prec(s1[0]) > prec(s2[0]))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
