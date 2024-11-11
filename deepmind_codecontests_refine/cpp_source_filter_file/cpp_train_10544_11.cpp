#include <bits/stdc++.h>
using namespace std;
const int M = 4e5 + 5, mod = 998244535;
int a[M], b[M], pos[M], vis[M];
long long ans;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      pos[a[i]] = i;
    }
    for (int i = 1; i <= k; i++) {
      scanf("%d", &b[i]);
      vis[pos[b[i]]] = 1;
    }
    ans = 1;
    for (int i = 1; i <= k; i++) {
      int d = pos[b[i]];
      int t = 0;
      if (d > 1 && vis[d - 1] == 0) t++;
      if (d < n && vis[d + 1] == 0) t++;
      ans = ans * t % mod;
      vis[d] = 0;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
