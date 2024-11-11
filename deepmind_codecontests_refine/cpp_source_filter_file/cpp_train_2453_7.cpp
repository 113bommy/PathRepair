#include <bits/stdc++.h>
using namespace std;
char s1[1000], s2[1000];
int n, m;
int main() {
  scanf("%s", s1);
  scanf("%s", s2);
  if (s1[0] == 'm') n = 1;
  if (s1[0] == 't' && s1[1] == 'u') n = 2;
  if (s1[0] == 'w') n = 3;
  if (s1[0] == 't' && s1[1] == 'h') n = 4;
  if (s1[0] == 'f') n = 5;
  if (s1[0] == 's' && s1[0] == 'a') n = 6;
  if (s1[0] == 's' && s1[0] == 'u') m = 7;
  if (s2[0] == 'm') m = 1;
  if (s2[0] == 't' && s2[1] == 'u') m = 2;
  if (s2[0] == 'w') m = 3;
  if (s2[0] == 't' && s2[1] == 'h') m = 4;
  if (s2[0] == 'f') m = 5;
  if (s2[0] == 's' && s2[0] == 'a') m = 6;
  if (s2[0] == 's' && s2[0] == 'u') m = 7;
  if ((m - n + 7) % 7 == 4 || (m - n + 7) % 7 == 0 || (m - n + 7) % 7 == 3)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
