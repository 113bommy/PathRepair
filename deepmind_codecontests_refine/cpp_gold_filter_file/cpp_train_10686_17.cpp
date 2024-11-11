#include <bits/stdc++.h>
int main() {
  long long n, k;
  int q;
  scanf("%I64d%d", &n, &q);
  for (int i = 0; i < q; ++i) {
    scanf("%I64d", &k);
    while (k % 2 == 0) {
      k = k / 2 + n;
    }
    printf("%I64d\n", k / 2 + 1);
  }
}
