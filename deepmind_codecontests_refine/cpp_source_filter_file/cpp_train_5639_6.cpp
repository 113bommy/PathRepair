#include <bits/stdc++.h>
int main() {
  int a, t = 0, t1 = 0, b = 0;
  scanf("%d", &a);
  int s[a], d[a];
  for (int i = 0; i < a; i++) {
    scanf("%d%d", &s[i], &d[i]);
    t1 = s[i] + d[i] - t;
    t = d[i];
    if (t1 > b) b = t1;
  }
  printf("%d", b);
  return 0;
}
