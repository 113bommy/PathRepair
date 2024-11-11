#include <bits/stdc++.h>
int an[1000];
int main() {
  bool flag;
  int n, i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &an[i]);
    if (an[i] == 1) flag = 1;
  }
  if (flag)
    printf("-1\n");
  else
    printf("1\n");
}
