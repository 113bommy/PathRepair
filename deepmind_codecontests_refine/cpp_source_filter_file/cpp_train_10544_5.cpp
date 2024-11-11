#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 998244535;
int a[N], b[N];
bool st[N];
int pos[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      pos[a[i]] = i;
    }
    for (int j = 0; j < m; j++) {
      scanf("%d", &b[j]);
      st[b[j]] = true;
    }
    long long ans = 1;
    for (int i = 0; i < m; i++) {
      st[b[i]] = false;
      long long t = 0;
      if (pos[b[i]] - 1 >= 0 && !st[a[pos[b[i]] - 1]]) t++;
      if (pos[b[i]] + 1 < n && !st[a[pos[b[i]] + 1]]) t++;
      ans = ans * t % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
