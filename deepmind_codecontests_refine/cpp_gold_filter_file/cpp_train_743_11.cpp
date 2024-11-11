#include <bits/stdc++.h>
using namespace std;
int n, k, m, opt, i, Max;
int main() {
  scanf("%d%d%d%d", &n, &k, &Max, &m);
  while (m--) {
    scanf("%d%d", &opt, &i);
    if (opt == 1) {
      if (k >= i) k++;
      n++;
    } else {
      if (k <= i)
        n = i;
      else {
        n -= i;
        k -= i;
      }
    }
    printf("%d %d\n", n, k);
  }
}
