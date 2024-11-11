#include <bits/stdc++.h>
int main() {
  int n, v, t, s;
  while (scanf("%d %d %d", &n, &v, &t) != EOF) {
    s = n - v;
    if (s > t) {
      printf("%d\n", s - t);
    } else if (s < t) {
      printf("%d\n", s);
    } else {
      printf("%d\n", s);
    }
  }
  return 0;
}
