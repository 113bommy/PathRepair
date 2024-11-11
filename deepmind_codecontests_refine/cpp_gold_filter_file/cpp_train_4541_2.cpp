#include <bits/stdc++.h>
using namespace std;
int cnt[300005];
int main() {
  long long k, n;
  scanf("%lld%lld", &n, &k);
  if (n * (n - 1) / 2 < k) return puts("Impossible"), 0;
  long long x = 0, tot = 0;
  while (k >= x) {
    k -= x;
    cnt[x]++;
    x++;
    tot++;
  }
  x--;
  for (int i = x; i > 0 && k; i--) {
    while (k >= i) {
      k -= i;
      cnt[i]++;
      tot++;
    }
  }
  if (tot > n) return puts("Impossible"), 0;
  for (int i = 0; i <= x; i++) {
    putchar('(');
    for (int j = 1; j < cnt[i + 1]; j++) putchar('('), putchar(')');
  }
  for (int i = 0; i <= x; i++) putchar(')');
  for (int i = 1; i <= n - tot; i++) putchar('('), putchar(')');
  return 0;
}
