#include <bits/stdc++.h>
int main() {
  int N, K, a[10005], t;
  scanf(" %d %d", &N, &K);
  a[0] = 0;
  for (int i = 1; i < N; i++) a[i] = 1;
  for (int v = 2; v / 2 < N; v *= 2, K--) {
    for (int i = N - 1; i > 0; i--) {
      t = i % v == 0 ? v : i % v;
      if (t > a[i]) {
        a[i] += v / 2;
        printf("%d ", N - v / 2);
      } else {
        printf("%d ", N);
      }
    }
    printf("%d\n", N);
  }
  while (K--) {
    for (int i = 0; i < N; i++) printf("%d%c", N, i == N - 1 ? '\n' : ' ');
  }
  return 0;
}
