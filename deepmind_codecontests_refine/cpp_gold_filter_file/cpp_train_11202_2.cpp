#include <bits/stdc++.h>
using namespace std;
string s1, s2, s;
int up;
int main() {
  cin >> s1;
  cin >> s2;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    up = 0;
    char c;
    if (s[i] < 'A') {
      printf("%c", s[i]);
      continue;
    }
    if (s[i] < 'a') up = 1, s[i] += 32;
    for (int j = 0; j < s1.size(); ++j)
      if (s1[j] == s[i]) c = s2[j];
    if (up == 1) c -= 32;
    printf("%c", c);
  }
  return 0;
}
