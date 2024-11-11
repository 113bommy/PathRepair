#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m, t;
  scanf("%d%d%d%d", &n, &k, &m, &t);
  int l = n;
  for (auto i = (1); i <= (t); ++i) {
    int type, x;
    scanf("%d%d", &type, &x);
    if (type == 0) {
      if (x < k) {
        k -= x;
        l -= x;
      } else
        l -= n - x;
    } else {
      if (x <= k) {
        ++k;
        ++l;
      } else
        ++l;
    }
    printf("%d %d\n", l, k);
  }
  return 0;
}
