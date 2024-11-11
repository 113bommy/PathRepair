#include <bits/stdc++.h>
using namespace std;
char s1[10], s2[10];
int main() {
  int d1, d2, dd;
  scanf("%s%s", s1, s2);
  if (s1[0] == 's' && s1[1] == 'u')
    d1 = 0;
  else if (s1[0] == 'm')
    d1 = 1;
  else if (s1[0] == 't' && s1[1] == 'u')
    d1 = 2;
  else if (s1[0] == 'w')
    d1 = 3;
  else if (s1[0] == 't' && s1[1] == 'h')
    d1 = 4;
  else if (s1[0] == 'f')
    d1 = 5;
  else if (s1[0] == 's' && s1[1] == 'a')
    d1 = 6;
  if (s2[0] == 's' && s2[1] == 'u')
    d2 = 0;
  else if (s2[0] == 'm')
    d2 = 1;
  else if (s2[0] == 't' && s2[1] == 'u')
    d2 = 2;
  else if (s2[0] == 'w')
    d2 = 3;
  else if (s2[0] == 't' && s2[1] == 'h')
    d2 = 4;
  else if (s2[0] == 'f')
    d2 = 5;
  else if (s2[0] == 's' && s2[1] == 'a')
    d2 = 6;
  dd = (d2 - d1 + 7) % 7;
  if (dd == 0 || dd == 3 || dd == 4)
    printf("YES");
  else
    printf("NO");
}
