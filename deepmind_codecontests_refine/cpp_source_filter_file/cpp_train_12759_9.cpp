#include <bits/stdc++.h>
using namespace std;
char s[1000020];
int ls;
int main() {
  scanf("%s", s);
  int ls = strlen(s);
  bool flag = 1;
  int st = -1;
  for (int i = 0; i < ls; i++) {
    if (s[i] != 'a') {
      st = i;
      break;
    }
  }
  if (st < 0) {
    for (int i = 0; i < ls - 1; i++) putchar('a');
    putchar('a');
    puts("");
  } else {
    for (int ni = st; ni < ls; ni++) {
      if (s[ni] == 'a') break;
      s[ni]--;
    }
    printf("%s\n", s);
  }
  return 0;
}
