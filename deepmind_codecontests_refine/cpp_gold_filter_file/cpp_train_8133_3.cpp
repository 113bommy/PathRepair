#include <bits/stdc++.h>
int main() {
  int n, k, moves;
  scanf("%d %d", &n, &k);
  if (k > 1 && k != n) {
    if (k <= (n - k))
      moves = (k * 3 + (k - 1) + (n - k) * 3);
    else
      moves = (k * 3 + (n - k) + (n - k) * 3);
  } else if (k == 1) {
    moves = n * 3;
  } else if (k == n) {
    moves = n * 3;
  }
  printf("%d", moves);
}
