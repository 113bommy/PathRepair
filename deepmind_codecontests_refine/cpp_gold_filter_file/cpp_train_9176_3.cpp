#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
int T, n, a[maxn], lst[maxn], d[maxn], c[maxn], ans[maxn];
vector<int> G[maxn];
queue<int> q;
void add(int p) {
  for (; p <= n + 1; p += p & -p) c[p]++;
}
int query(int p) {
  int s = 0;
  for (; p; p -= p & -p) s += c[p];
  return s;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n + 1; i++) {
      lst[i] = i, d[i] = c[i] = 0, G[i].clear();
    }
    int cur = 0, flag = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i] == -1) a[i] = i + 1;
      if (query(a[i] - 1) - query(i)) flag = 1;
      add(a[i]), G[i].push_back(lst[a[i]]);
      d[lst[a[i]]]++, lst[a[i]] = i;
    }
    if (flag) {
      printf("-1\n");
      continue;
    }
    for (int i = 1; i <= n + 1; i++) {
      if (!d[i]) q.push(i);
    }
    int tot = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      if (v <= n) ans[v] = ++tot;
      for (int u : G[v])
        if (!--d[u]) q.push(u);
    }
    for (int i = 1; i <= n; i++) {
      printf("%d%c", ans[i], " \n"[i == n]);
    }
  }
  return 0;
}
