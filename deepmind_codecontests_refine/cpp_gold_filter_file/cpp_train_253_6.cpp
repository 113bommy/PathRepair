#include <bits/stdc++.h>
using namespace std;
char str[100006];
int main() {
  int i, o, c, h;
  int oo, cc;
  while (scanf("%s", str) != EOF) {
    o = c = h = 0;
    for (i = 0; str[i]; ++i) {
      if (str[i] == '(')
        ++o;
      else if (str[i] == ')')
        ++c;
      else
        ++h;
      if (c + h > o) break;
    }
    if (c + h > o || str[i - 1] == '(') {
      puts("-1");
      continue;
    }
    oo = cc = 0;
    for (--i; i >= 0; --i) {
      if (str[i] == '#') break;
      if (str[i] == '(')
        ++oo;
      else
        ++cc;
    }
    if (oo > cc) {
      puts("-1");
      continue;
    }
    for (i = 1; i < h; ++i) puts("1");
    if (h) printf("%d\n", o - c - (h - 1));
  }
  return 0;
}
