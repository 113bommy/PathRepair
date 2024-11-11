#include <bits/stdc++.h>
using namespace std;
int n;
char str[100500];
struct Node {
  int t[26], f, len, siz;
} a[100500 << 1];
int las, tn;
vector<int> g[100500 << 1];
void add(int c) {
  int p = las, np = ++tn;
  las = np;
  a[np].len = a[p].len + 1;
  for (; p && !a[p].t[c]; p = a[p].f) a[p].t[c] = np;
  if (!p)
    a[np].f = 1;
  else {
    int v = a[p].t[c];
    if (a[v].len == a[p].len + 1)
      a[np].f = v;
    else {
      int nv = ++tn;
      a[nv] = a[v];
      a[nv].len = a[p].len + 1;
      for (; p && a[p].t[c] == v; p = a[p].f) a[p].t[c] = nv;
      a[np].f = a[v].f = nv;
    }
  }
}
long long ans;
void dfs(int num) {
  for (int i = 0, v; i < g[num].size(); i++) {
    dfs(g[num][i]);
    a[num].siz += a[g[num][i]].siz;
  }
  ans += a[num].siz * a[num].siz * (a[num].len - a[a[num].f].len);
}
void solve() {
  scanf("%s", str);
  n = strlen(str);
  las = tn = 1;
  for (int i = 0; i < n; i++) add(str[i] - 'a');
  for (int i = 0, p = 1; i < n; i++) {
    p = a[p].t[str[i] - 'a'];
    a[p].siz = 1;
  }
  for (int i = 2; i <= tn; i++) g[a[i].f].push_back(i);
  dfs(1);
  printf("%lld\n", ans);
  memset(a, 0, sizeof(Node) * (tn + 5));
  ans = 0;
  for (int i = 1; i <= tn; i++) g[i].clear();
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
