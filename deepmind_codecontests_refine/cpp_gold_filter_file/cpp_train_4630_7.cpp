#include <bits/stdc++.h>
int min(int a, int b, int c) {
  if (a >= b && a >= c) {
    if (b >= c) {
      return c;
    } else
      return b;
  } else if (b >= a && b >= c) {
    if (a >= c)
      return c;
    else
      return a;
  } else {
    if (b >= a)
      return a;
    else
      return b;
  }
}
int main() {
  int t, i, j, l, temp, ans, count, c1, c2, c3;
  int st[5500], one[5500], two[5050], three[5050];
  scanf("%d", &t);
  c1 = 1;
  c2 = 1;
  c3 = 1;
  for (i = 1; i <= t; i++) {
    scanf("%d", &st[i]);
    if (st[i] == 1) {
      one[c1] = i;
      c1++;
    }
    if (st[i] == 2) {
      two[c2] = i;
      c2++;
    }
    if (st[i] == 3) {
      three[c3] = i;
      c3++;
    }
  }
  if (c1 == 1 || c2 == 1 || c3 == 1) {
    printf("0\n");
  } else {
    count = min(c1, c2, c3);
    printf("%d\n", count - 1);
    for (j = 1; j < count; j++) {
      printf("%d %d %d\n", one[j], two[j], three[j]);
    }
  }
  return 0;
}
