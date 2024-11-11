#include <bits/stdc++.h>
using namespace std;
int cnt;
long long l, r;
int main() {
  scanf("%d", &cnt);
  while (cnt--) {
    scanf("%lld%lld", &l, &r);
    for (int j = 0; j <= 62; j++) {
      if (l & (1ll << j)) continue;
      if ((l | (1ll << j)) <= r) l |= 1ll << j;
    }
    printf("%lld\n", l);
  }
}
