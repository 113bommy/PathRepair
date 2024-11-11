#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10;
struct node {
  int l, r, sum, mus;
} tr[M];
int n, a[M], now[M], sz[M], place[M], q, p;
vector<int> g[M];
void maket(int l, int r, int t) {
  tr[t].l = l;
  tr[t].r = r;
  if (l == r) {
    tr[t].sum += a[now[l]];
    return;
  }
  maket(l, (l + r) / 2, 2 * t);
  maket((l + r) / 2 + 1, r, 2 * t + 1);
  tr[t].sum = tr[2 * t].sum + tr[2 * t + 1].sum;
}
void change(int l, int r, int t) {
  if (tr[t].l == l && tr[t].r == r) {
    tr[t].sum = r - l + 1 - tr[t].sum;
    tr[t].mus ^= 1;
    return;
  }
  if (tr[t].mus) {
    change(tr[2 * t].l, tr[2 * t].r, 2 * t);
    change(tr[2 * t + 1].l, tr[2 * t + 1].r, 2 * t + 1);
    tr[t].mus = 0;
  }
  if (r <= tr[2 * t].r)
    change(l, r, 2 * t);
  else if (l >= tr[2 * t + 1].l)
    change(l, r, 2 * t + 1);
  else {
    change(l, tr[2 * t].r, 2 * t);
    change(tr[2 * t + 1].l, r, 2 * t + 1);
  }
  tr[t].sum = tr[2 * t].sum + tr[2 * t + 1].sum;
}
int query(int l, int r, int t) {
  if (tr[t].l == l && tr[t].r == r) return tr[t].sum;
  if (tr[t].mus) {
    change(tr[2 * t].l, tr[2 * t].r, 2 * t);
    change(tr[2 * t + 1].l, tr[2 * t + 1].r, 2 * t + 1);
    tr[t].mus = 0;
  }
  if (r <= tr[2 * t].r)
    return query(l, r, 2 * t);
  else if (l >= tr[2 * t + 1].l)
    return query(l, r, 2 * t + 1);
  else
    return query(l, tr[2 * t].r, 2 * t) + query(tr[2 * t + 1].l, r, 2 * t + 1);
  tr[t].sum = tr[2 * t].sum + tr[2 * t + 1].sum;
}
void dfs(int v) {
  a[++p] = v;
  place[v] = p;
  sz[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    dfs(g[v][i]);
    sz[v] += sz[g[v][i]];
  }
}
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    g[x].push_back(i);
  }
  for (int i = 1; i <= n; i++) scanf("%d", now + i);
  dfs(1);
  maket(1, n, 1);
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    int v;
    scanf("%d", &v);
    if (s == "get")
      printf("%d\n", query(place[v], place[v] + sz[v] - 1, 1));
    else
      change(place[v], place[v] + sz[v] - 1, 1);
  }
  return 0;
}
