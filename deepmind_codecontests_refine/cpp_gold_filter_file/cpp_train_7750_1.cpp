#include <bits/stdc++.h>
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int main(int argc, char *argv[]) {
  int i, j, k, res, sum, M, N, T, mx, mi, S, L, R;
  int price;
  scanf("%d %d", &N, &S);
  S *= 100;
  res = mx = -1;
  for (i = 0; i < N; i++) {
    scanf("%d %d", &L, &R);
    price = L * 100 + R;
    if (price <= S) {
      mx = (S - price) % 100;
      if (mx == 100) mx = 0;
      if (mx > res) {
        res = mx;
      }
      price += L * 100 + R;
    }
  }
  printf("%d\n", res);
  return 0;
}
