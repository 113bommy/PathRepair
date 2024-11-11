#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj(200001, vector<int>(0));
int k = 0, n;
int from[200001], to[200001], t[200001];
int segment[800010], f1[800010];
int pos[200010];
void dfs(int v) {
  from[v] = ++k;
  pos[k] = t[v];
  int l = adj[v].size();
  for (int j = 0; j < l; j++) {
    dfs(adj[v][j]);
  }
  to[v] = k;
}
void build(int x, int l, int r) {
  if (l < r) {
    int y = (l + r) / 2;
    build(2 * x, l, y);
    build(2 * x + 1, y + 1, r);
    segment[x] = segment[2 * x] + segment[2 * x + 1];
  } else {
    segment[x] = pos[l];
    return;
  }
}
void push(int x, int l, int r) {
  if (f1[x]) return;
  int y = (l + r) / 2;
  f1[x] ^= 1;
  f1[2 * x] ^= 1;
  f1[2 * x + 1] ^= 1;
  segment[2 * x] = y - l + 1 - segment[2 * x];
  segment[2 * x + 1] = r - y - segment[2 * x + 1];
}
int query(int x, int l, int r, int ll, int rr) {
  ;
  if (ll > rr) {
    return 0;
  }
  if (ll == l && r == rr) {
    return segment[x];
  }
  push(x, l, r);
  int y = (l + r) / 2;
  int res = query(2 * x, l, y, ll, min(y, rr));
  res = res + query(2 * x + 1, y + 1, r, max(y + 1, ll), rr);
  return res;
}
void update(int x, int l, int r, int ll, int rr) {
  if (rr < ll) return;
  if (ll == l && r == rr) {
    segment[x] = r - l + 1 - segment[x];
    f1[x] ^= 1;
    return;
  }
  push(x, l, r);
  int y = (l + r) / 2;
  update(2 * x, l, y, ll, min(y, rr));
  update(2 * x + 1, y + 1, r, max(y + 1, ll), rr);
  segment[x] = segment[2 * x] + segment[2 * x + 1];
}
int main() {
  scanf("%d", &n);
  int x, q;
  string st;
  for (int i = 2; i < n + 1; i++) {
    scanf("%d", &x);
    adj[x].push_back(i);
  }
  for (int i = 0; i < 80002; i++) {
    f1[i] = 1;
  }
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &x);
    t[i] = x;
  }
  dfs(1);
  build(1, 1, n);
  for (int i = 1; i < 4 * n + 1; i++) {
    ;
  }
  scanf("%d", &q);
  while (q--) {
    cin >> st;
    if (st == "get") {
      cin >> x;
      printf("%d\n", query(1, 1, n, from[x], to[x]));
    } else {
      cin >> x;
      update(1, 1, n, from[x], to[x]);
    }
  }
}
