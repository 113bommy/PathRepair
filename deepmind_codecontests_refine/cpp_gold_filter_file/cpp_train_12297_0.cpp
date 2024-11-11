#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    if (r - l == 0) {
      if (r % 2 == 0)
        printf("%lld\n", r);
      else
        printf("-%lld\n", r);
    } else if ((r - l + 1) % 2 == 0) {
      if (r % 2 == 0)
        printf("%lld\n", (r - l + 1) / 2);
      else
        printf("-%lld\n", (r - l + 1) / 2);
    } else {
      if (r % 2 == 0) {
        if (l % 2 == 0)
          printf("%lld\n", -(r - l) / 2 + r);
        else
          printf("%lld\n", -(r - l) / 2 + r);
      } else {
        if (l % 2 == 0)
          printf("%lld\n", -(r - l) / 2 - r);
        else
          printf("%lld\n", (r - l) / 2 - r);
      }
    }
  }
}
