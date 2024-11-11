#include <bits/stdc++.h>
using namespace std;
const int N = 1145;
const int md = 998244353;
long long as = 1, ct, f[N];
int n, b1, b2, a1, a2, p[N], q[N], a[N], b[N], v[N], fl[N];
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d", &p[i]);
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &q[i]);
    if (p[i] && q[i])
      a[p[i]] = q[i], b[q[i]] = 1;
    else if (!p[i] && !q[i])
      as = as * (++ct) % md;
    else if (!q[i])
      fl[p[i]] |= 1;
    else
      fl[q[i]] |= 2;
  }
  ct = 0;
  for (int i = (1); i <= (n); i++)
    if (!v[i] && !b[i]) {
      v[i] = 1;
      int j = i;
      while (!v[a[j]] && a[j]) j = a[j], v[j] = 1;
      if (fl[i] & 2)
        fl[j] & 1 ? b1++ : b2++;
      else
        fl[j] & 1 ? a1++ : a2++;
    }
  for (int i = (1); i <= (n); i++)
    if (!v[i]) {
      ct++;
      v[i] = 1;
      for (int j = i; !v[a[j]]; j = a[j], v[j] = 1)
        ;
    }
  for (int i = (1); i <= (b1); i++) as = as * max(a2 + 1 - i, 0) % md;
  f[ct] = as;
  for (int i = (1); i <= (a1 + a2); i++) {
    for (int j = (n); j >= (ct); j--) f[j] = (f[j] * (i - 1) + f[j - 1]) % md;
    f[0] = 0;
  }
  for (int i = (1); i <= (b2); i++)
    for (int j = (n); j >= (ct); j--)
      f[j] = (f[j] * (i - 1 + a2) + f[j - 1]) % md;
  for (int i = (0); i <= (n - 1); i++) printf("%d ", f[n - i]);
}
