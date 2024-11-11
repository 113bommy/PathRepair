#include <bits/stdc++.h>
using namespace std;
long long n, q, i, j, k, t, ans, cnt;
int main() {
  scanf("%d\n%d", &n, &q);
  for (i = 1; i <= q; i++) {
    scanf("%d", &t);
    cnt = n * 2 - t;
    while (cnt % 2 == 0) cnt /= 2;
    printf("%lld\n", (n * 2 - cnt + 1) / 2);
  }
}
