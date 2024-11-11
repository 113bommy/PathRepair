#include <bits/stdc++.h>
using namespace std;
namespace FGF {
int n;
const int N = (1 << 21) + 5;
char s[N];
long long a[N], b[N];
void FWTor(long long *y, int op) {
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += (i << 1))
      for (int k = 0; k < i; k++) y[i | j | k] += y[j | k] * op;
}
void work() {
  scanf("%d%s", &n, s);
  n = 1 << n;
  for (int i = 0; i < n; i++)
    a[i] = 1ll * (s[i] - '0') << (__builtin_popcount(i) << 1);
  scanf("%s", s);
  for (int i = 0; i < n; i++)
    b[i] = 1ll * (s[i] - '0') << (__builtin_popcount(i) << 1);
  FWTor(a, 1), FWTor(b, 1);
  for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
  FWTor(a, -1);
  for (int i = 0; i < n; i++)
    printf("%lld", a[i] >> (__builtin_popcount(i) << 1) & 3);
}
}  // namespace FGF
int main() {
  FGF::work();
  return 0;
}
