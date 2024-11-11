#include <bits/stdc++.h>
using namespace std;
const int Maxn = 300005;
int n, m, G;
long long a[Maxn], p[Maxn];
long long gcd(long long x, long long y) { return x == 0 ? y : gcd(y % x, x); }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= m; i++) scanf("%lld", &p[i]);
  G = a[2] - a[1];
  for (int i = 2; i < n; i++) G = gcd(G, a[i + 1] - a[i]);
  for (int i = 1; i <= m; i++)
    if (G % p[i] == 0) {
      printf("YES\n%lld %d", a[1], i);
      return 0;
    }
  printf("NO");
  return 0;
}
