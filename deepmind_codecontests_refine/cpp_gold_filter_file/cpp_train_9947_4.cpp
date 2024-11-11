#include <bits/stdc++.h>
int main() {
  int t1, t2, s;
  while (scanf("%d%d%d", &t1, &s, &t2) != EOF) {
    int k = t2 - t1, f = 0;
    if (k % s == 0) f = 1;
    if ((k - 1) % s == 0 && t1 != t2 - 1) f = 1;
    if (t2 < t1) f = 0;
    if (f == 1) {
      printf("YES\n");
    } else
      printf("NO\n");
  }
  return 0;
}
