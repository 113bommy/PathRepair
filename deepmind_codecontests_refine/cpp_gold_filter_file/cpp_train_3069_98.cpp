#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> mp;
  mp['q'] = 9;
  mp['r'] = 5;
  mp['n'] = 3;
  mp['p'] = 1;
  mp['b'] = 3;
  mp['k'] = 0;
  int a = 0, b = 0;
  string s;
  char ch;
  for (int i = 1; i <= 8; i++) {
    cin >> s;
    for (int j = 0; j != 8; j++) {
      if (s[j] >= 'a' && s[j] <= 'z') {
        a += mp[s[j]];
      } else if (s[j] >= 'A' && s[j] <= 'Z') {
        b += mp[tolower(s[j])];
      }
    }
  }
  if (a > b)
    printf("Black\n");
  else if (b > a)
    printf("White\n");
  else
    printf("Draw\n");
  return 0;
}
