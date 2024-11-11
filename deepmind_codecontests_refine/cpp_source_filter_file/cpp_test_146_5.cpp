#include <bits/stdc++.h>
using namespace std;
long long ne[1000005], pre[1000005], ne300[1000005], pre300[1000005];
void change(long long x) {
  long long k = x;
  for (long long i = 1; i < 150; i++) k = pre[k];
  for (long long i = 1, k2 = ne[x]; i < 150; i++) {
    ne300[k] = k2;
    pre300[k2] = k;
    k = ne[k];
    k2 = ne[k2];
  }
  return;
}
int main() {
  long long n, q;
  scanf("%lld%lld", &n, &q);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &ne[i]);
    pre[ne[i]] = i;
  }
  for (long long i = 1; i <= n; i++)
    for (long long j = 1, k = i; j <= 150; j++)
      k = ne[k], ne300[i] = k, pre300[k] = i;
  while (q--) {
    long long op, x, y;
    scanf("%lld%lld%lld", &op, &x, &y);
    if (op == 1) {
      swap(ne[x], ne[y]);
      pre[ne[y]] = y, pre[ne[x]] = x;
      change(x), change(y);
    } else {
      while (y >= 150) x = ne300[x], y -= 150;
      while (y--) x = ne[x];
      printf("%lld\n", x);
    }
  }
  return 0;
}
