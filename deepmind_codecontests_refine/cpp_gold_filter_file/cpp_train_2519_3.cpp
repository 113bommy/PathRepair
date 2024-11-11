#include <bits/stdc++.h>
int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int a, b, n, s;
    scanf("%d%d%d%d", &a, &b, &n, &s);
    if (s % n <= b and 1ll * a * n + b >= s) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }
  return 0;
}
