#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long node[4 * N], root[4 * N], inds[N], indf[N], h[N], CNT, n, q;
vector<int> adj[N];
void DFS(int v, int par) {
  inds[v] = CNT++;
  for (int i = 0; i < adj[v].size(); i++)
    if (adj[v][i] != par) {
      h[adj[v][i]] = h[v] + 1;
      DFS(adj[v][i], v);
    }
  indf[v] = CNT - 1;
}
void modify(int tag, int L, int R, int s, int e, int val) {
  if (s >= R || e <= L) return;
  if (s <= L && R <= e) {
    node[tag] += val;
    return;
  }
  modify(tag * 2, L, (L + R) / 2, s, e, val);
  modify(tag * 2 + 1, (L + R) / 2, R, s, e, val);
}
void modify_root(int tag, int L, int R, int s, int e, int val) {
  if (s >= R || e <= L) return;
  if (s <= L && R <= e) {
    root[tag] += val;
    return;
  }
  modify_root(tag * 2, L, (L + R) / 2, s, e, val);
  modify_root(tag * 2 + 1, (L + R) / 2, R, s, e, val);
}
int get_vert(int tag, int L, int R, int s, int e) {
  if (e <= L || s >= R) return 0;
  if (s <= L && R <= e) return node[tag];
  return get_vert(tag * 2, L, (L + R) / 2, s, e) +
         get_vert(tag * 2 + 1, (L + R) / 2, R, s, e) + node[tag];
}
int get_root(int tag, int L, int R, int s, int e) {
  if (e <= L || s >= R) return 0;
  if (s <= L && R <= e) return root[tag];
  return get_root(tag * 2, L, (L + R) / 2, s, e) +
         get_root(tag * 2 + 1, (L + R) / 2, R, s, e) + root[tag];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  DFS(1, 1);
  while (q--) {
    int t;
    cin >> t;
    if (t == 0) {
      int v, val, d;
      cin >> v >> val >> d;
      if (d >= h[v]) {
        int s = inds[v] - 2 * h[v] + d + 1, e = min(inds[v] + d, indf[v]);
        if (s <= e) modify(1, 0, n, s, e + 1, val);
        modify_root(1, 0, n, 0, d - h[v] + 1, val);
      } else
        modify(1, 0, n, inds[v] - d, min(inds[v] + d, indf[v]) + 1, val);
    }
    if (t == 1) {
      int v;
      cin >> v;
      cout << get_vert(1, 0, n, inds[v], inds[v] + 1) +
                  get_root(1, 0, n, h[v], h[v] + 1)
           << endl;
    }
  }
}
