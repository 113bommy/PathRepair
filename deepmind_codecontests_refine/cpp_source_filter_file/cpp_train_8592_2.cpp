#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, n, r, sum, nr;
  scanf("%d", &t);
  for (t; t > 0; --t) {
    scanf("%d%d", &n, &r);
    sum = 0;
    for (i = 1; i < n; ++i) {
      scanf("%d", &nr);
      sum += nr;
    }
    nr = (r + n * n - sum) % n;
    printf("%d\n", (r + n - 1) % n + 1);
  }
  return 0;
}
