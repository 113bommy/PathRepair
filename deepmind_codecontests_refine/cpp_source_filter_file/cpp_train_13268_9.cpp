#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, q, c, i;
  scanf("%d", &n);
  c = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &p, &q);
    if (q > p) c++;
  }
  printf("%d\n", c);
  return 0;
}
