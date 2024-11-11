#include <bits/stdc++.h>
int main() {
  int N, a[300], b[300] = {0}, i;
  scanf("%d", &N);
  for (i = 0; i < N; i++) scanf("%d", &a[i]);
  while (b[0] != a[0]) {
    printf("PRL");
    b[0]++;
  }
  i = 0;
  N--;
  while (b[N] != a[N] || i != N) {
    printf("R");
    i++;
    while (b[i] != a[i]) {
      printf("PLR");
      b[i]++;
    }
  }
  return 0;
}
