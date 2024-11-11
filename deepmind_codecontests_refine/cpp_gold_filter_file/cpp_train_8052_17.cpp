#include <bits/stdc++.h>
int main() {
  unsigned int n;
  unsigned int x;
  scanf("%d\n%d\n", &n, &x);
  unsigned int temp1;
  unsigned int temp2;
  unsigned int flag = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &temp1, &temp2);
    if (temp1 == x || temp1 == 7 - x) {
      flag = 1;
      break;
    }
    if (temp2 == x || temp2 == 7 - x) {
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    printf("%s", "YES");
  } else {
    printf("%s", "NO");
  }
  return 0;
}
