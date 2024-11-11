#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int inf = 0x3f3f3f3f;
int dfn[maxn], low[maxn], n, m, belong[maxn], f[maxn], cnt, inst[maxn], scc;
vector<int> e[maxn], ans1, ans2;
stack<int> t;
int find(int x) {
  if (f[x] == x) return x;
  return f[x] = find(f[x]);
}
void tarjan(int x) {
  dfn[x] = low[x] = ++cnt;
  t.push(x);
  inst[x] = 1;
  for (int i = 0; i < e[x].size(); i++) {
    int y = e[x][i];
    if (!dfn[y]) {
      tarjan(y);
      low[x] = min(low[x], low[y]);
    } else if (inst[y])
      low[x] = min(low[x], dfn[y]);
  }
  if (low[x] == dfn[x]) {
    int v;
    scc++;
    do {
      v = t.top();
      t.pop();
      inst[v] = 0;
      belong[v] = scc;
    } while (v != x);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    cnt = 0;
    scc = 0;
    while (!t.empty()) t.pop();
    ans1.clear();
    ans2.clear();
    for (int i = 0; i <= n; i++) e[i].clear(), dfn[i] = low[i] = 0, inst[i] = 0;
    for (int i = 1; i <= m; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      e[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
      if (!dfn[i]) tarjan(i);
    if (scc == 1)
      puts("No");
    else {
      for (int i = 1; i <= n; i++)
        if (belong[i] == scc)
          ans1.push_back(i);
        else
          ans2.push_back(i);
      puts("Yes");
      printf("%d %d\n", ans1.size(), ans2.size());
      for (int i = 0; i < ans1.size(); i++) printf("%d ", ans1[i]);
      printf("\n");
      for (int i = 0; i < ans2.size(); i++) printf("%d ", ans2[i]);
      printf("\n");
    }
  }
}
