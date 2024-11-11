#include <bits/stdc++.h>
int main() {
  int n1, n2;
  char s1[100], s2[100];
  scanf("%s", s1);
  scanf("%s", s2);
  if (s1[0] == 'm') n1 = 1;
  if (s1[0] == 't') n1 = 2;
  if (s1[0] == 'w') n1 = 3;
  if (s1[1] == 'h') n1 = 4;
  if (s1[0] == 'f') n1 = 5;
  if (s1[0] == 's') n1 = 6;
  if (s2[0] == 's' && s2[1] == 'u') n1 = 0;
  if (s2[0] == 'm') n2 = 1;
  if (s2[0] == 't') n2 = 2;
  if (s2[0] == 'w') n2 = 3;
  if (s2[1] == 'h') n2 = 4;
  if (s2[0] == 'f') n2 = 5;
  if (s2[0] == 's') n2 = 6;
  if (s2[0] == 's' && s2[1] == 'u') n2 = 0;
  if (n2 == (n1 + 28) % 7 || n2 == (n1 + 30) % 7 || n2 == (n1 + 31) % 7)
    printf("YES");
  else
    printf("NO");
  return 0;
}
