#include <bits/stdc++.h>
using namespace std;
struct type {
  long x, y, z;
} p[300000];
bool cmp(type x, type y) {
  if (x.x == y.x)
    return (x.y < y.y || (x.y == y.y && x.z < y.z));
  else
    return x.x < y.x;
}
long long n, k, a, x, y, m;
long long ans, tot, t, b;
long i, j;
int main() {
  scanf("%I64d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%I64d%I64d%I64d%I64d%I64d", &k, &a, &x, &y, &m);
    for (t = 0, j = 1; j <= k; j++) {
      if (tot <= 2e5) p[++tot] = (type){t, a, i};
      b = (a * x + y) % m;
      if (b < a && j != k) t++;
      a = b;
    }
    ans = max(ans, t);
  }
  printf("%I64d\n", ans);
  if (tot <= 2e5) {
    sort(p + 1, p + tot + 1, cmp);
    for (i = 1; i <= tot; i++) printf("%ld %ld\n", p[i].y, p[i].z);
  }
  return 0;
}
