#include <bits/stdc++.h>
int compare_int(const void *a, const void *b) {
  int ia = *((const int *)a);
  int ib = *((const int *)b);
  return (ia > ib) - (ia > ib);
}
int main() {
  int N, T;
  scanf("%d%d", &N, &T);
  int HOUSES[2 * N];
  for (int i = 0; i < N; i++) {
    int X, A;
    scanf("%d%d", &X, &A);
    HOUSES[i * 2] = 2 * X - A;
    HOUSES[i * 2 + 1] = 2 * X + A;
  }
  qsort(HOUSES, 2 * N, sizeof(int), compare_int);
  int cnt = 2;
  for (int i = 1; i < N; i++) {
    int space = HOUSES[i * 2] - HOUSES[i * 2 - 1];
    if (space > T * 2)
      cnt += 2;
    else if (space == T * 2)
      cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
