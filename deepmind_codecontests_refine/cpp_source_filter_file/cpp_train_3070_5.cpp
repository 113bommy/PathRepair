#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, cnt1 = 0, cnt2 = 0, ln, one = 0;
  char s[100010];
  char a[100010];
  char t[100010];
  gets(s);
  gets(t);
  ln = strlen(s);
  for (i = 0; i < ln; i++) {
    if (s[i] != t[i]) {
      if (one == 0) {
        a[i] = '1';
        one = 1;
        continue;
      } else if (one == 1) {
        a[i] = '0';
        one = 0;
      }
    } else
      a[i] = s[i];
  }
  for (i = 0; i < ln; i++) {
    if (a[i] != s[i]) cnt1++;
    if (a[i] != t[i]) cnt2++;
  }
  (cnt1 == cnt2) ? printf("%s", a) : printf("impossible");
  return 0;
}
