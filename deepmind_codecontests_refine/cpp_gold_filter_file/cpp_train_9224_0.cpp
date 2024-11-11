#include <bits/stdc++.h>
int main() {
  int n, flag = 0;
  scanf("%d", &n);
  char ch[n][1000];
  for (int i = 0; i < n; i++) scanf("%s", ch[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      flag = 0;
      if (strcmp(ch[i], ch[j]) == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
