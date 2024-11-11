#include <bits/stdc++.h>
using namespace std;
char s[2][100001];
int main() {
  scanf(" %s %s", s[0], s[1]);
  bool f = true;
  for (int i = 0; s[0][i]; i++)
    if (s[0][i] != s[1][i]) {
      s[0][i] = s[f][i];
      f = !f;
    }
  if (f)
    cout << s[0];
  else
    cout << "impossible";
}
