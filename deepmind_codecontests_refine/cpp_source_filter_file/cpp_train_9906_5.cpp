#include <bits/stdc++.h>
using namespace std;
int fa[200005], ffa[200005];
int sz[200005], ssz[200005];
int f(int x) { return (fa[x] == x ? x : fa[x] = f(fa[x])); }
int ff(int x) { return (ffa[x] == x ? x : ffa[x] = ff(ffa[x])); }
struct _edge {
  int x, y, c;
} edge[200005];
int main() {
  long long ans = 0;
  for (int i = 1; i <= 200005 - 2; ++i) {
    fa[i] = ffa[i] = i;
    sz[i] = ssz[i] = 1;
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].c);
  }
  for (int i = 1; i < n; ++i) {
    if (edge[i].c == 1) {
      sz[f(edge[i].y)] += sz[f(edge[i].x)];
      fa[f(edge[i].x)] = f(edge[i].y);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (f(i) == i) {
      ans += 1ll * sz[i] * (sz[i] - 1);
    }
  }
  for (int i = 1; i < n; ++i) {
    if (edge[i].c == 0) {
      ssz[ff(edge[i].y)] += ssz[ff(edge[i].x)];
      ffa[ff(edge[i].x)] = ff(edge[i].y);
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans += sz[f(i)] * (ssz[ff(i)] - 1);
  }
  cout << ans;
  return 0;
}
