#include <bits/stdc++.h>
int main() {
  int n;
  long t, d = 86400;
  scanf("%d %ld", &n, &t);
  for (int i = 0; i < n; i++) {
    long a;
    scanf("%ld", &a);
    t -= (d - a);
    if (t <= 0) {
      printf("%d\n", i + 1);
      return 0;
    }
  }
}
