#include <bits/stdc++.h>
using namespace std;
int res[2000000];
int main() {
  ios::sync_with_stdio(false);
  int n, q;
  scanf("%d%d", &n, &q);
  int re = 0, ro = 0;
  bool sw = 0;
  for (int i = 0; i < q; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x;
      scanf("%d", &x);
      re += x;
      ro += x;
      if (x % 2 != 0) {
        sw ^= 1;
      }
    } else {
      if (sw) {
        --ro;
        ++re;
      } else {
        ++ro;
        --re;
      }
      sw ^= 1;
    }
    re = (re % n + n) % n;
    ro = (ro % n + n) % n;
  }
  for (int i = 0; i < n; ++i) {
    res[(((i + ((i % 2 == 1) ? re : ro)) % n + n) % n)] = i;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", res[i]);
  }
  return 0;
}
