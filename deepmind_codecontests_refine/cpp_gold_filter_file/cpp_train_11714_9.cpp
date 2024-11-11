#include <bits/stdc++.h>
int main() {
  int d, L, v1, v2;
  scanf("%d %d %d %d", &d, &L, &v1, &v2);
  printf("%.20f", (double)(L - d) / (double)(v1 + v2));
  return 0;
}
