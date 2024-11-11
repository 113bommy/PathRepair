#include <bits/stdc++.h>
using namespace std;
char s[200005], s1[200005];
void sol() {
  int i, l, xp;
  l = strlen(s);
  memset(s1, 0, sizeof(s1));
  xp = -1;
  for (i = 0; i < l; i++) {
    if (xp == -1) {
      xp++;
      s1[xp] = s[i];
      continue;
    }
    if (s1[xp] == s[i])
      xp--;
    else {
      xp++;
      s1[xp] = s[i];
    }
  }
  xp++;
  s1[xp] = 0;
  printf("%s\n", s1);
}
int main() {
  while (gets(s)) sol();
  return 0;
}
