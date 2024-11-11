#include <bits/stdc++.h>
using namespace std;
const int N = 255;
const int mo = 998244353;
int p[N], q[N], fl[N];
int vis[N], d[N], nxt[N];
int n, no, na, nb, nab, f[N];
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &p[i]);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &q[i]);
  int ans = 1, cnt = 0;
  for (int i = (int)(1); i <= (int)(n); i++)
    if (p[i] && q[i])
      d[q[i]]++, nxt[p[i]] = q[i];
    else if (!p[i] && !q[i])
      ans = 1ll * ans * (++cnt) % mo;
    else if (!q[i])
      fl[p[i]] |= 1;
    else
      fl[q[i]] |= 2;
  cnt = 0;
  for (int i = (int)(1); i <= (int)(n); i++)
    if (!d[i] && !vis[i]) {
      int j = i;
      vis[i] = 1;
      for (; nxt[j] && !vis[nxt[j]];) j = nxt[j], vis[j] = 1;
      if (fl[i] & 2)
        fl[j] & 1 ? ++nab : ++nb;
      else
        fl[j] & 1 ? ++na : ++no;
    }
  for (int i = (int)(1); i <= (int)(n); i++)
    if (!vis[i]) {
      cnt++;
      for (int j = i; !vis[j]; j = nxt[j]) vis[j] = 1;
    }
  for (int i = (int)(1); i <= (int)(nab); i++)
    ans = 1ll * ans * max(no + 1 - i, 0) % mo;
  f[cnt] = ans;
  for (int i = (int)(1); i <= (int)(no + na); i++) {
    for (int j = (int)(n); j >= (int)(1); j--)
      f[j] = (1ll * f[j] * (i - 1) + f[j - 1]) % mo;
    f[0] = 0;
  }
  for (int i = (int)(1); i <= (int)(nb); i++) {
    for (int j = (int)(n); j >= (int)(1); j--)
      f[j] = (1ll * f[j] * (i - 1 + no) + f[j - 1]) % mo;
    f[0] = 0;
  }
  for (int i = (int)(0); i <= (int)(n - 1); i++) printf("%d ", f[n - i]);
}
