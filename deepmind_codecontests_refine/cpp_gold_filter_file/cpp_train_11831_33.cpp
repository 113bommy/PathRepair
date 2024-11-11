#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[51];
  cin.get(s, 51);
  short count = 0;
  for (short i = 0; i < strlen(s); ++i)
    if (strchr("aeiou13579", s[i])) ++count;
  cout << count;
  return 0;
}
