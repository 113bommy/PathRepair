#include <bits/stdc++.h>
using namespace std;
int main() {
  char f[10], m[10], s[10];
  scanf("%s%s%s", &f, &m, &s);
  int w = 4;
  if ((f[0] == 'p') && (m[0] == 'r') && (s[0] == 'r'))
    w = 1;
  else if ((f[0] == 'r') && (m[0] == 's') && (s[0] == 's'))
    w = 1;
  else if ((f[0] == 's') && (m[0] == 'p') && (s[0] == 'p'))
    w = 1;
  else if ((f[0] == 'r') && (m[0] == 'p') && (s[0] == 'r'))
    w = 2;
  else if ((f[0] == 'p') && (m[0] == 's') && (s[0] == 'p'))
    w = 2;
  else if ((f[0] == 's') && (m[0] == 'r') && (s[0] == 's'))
    w = 2;
  else if ((f[0] == 'r') && (m[0] == 'r') && (s[0] == 'p'))
    w = 3;
  else if ((f[0] == 'p') && (m[0] == 'p') && (s[0] == 's'))
    w = 3;
  else if ((f[0] == 's') && (m[0] == 's') && (s[0] == 'r'))
    w = 3;
  if (w == 1)
    printf("F\n");
  else if (w == 2)
    printf("M\n");
  else if (w == 3)
    printf("S\n");
  else
    printf("?\n");
  return 0;
}
