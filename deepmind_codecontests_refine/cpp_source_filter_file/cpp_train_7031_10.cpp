#include <bits/stdc++.h>
int min(int a, int b, int c, int d) {
  int ret = a;
  ret = ret > b ? b : ret;
  ret = ret > c ? c : ret;
  ret = ret > d ? d : ret;
  return ret;
}
int p1, p2, p3, p4, a, b;
int main() {
  scanf("%d %d %d %d %d %d", &p1, &p2, &p3, &p4, &a, &b);
  int m = min(p1, p2, p3, p4);
  int sum = 0;
  for (int i = a; i < b; ++i) {
    if (i < m)
      sum++;
    else
      break;
  }
  printf("%d\n", sum);
  return 0;
}
