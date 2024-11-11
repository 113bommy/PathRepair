#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, inf = 1e9;
int n, kk, s, x, k[N][2];
char ch[N];
int fa[N << 1], val[N << 1];
int find(int u) { return fa[u] ? fa[u] = find(fa[u]) : u; }
void uni(int a, int b) {
  if (find(a) == find(b)) return;
  val[find(b)] += val[find(a)];
  fa[find(a)] = find(b);
}
int mix(int a) { return min(val[find(a)], val[find(a + kk)]); };
int main() {
  scanf("%d%d%s", &n, &kk, ch + 1);
  for (int i = 1; i <= kk; i++) {
    scanf("%d", &s);
    while (s--) {
      scanf("%d", &x);
      k[x][bool(k[x][0])] = i;
    }
  }
  for (int i = 1; i <= kk; i++) val[i] = 1;
  val[kk + kk + 1] = inf;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (k[i][0] == 0) goto qwq;
    if (ch[i] == '1') {
      if (k[i][1]) {
        if (find(k[i][0]) == find(k[i][1])) goto qwq;
        ans -= mix(k[i][0]) + mix(k[i][1]);
        uni(k[i][0], k[i][1]), uni(k[i][0] + kk, k[i][1] + kk);
        ans += mix(k[i][1]);
      } else {
        ans -= mix(k[i][0]);
        uni(k[i][0], kk + kk + 1);
        ans += val[find(k[i][0] + kk)];
      }
    } else {
      if (k[i][1]) {
        if (find(k[i][0]) == find(k[i][1] + kk)) goto qwq;
        ans -= mix(k[i][0]) + mix(k[i][1]);
        uni(k[i][0], k[i][1] + kk), uni(k[i][0] + kk, k[i][1]);
        ans += mix(k[i][0]);
      } else {
        ans -= mix(k[i][0]);
        uni(k[i][0] + kk, kk + kk + 1);
        ans += mix(k[i][0]);
      }
    }
  qwq:
    printf("%d\n", ans);
  }
  return 0;
}
