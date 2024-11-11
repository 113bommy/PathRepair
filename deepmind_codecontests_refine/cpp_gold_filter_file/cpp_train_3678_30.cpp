#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int sum[N];
int fa[N];
int getfa(int x) {
  if (fa[x] == x) return fa[x];
  return fa[x] = getfa(fa[x]);
}
int main() {
  int n, m, k;
  while (~scanf("%d%d%d", &n, &m, &k)) {
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      x = getfa(x);
      y = getfa(y);
      if (x == y) continue;
      fa[x] = y;
    }
    for (int i = 1; i <= n; i++) sum[getfa(i)]++;
    int kk = 0;
    long long res = 1;
    for (int i = 1; i <= n; i++) {
      if (fa[i] == i) {
        kk++;
        if (kk > 2) res = res * n % k;
        res = res * sum[i] % k;
      }
    }
    if (kk > 1)
      cout << res << endl;
    else
      cout << 1 % k << endl;
  }
  return 0;
}
