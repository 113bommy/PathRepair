#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long a[N], b[N], c[N];
int main() {
  scanf("%d", &n);
  long long s = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d%I64d", &a[i], &b[i]);
    s ^= a[i];
    c[i] = a[i] ^ b[i];
  }
  for (int i = 1, k = 64; k && i <= n; --k) {
    if (!((c[i] >> (k - 1)) & 1)) {
      for (int j = i + 1; j <= n; ++j)
        if ((c[j] >> (k - 1)) & 1) {
          swap(c[i], c[j]);
          break;
        }
    }
    if (!((c[i] >> (k - 1)) & 1)) continue;
    for (int j = i + 1; j <= n; ++j)
      if ((c[j] >> (k - 1)) & 1) c[j] ^= c[i];
    ++i;
  }
  for (int i = 1; i <= n; ++i)
    if (s > (s ^ c[i])) s ^= c[i];
  if (s)
    puts("1/1");
  else {
    int m = 0;
    for (int i = 1; i <= n; ++i)
      if (c[i]) ++m;
    printf("%I64d/%I64d\n", (1ll << m) - 1, 1ll << m);
  }
  return 0;
}
