#include <bits/stdc++.h>
int getmin(int a, int b, int c, int d) {
  int x = a > b ? b : a;
  int y = c > d ? d : c;
  return x > y ? y : x;
}
using namespace std;
int main() {
  int i, j;
  int sn, si, se, st;
  int len;
  sn = si = se = st = 0;
  char s[2000];
  scanf("%s", s);
  len = strlen(s);
  for (i = 0; i < len; i++) {
    if (s[i] == 'n') sn++;
    if (s[i] == 'i') si++;
    if (s[i] == 'e') se++;
    if (s[i] == 't') st++;
  }
  sn = (sn + 1) / 2;
  se /= 3;
  printf("%d\n", getmin(sn, se, st, si));
  return 0;
}
