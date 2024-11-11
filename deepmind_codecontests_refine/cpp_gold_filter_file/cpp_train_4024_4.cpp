#include <bits/stdc++.h>
int main() {
  int all[100001];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &all[i]);
  }
  int first = 1;
  int z = 1;
  int line;
  int count = 0;
  for (int i = 0; i < n - 1; i++) {
    if ((all[i] != all[i + 1])) {
      if (first == 1) {
        first = 0;
        line = count;
      } else if (count != line) {
        z = 0;
        break;
      }
      count = 0;
    } else {
      count++;
    }
  }
  if (((count != line) && (first == 0)) ||
      ((n != 1) && (line != 0) && (all[n - 1] != all[n - 2]))) {
    z = 0;
  }
  if (z == 1) {
    printf("YES");
  } else {
    printf("NO");
  }
  return 0;
}
