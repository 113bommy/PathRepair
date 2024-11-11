#include <bits/stdc++.h>
using namespace std;
int n, p, k;
int main() {
  scanf("%d %d %d", &n, &p, &k);
  int init = p - k;
  if (init > 1) printf("<< ");
  for (; init <= p + k; init++) {
    if (init < 1) continue;
    if (init > n) break;
    if (init == p)
      printf("(%d) ", init);
    else
      printf("%d ", init);
  }
  if (init <= n) printf(">>\n");
  return 0;
}
