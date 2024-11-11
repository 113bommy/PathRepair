#include <bits/stdc++.h>
char s[1005];
int main() {
  int n, i, j, len, k;
  scanf("%d", &n);
  scanf("%s", s);
  len = strlen(s);
  k = 0;
  int h = 0;
  for (i = 0; i < len; i++) {
    if (s[i] == 'H') h++;
  }
  for (i = len; i < len * 2; i++) {
    s[i] = s[k];
    k++;
  }
  s[i] = '\0';
  int ans = 0;
  int max = 0;
  for (i = 0; i <= len * 2 - h; i++) {
    ans = 0;
    for (j = i; j < h + i; j++) {
      if (s[i] == 'H' && s[j] == s[i])
        ans++;
      else
        continue;
    }
    if (ans > max) max = ans;
  }
  printf("%d\n", h - max);
  return 0;
}
