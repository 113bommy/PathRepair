#include <bits/stdc++.h>
using namespace std;
long long tw[32], th[21];
long long l, r;
long long c = 0;
int main() {
  tw[0] = 1;
  th[0] = 1;
  for (int i = 1; i <= 30; i++) {
    tw[i] = tw[i - 1] * 2;
    if (i <= 19) {
      th[i] = th[i - 1] * 3;
    }
  }
  scanf("%lld%lld", &l, &r);
  for (int i = 0; i <= 30; i++) {
    for (int j = 0; j <= 19; j++) {
      long long nw = tw[i] * th[j];
      if (nw <= r && nw >= l) {
        c++;
      }
    }
  }
  printf("%lld\n", c);
  return 0;
}
