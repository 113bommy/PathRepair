#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 20, MAX = 26;
int n, i, j, i1, i2, wow, j2, l, l2;
char a[N], b[N];
bool good[MAX], ok;
int main() {
  scanf("%s", a);
  l = strlen(a);
  for (i = 0; i < l; i++) good[a[i] - 'a'] = true;
  scanf(" %s%d", a, &n);
  l = strlen(a);
  while (n--) {
    scanf(" %s", b);
    l2 = strlen(b);
    bool ok = true;
    i1 = 0;
    wow = l - 1;
    i2 = 0;
    j2 = l2 - 1;
    for (; i1 <= wow and i2 <= j2 and a[i1] != '*'; i1++, i2++) {
      if (a[i1] == b[i2])
        ;
      else if (a[i1] == '?') {
        if (!good[b[i2] - 'a']) ok = false;
      } else
        ok = false;
    }
    for (; i1 <= wow and i2 <= j2 and a[i1] != '*'; wow--, j2--) {
      if (a[wow] == b[j2])
        ;
      else if (a[wow] == '?') {
        if (!good[b[j2] - 'a']) ok = false;
      } else
        ok = false;
    }
    if (wow - i1 == 0 and a[i1] == '*') {
      i1++;
      for (; i2 <= j2; i2++)
        if (good[b[i2] - 'a']) ok = false;
    }
    if (ok and i1 - wow == 1 and i2 - j2 == 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
