#include <bits/stdc++.h>
const int N = 300001;
int n, m;
int len[N], swit[N][3], fa[N];
bool stat[N];
int get_fa(int x) { return x == fa[x] ? x : fa[x] = get_fa(fa[x]); }
void link(int x, int y) {
  if (get_fa(x) != get_fa(y)) fa[fa[x]] = get_fa(y);
}
int main() {
  scanf("%d%d", &n, &m);
  int t;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t);
    stat[i] = t;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &len[i]);
    for (int j = 1; j <= len[i]; j++) {
      scanf("%d", &t);
      swit[t][++swit[t][0]] = i;
    }
  }
  for (int i = 1; i <= m << 1; i++) fa[i] = i;
  for (int i = 1; i <= n; i++) {
    int u = swit[i][1], v = swit[i][2];
    if (stat[i]) {
      link(u + m, v + m);
      link(v, u);
    } else {
      link(u + m, v);
      link(u, v + m);
    }
  }
  for (int i = 1; i <= m; i++) {
    int _ = i + m;
    if (get_fa(i) == get_fa(_)) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
