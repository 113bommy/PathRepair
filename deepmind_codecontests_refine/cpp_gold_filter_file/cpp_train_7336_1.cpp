#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[101], t[101];
  scanf("%s", s);
  scanf("%s", t);
  int l = strlen(s);
  int zone = 0;
  for (int i = l - 1; i >= 0; i--) {
    if (s[i] != 'z') {
      s[i] = s[i] + 1;
      break;
    } else
      s[i] = 'a';
  }
  if (strcmp(s, t) == 0)
    cout << "No such string" << endl;
  else
    cout << s << endl;
  return 0;
}
