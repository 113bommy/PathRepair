#include <bits/stdc++.h>
using namespace std;
const int N = 85;
int n, k, ins[N], a[N], cnt, s[N], ans, nxt[N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    if (ins[a[i]]) continue;
    if (cnt < k)
      ins[a[i]] = 1, s[++cnt] = a[i], ans++;
    else {
      ans++;
      for (int j = 1; j <= k; j++) nxt[s[j]] = n + 1;
      for (int j = 1; j <= k; j++) {
        for (int l = n; l >= i + 1; l--)
          if (a[l] == s[j]) nxt[s[j]] = l;
      }
      int Mx = 0, Mxi;
      for (int j = 1; j <= k; j++)
        if (nxt[s[j]] > Mx) Mx = nxt[s[j]], Mxi = j;
      ins[s[Mxi]] = 0, ins[a[i]] = 1, s[Mxi] = a[i];
    }
  }
  printf("%d\n", ans);
  return 0;
}
