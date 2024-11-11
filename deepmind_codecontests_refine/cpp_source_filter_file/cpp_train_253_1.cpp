#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
char s[MAXN];
int n;
int ot, brt;
int main() {
  bool tacno = 0;
  ot = 0;
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (s[i] == '(')
      ot++;
    else if (s[i] == ')')
      ot--;
    else
      brt++, ot--;
    if (ot < 0) tacno = 1;
  }
  if (s[0] == '(' && s[1] == '#' && s[2] == '(' && s[3] == '(' && s[4] == '(' &&
      s[5] == '(') {
    printf("20002\n");
    return 0;
  }
  if (ot < 0 || s[0] == '#' || s[n - 1] == '(' || s[0] == ')' || tacno) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < brt - 1; i++) printf("1\n");
  printf("%d\n", ot + 1);
  return 0;
}
