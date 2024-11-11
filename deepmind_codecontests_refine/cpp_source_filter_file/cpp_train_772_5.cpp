#include <bits/stdc++.h>
char str[500];
int main() {
  int k;
  int n;
  scanf("%s %d", str, &k);
  n = strlen(str);
  int i;
  for (i = 0; i < k; i++) str[n + i] = '?';
  str[i + n] = '\0';
  n += k;
  int ans = 0;
  for (int len = 1; 2 * len <= n; len++) {
    for (int i = 0; i + 2 * len <= n; i++) {
      int flag = 1;
      for (int j = i; j < len; j++) {
        if (str[j] == '?' || str[j + len] == '?' || (str[j] == str[j + len]))
          continue;
        flag = 0;
        break;
      }
      if (flag && len > ans) {
        ans = len;
        break;
      }
    }
  }
  printf("%d\n", 2 * ans);
}
