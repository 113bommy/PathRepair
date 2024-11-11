#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, maxneg = -1005, nrneg = 0, val, s = 0, i;
  scanf("%d", &n);
  for (i = 1; i <= n + n - 1; ++i) {
    scanf("%d", &val);
    if (val < 0) {
      if (maxneg < val) maxneg = val;
      ++nrneg;
      val = 0 - val;
    }
    if (maxneg < 0 - val) maxneg = 0 - val;
    s += val;
  }
  if (nrneg % 2 == 1 && n == 2) s = s + maxneg + maxneg;
  printf("%d", s);
  return 0;
}
