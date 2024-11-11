#include <bits/stdc++.h>
using namespace std;
int a[200005], p[200005], fa[200005];
vector<int> v[200005];
int findd(int x) {
  if (x == fa[x]) {
    return x;
  } else {
    return fa[x] = findd(fa[x]);
  }
}
int main() {
  int n, m, x, y;
  scanf("%d%d", &n, &m);
  int ans = n - 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    p[i] = x;
    v[x].push_back(i);
    if (p[i] == p[i - 1]) ans--;
  }
  for (int i = 1; i <= n; i++) fa[i] = i;
  printf("%d\n", ans);
  for (int i = 1; i <= m - 1; i++) {
    scanf("%d%d", &x, &y);
    x = findd(x);
    y = findd(y);
    if (v[x].size() > v[y].size()) swap(x, y);
    for (auto now : v[x]) {
      if (p[now + 1] == y) ans--;
      if (p[now - 1] == y) ans--;
    }
    for (auto now : v[x]) {
      p[now] = y;
      v[y].push_back(now);
    }
    fa[x] = y;
    printf("%d\n", ans);
  }
}
