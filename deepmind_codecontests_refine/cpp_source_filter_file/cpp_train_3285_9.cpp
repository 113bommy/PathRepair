#include <bits/stdc++.h>
using namespace std;
const int mo = 998244353;
const int N = 2005;
int n, p[N], q[N];
int d[N], fl[N], nx[N];
int f[N], ans, cnt, vis[N];
int no, na, nb, nab;
int main() {
  ans = 1;
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &p[i]);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &q[i]);
  for (int i = (int)(1); i <= (int)(n); i++) {
    if (p[i] && q[i]) ++d[q[i]], nx[p[i]] = q[i];
    if (!p[i] && !q[i]) ans = 1ll * ans * (++cnt) % mo;
    if (p[i] && !q[i]) fl[p[i]] = 1;
    if (!p[i] && q[i]) fl[q[i]] = 2;
  }
  cnt = 0;
  for (int i = (int)(1); i <= (int)(n); i++)
    if (!d[i] && !vis[i]) {
      int j = i;
      vis[i] = 1;
      for (; nx[j]; vis[j = nx[j]] = 1)
        ;
      if (fl[i] & 2)
        fl[j] & 1 ? ++nab : ++nb;
      else
        fl[j] & 1 ? ++na : ++no;
    }
  for (int i = (int)(1); i <= (int)(n); i++)
    if (!vis[i]) {
      ++cnt;
      for (int j = i; !vis[j]; j = nx[j]) vis[j] = 1;
    }
  for (int i = (int)(1); i <= (int)(nab); i++)
    ans = 1ll * ans * (no + 1 - i) % mo;
  f[cnt] = ans;
  for (int i = (int)(1); i <= (int)(no + na); i++) {
    for (int j = (int)(n); j >= (int)(1); j--)
      f[j] = (1ll * f[j] * (i - 1) + f[j - 1]) % mo;
    f[0] = 0;
  }
  for (int i = (int)(1); i <= (int)(nb); i++) {
    for (int j = (int)(n); j >= (int)(1); j--)
      f[j] = (1ll * f[j] * (i + no - 1) + f[j - 1]) % mo;
    f[0] = 0;
  }
  for (int i = (int)(0); i <= (int)(n - 1); i++) printf("%d ", f[n - i]);
}
