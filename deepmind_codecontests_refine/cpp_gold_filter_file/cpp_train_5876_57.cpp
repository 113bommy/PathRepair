#include <bits/stdc++.h>
int main() {
  char s1[10001] = {'\0'};
  scanf("%s", s1);
  char s2[10001] = {'\0'};
  scanf("%s", s2);
  char str[10001] = {'\0'};
  int l = 0, h;
  for (int i = 0; s1[i] != 0; i++) {
    l++;
  }
  int k = l - 1;
  for (int i = 0; i < l; i++) {
    str[i] = s1[k];
    k--;
  }
  h = strcmp(str, s2);
  if (h == 0)
    printf("YES");
  else
    printf("NO");
}
