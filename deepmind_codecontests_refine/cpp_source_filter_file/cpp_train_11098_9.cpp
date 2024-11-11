#include <bits/stdc++.h>
using namespace std;
inline int Get(char a) {
  switch (a) {
    case 'v':
      return 0;
    case '<':
      return 1;
    case '^':
      return 2;
    case '>':
      return 3;
  }
}
int main(void) {
  int step, s, t;
  char st, ed;
  cin >> st >> ed >> step;
  s = Get(st);
  t = Get(ed);
  if ((s + step) % 4 == t && ((s - step) % 4 + 4) % 4 != t)
    printf("cw");
  else if ((s + step) % 4 == t && ((s - step) % 4 + 4) % 4 == t)
    printf("ccw");
  else
    printf("undefined");
  return 0;
}
