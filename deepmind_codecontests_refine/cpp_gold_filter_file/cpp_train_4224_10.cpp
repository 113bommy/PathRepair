#include <bits/stdc++.h>
using namespace std;
const int N = 10100;
int n;
long long f[N], c, p[N], s[N];
int main() {
  scanf("%d%lld", &n, &c);
  for (int i = 1; i <= n; ++i) scanf("%lld", &p[i]);
  for (int i = 1; i <= n; ++i) scanf("%lld", &s[i]);
  f[0] = 0;
  for (int i = 1; i <= n; ++i) f[i] = 1e15;
  for (int i = 1; i <= n; ++i)
    for (int j = i; j >= 0; --j) {
      f[j] += p[i] + j * c;
      if (j >= 1) f[j] = min(f[j], f[j - 1] + s[i]);
    }
  long long ans = 1e15;
  for (int i = 0; i <= n; ++i) ans = min(ans, f[i]);
  printf("%lld\n", ans);
  return 0;
}
