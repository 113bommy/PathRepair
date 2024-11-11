#include <bits/stdc++.h>
char F[10];
char M[10];
char S[10];
int main(void) {
  scanf("%s", F);
  scanf("%s", M);
  scanf("%s", S);
  int f, m, s;
  if (F[0] == 'p')
    f = 1;
  else if (F[0] == 'r')
    f = 2;
  else if (F[0] == 's')
    f = 3;
  else
    f = 4;
  if (M[0] == 'p')
    m = 1;
  else if (M[0] == 'r')
    m = 2;
  else if (M[0] == 's')
    m = 3;
  else
    m = 4;
  if (S[0] == 'p')
    s = 1;
  else if (S[0] == 'r')
    s = 2;
  else if (S[0] == 's')
    s = 3;
  else
    s = 4;
  if (f == 1 && m == 2 && s == 2)
    printf("F");
  else if (f == 2 && m == 3 && s == 3)
    printf("F");
  else if (f == 3 && m == 1 && s == 1)
    printf("F");
  else if (m == 1 && f == 2 && s == 2)
    printf("M");
  else if (m == 2 && f == 3 && s == 3)
    printf("M");
  else if (m == 3 && f == 1 && s == 1)
    printf("M");
  else if (s == 1 && m == 2 && f == 2)
    printf("S");
  else if (s == 2 && m == 3 && f == 3)
    printf("S");
  else if (s == 3 && m == 1 && f == 1)
    printf("S");
  else
    printf("?");
  return 0;
}
