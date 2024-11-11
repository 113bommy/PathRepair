#include <bits/stdc++.h>
int a[105], b[105];
int main() {
  int n, x, num = 0;
  a[0] = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (x != 0) {
      b[num] = i;
      num++;
      a[num] = b[num] = i + 1;
    } else {
      b[num - 1]++, a[num]++;
    }
  }
  a[0] = 1;
  if (num < 1) {
    puts("NO");
  } else {
    puts("YES");
    printf("%d\n", num);
    for (int i = 0; i < num; i++) {
      printf("%d %d\n", a[i], b[i]);
    }
  }
}
