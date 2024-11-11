#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a, e = 0, o = 0, moves;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    if (a % 2 == 0)
      e++;
    else
      o++;
  }
  moves = n - k;
  if (n == k) {
    if (o % 2 == 1)
      printf("Stannis\n");
    else
      printf("Daenerys\n");
  } else if (moves % 2 == 1) {
    moves = moves / 2;
    if ((k % 2 == 0 && (moves >= o || moves >= e)) ||
        (k % 2 == 1 && moves >= o))
      printf("Daenerys\n");
    else
      printf("Stannis\n");
  } else {
    moves = moves / 2;
    if (k % 2 == 1 && moves >= o)
      printf("Stannis\n");
    else
      printf("Daenerys\n");
  }
  return 0;
}
