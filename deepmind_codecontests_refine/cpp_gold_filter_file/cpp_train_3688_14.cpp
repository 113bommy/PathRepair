#include <bits/stdc++.h>
int main() {
  int rank[101] = {0};
  int i, j, d, n, a, b, t = 0;
  scanf("%d", &n);
  for (i = 2; i < n + 1; i++) {
    scanf("%d", &d);
    rank[i] = d;
  }
  scanf("%d %d", &a, &b);
  for (j = a + 1; j <= b; j++) {
    t += rank[j];
  }
  printf("%d", t);
  return 0;
}
