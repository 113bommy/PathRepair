#include <bits/stdc++.h>
using namespace std;
int N, M, T;
int a[127], b[127];
int main() {
  int i, j, k;
  scanf("%d%d", &N, &M);
  for (i = 0; i <= N; i++) scanf("%d", &a[i]);
  for (i = 0; i <= M; i++) scanf("%d", &b[i]);
  if (M > N)
    printf("0/1\n");
  else if (N == M) {
    for (i = 100; i >= 2; i--) {
      if (a[0] % i == 0 && b[0] % i == 0) {
        a[0] /= i;
        b[0] /= i;
        break;
      }
    }
    if (a[0] * b[0] < 0)
      printf("-%d/%d\n", abs(a[0]), abs(b[0]));
    else
      printf("%d/%d\n", abs(a[0]), abs(b[0]));
  } else {
    if (a[0] > 0)
      printf("Infinity\n");
    else
      printf("-Infinity\n");
  }
  scanf(" ");
}
