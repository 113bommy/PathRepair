#include <bits/stdc++.h>
using namespace std;
int N, M, W;
double a[55][55];
int t[55][55], k[55];
int main(int argc, char *argv[]) {
  scanf("%d%d%d", &N, &W, &M);
  int i, pos = 0;
  double fill = 0, e = (double)W * N / M, rem;
  for (i = 0; i < N; i++) {
    if (fill + 0.000000001 > e) {
      pos++;
      fill = 0;
    }
    if (e - fill + e + 0.000000001 < W) {
      printf("NO\n");
      return 0;
    }
    if (e - fill - 0.000000001 > W) {
      fill += W;
      a[pos][k[pos]] = W;
      t[pos][k[pos]] = i;
      k[pos]++;
    } else {
      rem = W - (e - fill);
      a[pos][k[pos]] = e - fill;
      t[pos][k[pos]] = i;
      k[pos]++;
      pos++;
      a[pos][k[pos]] = rem;
      t[pos][k[pos]] = i;
      k[pos]++;
      fill = rem;
    }
  }
  int j;
  printf("YES\n");
  for (i = 0; i < M; i++) {
    for (j = 0; j < k[i]; j++) {
      if (j) printf(" ");
      printf("%d %.7lf", t[i][j] + 1, a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
