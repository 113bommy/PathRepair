#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100001;
const int oo = 1000000007;
int n, root[MaxN], depth[MaxN], ans = 0;
int findroot(int k, int v, int x, int ans) {
  ans %= oo;
  if (root[k] == k) {
    root[k] = v;
    depth[k] = ans + x;
    depth[k] %= oo;
    return k;
  }
  int j = root[k];
  int c = findroot(root[k], v, x, ans + depth[k]);
  root[k] = v;
  depth[k] += depth[j];
  depth[k] %= oo;
  return c;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    root[i] = i;
    depth[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int v, x;
      scanf("%d%d", &v, &x);
      v--;
      ans += depth[findroot(v, i, x, 0)];
      ans %= oo;
    }
  }
  if (ans < 0) ans += oo;
  printf("%d\n", ans);
  return 0;
}
