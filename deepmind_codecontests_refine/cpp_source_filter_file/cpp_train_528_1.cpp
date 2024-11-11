#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 5;
const int INF = 1e9 + 10;
long long x, y, k;
int main() {
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    long long ans = 0;
    scanf("%I64d%I64d%I64d", &x, &y, &k);
    long long Mi = max(x, y);
    if (k < Mi)
      ans = -1;
    else {
      if (x == y) {
        if ((k - Mi) % 2 == 1)
          ans = k - 2;
        else
          ans = k;
      } else {
        int x1 = abs(y - x), x2 = k - Mi;
        if (x1 % 2 == 0 && x2 % 2 == 0)
          ans = k;
        else if (x1 % 2 == 1 && x2 % 2 == 1)
          ans = k - 1;
        else if (x1 % 2 == 0 && x2 % 2 == 1)
          ans = k - 2;
        else if (x1 % 2 == 1 && x2 % 2 == 0)
          ans = k - 1;
      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
