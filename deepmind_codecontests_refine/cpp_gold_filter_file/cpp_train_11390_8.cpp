#include <bits/stdc++.h>
using namespace std;
int n;
int st1[1000005];
int en1[1000005];
int vis[1000005];
vector<int> gra[1000005];
int a, b;
int par[1000005];
int cnt;
int seg[4000005];
int lazy[4000005];
void dfs(int node) {
  st1[node] = ++cnt;
  en1[node] = st1[node];
  vis[node] = 1;
  for (int i = 0; i < gra[node].size(); ++i) {
    int v = gra[node][i];
    if (vis[v]) continue;
    dfs(v);
    par[v] = node;
    en1[node] = max(en1[node], en1[v]);
  }
}
void lazyupd(int node, int st, int en) {
  if (lazy[node] == 0) {
    return;
  }
  if (st == en) {
    seg[node] = lazy[node];
    lazy[node] = 0;
    return;
  }
  seg[node] = lazy[node];
  lazy[2 * node] = lazy[node];
  lazy[2 * node + 1] = lazy[node];
  lazy[node] = 0;
}
void upd(int node, int st, int en, int qst, int qen, int val) {
  if (st > en) return;
  lazyupd(node, st, en);
  if (st > en || qst > qen || qst > en || qen < st) return;
  if (st >= qst && en <= qen) {
    lazy[node] = val;
    lazyupd(node, st, en);
    return;
  }
  int mid = (st + en) >> 1;
  upd(2 * node, st, mid, qst, qen, val);
  upd(2 * node + 1, mid + 1, en, qst, qen, val);
  seg[node] = min(seg[2 * node], seg[2 * node + 1]);
}
int q(int node, int st, int en, int qst, int qen) {
  if (st > en || qst > qen || qst > en || qen < st) return 1000000007;
  lazyupd(node, st, en);
  if (st >= qst && en <= qen) {
    return seg[node];
  }
  int mid = (st + en) >> 1;
  return min(q(2 * node, st, mid, qst, qen),
             q(2 * node + 1, mid + 1, en, qst, qen));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> a >> b;
    gra[a].push_back(b);
    gra[b].push_back(a);
  }
  dfs(1);
  for (int i = 1; i <= 4000004; ++i) seg[i] = 1;
  int qu;
  cin >> qu;
  int c, a;
  while (qu--) {
    cin >> c >> a;
    if (c == 1) {
      int v = q(1, 1, 500000, st1[a], en1[a]);
      if (v == 1) {
        if (par[a]) upd(1, 1, 500000, st1[par[a]], st1[par[a]], 1);
      }
      upd(1, 1, 500000, st1[a], en1[a], 2);
    }
    if (c == 2) {
      upd(1, 1, 500000, st1[a], st1[a], 1);
    }
    if (c == 3) {
      int v = q(1, 1, 500000, st1[a], en1[a]);
      cout << v - 1 << "\n";
    }
  }
  return 0;
}
