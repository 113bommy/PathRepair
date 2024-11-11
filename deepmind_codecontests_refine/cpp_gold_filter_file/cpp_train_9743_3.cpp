#include <bits/stdc++.h>
using namespace std;
long long du[1000101];
int fa[1000101];
int h[1000101];
int ff(int x) {
  if (fa[x] == x) return x;
  fa[x] = ff(fa[x]);
  return fa[x];
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) fa[i] = i;
  long long t = 0;
  long long o = 0;
  int e;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x == y)
      h[x]++, o++;
    else
      du[x]++, du[y]++, t++;
    e = x;
    if (ff(x) != ff(y)) {
      fa[ff(x)] = ff(y);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (ff(i) != ff(e) && (ff(i) != i || h[i] == 1)) {
      cout << 0 << endl;
      return 0;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += du[i] * (du[i] - 1) / 2;
  }
  ans += o * t;
  ans += o * (o - 1) / 2;
  cout << ans << endl;
  return 0;
}
