#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
unsigned long long q, k, a[N], b[N], c[N], st[N], ed[N], num[N], f[22];
int main() {
  f[0] = 1;
  for (int i = 1; i <= 18; i++) f[i] = f[i - 1] * 10;
  num[1] = 9;
  for (unsigned long long i = 1; i <= 20; i++) {
    st[i] = ed[i - 1] + i;
    ed[i] = st[i] + (num[i] - 1) * i;
    a[i] = a[i - 1] + (st[i] + ed[i]) * num[i] / 2;
    if (a[i] >= (unsigned long long)1e18) break;
    num[i + 1] = num[i] * 10;
  }
  scanf("%lld", &q);
  while (q--) {
    scanf("%lld", &k);
    unsigned long long pos = 0;
    for (int i = 1; i <= 10; i++) {
      if (a[i] >= k) {
        pos = i;
        break;
      }
    }
    k -= a[pos - 1];
    unsigned long long l = 1, r = num[pos], m, id;
    while (l <= r) {
      m = (l + r) / 2;
      unsigned long long tp = (st[pos] + st[pos] + (m - 1) * pos) * m / 2;
      if (tp >= k)
        id = m, r = m - 1;
      else
        l = m + 1;
    }
    k -= (st[pos] + st[pos] + (id - 2) * pos) * (id - 1) / 2;
    unsigned long long res = 0, idx = 0;
    for (int i = 1; i <= 20; i++) {
      if (k <= num[i] * i) {
        idx = i;
        break;
      }
      k -= num[i] * i;
      res += num[i];
    }
    unsigned long long val = res + k / idx;
    unsigned long long kk;
    if (k % idx == 0)
      kk = idx;
    else
      kk = k % idx, val++;
    printf("%lld\n", (val / f[idx - kk]) % 10);
  }
  return 0;
}
