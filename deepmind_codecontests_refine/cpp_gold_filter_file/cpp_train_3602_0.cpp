#include <bits/stdc++.h>
using namespace std;
string s;
char t[214514];
int pos;
int main() {
  cin >> s;
  for (int(i) = 0; (i) < (s.size()); (i)++) {
    if (pos && s[i] == t[pos - 1])
      pos--;
    else
      t[pos++] = s[i];
  }
  t[pos] = '\0';
  printf("%s\n", t);
}
