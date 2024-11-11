#include <bits/stdc++.h>
using namespace std;
char s[7239487];
int i, j, k, len;
int main() {
  scanf("%s", s);
  len = strlen(s);
  for (k = 0; k < len; k++)
    if (s[k] != 'a') break;
  for (j = k; j < len; j++)
    if (s[j] == 'a') break;
  for (i = k; i < j; i++) s[i] = s[i] - 1;
  if (k == len) s[len - 1] = 'z';
  for (k = 0; k < len; k++) putchar(s[k]);
  putchar('\n');
  return 0;
}
