#include <bits/stdc++.h>
const int N = 100005;
int c[N], a[N], ans[N], T, n, x, y, id[N], b[N];
std::vector<int> e[N];
bool cmp(int x, int y) { return c[x] > c[y]; }
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &x, &y);
    int rest = n - x;
    y -= x;
    for (int i = 1; i <= n + 1; i++) c[i] = 0, e[i].clear(), ans[i] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      c[a[i]]++, e[a[i]].push_back(i);
    }
    for (int i = 1; i <= n + 1; i++) id[i] = i;
    std::sort(id + 1, id + n + 2, cmp);
    int p = 1, tot = 1;
    while (c[id[tot]] == c[id[tot + 1]]) tot++;
    while (x) {
      for (int i = tot; i && x; i--) {
        int col = id[i];
        c[col]--;
        ans[e[col][c[col]]] = col;
        x--;
      }
      if (!x) break;
      while (c[id[tot]] == c[id[tot + 1]]) tot++;
    }
    rest -= c[id[1]];
    if (std::min(c[id[1]], rest) + rest < y) {
      puts("NO");
      continue;
    }
    puts("YES");
    int Y = std::min(c[id[1]], rest) + rest;
    for (int i = 1; i <= n + 1; i++) c[i] = std::min(c[i], Y / 2);
    p = 1;
    for (int i = 0; i < Y; i += 2) {
      if (!c[id[p]]) p++;
      int t = id[p];
      c[t]--;
      b[i] = e[t][c[t]];
    }
    for (int i = 1; i < Y; i += 2) {
      if (!c[id[p]]) p++;
      int t = id[p];
      c[t]--;
      b[i] = e[t][c[t]];
    }
    for (int i = 0; i < y; i++) ans[b[i]] = a[b[(i + 1) % Y]];
    for (int i = 1; i <= n; i++) printf("%d ", ans[i] ? ans[i] : id[n + 1]);
    puts("");
  }
}
