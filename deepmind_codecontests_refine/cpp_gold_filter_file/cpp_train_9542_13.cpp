#include <bits/stdc++.h>
using namespace std;
char a[100010];
int s[100010], fa[100010], b[100010];
map<string, int> p;
int res;
int find(int x) {
  if (x == fa[x]) {
    res = min(res, s[x]);
    return x;
  } else {
    res = min(res, s[fa[x]]);
    return fa[x] = find(fa[x]);
  }
}
void unite(int x, int y) {
  res = s[x];
  x = find(x);
  s[x] = res;
  res = s[y];
  y = find(y);
  s[y] = res;
  if (x != y) {
    fa[x] = y;
    s[x] = min(s[x], s[y]);
    s[y] = s[x];
  }
}
int main() {
  int n, m, k, i, j, x, t;
  long long ans;
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= n; i++) {
    scanf("%s", a);
    p[a] = i;
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
    fa[i] = i;
  }
  for (i = 1; i <= m; i++) {
    scanf("%d", &x);
    for (j = 1; j <= x; j++) {
      scanf("%d", &b[j]);
      if (j > 1) unite(b[j - 1], b[j]);
    }
  }
  ans = 0;
  for (i = 1; i <= k; i++) {
    scanf("%s", a);
    ans = ans + s[find(p[a])];
  }
  printf("%lld\n", ans);
  return 0;
}
