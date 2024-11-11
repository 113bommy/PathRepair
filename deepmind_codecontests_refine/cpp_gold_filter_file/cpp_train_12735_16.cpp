#include <bits/stdc++.h>
using namespace std;
int tree[300000];
int rn, tr0;
void make_tree(int n) {
  for (int i = 0;; ++i)
    if ((1 << i) >= n) {
      rn = (1 << i);
      tr0 = rn - 1;
      return;
    }
}
void prepare() {
  for (int i = tr0 - 1; i >= 0; --i)
    tree[i] += tree[i * 2 + 1] + tree[i * 2 + 2];
}
int getsumm(int l, int r, int i, int gl, int gr) {
  if (r <= gl || l >= gr) return 0;
  if (gl >= l && gr <= r) return tree[i];
  int gc = (gl + gr) / 2;
  return getsumm(l, r, i * 2 + 1, gl, gc) + getsumm(l, r, i * 2 + 2, gc, gr);
}
void add(int i, int x) {
  i += tr0;
  for (;; i = (i - 1) / 2) {
    tree[i] -= x;
    if (i == 0) return;
  }
}
void rec(int i, int li, const vector<vector<int> > &g, vector<int> &ns) {
  for (int j = 0; j < g[i].size(); ++j)
    if (g[i][j] != li) rec(g[i][j], i, g, ns);
  ns.push_back(i);
}
int main() {
  int n;
  cin >> n;
  vector<vector<int> > g(n);
  vector<pair<int, int> > e(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    e[i] = pair<int, int>(a, b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int maxi = 0;
  for (int i = 1; i < n; ++i)
    if (g[maxi].size() < g[i].size()) maxi = i;
  vector<int> ns;
  vector<int> rs(n - 1, -1);
  int vi = 0;
  for (int j = 0; j < (int)g[maxi].size(); ++j) {
    rec(g[maxi][j], maxi, g, ns);
    for (int i = ns.size() - 1; i >= 0 && rs[i] == -1; --i) rs[i] = ns.size();
  }
  vector<int> v(n);
  for (int i = 0; i < ns.size(); ++i) v[ns[i]] = i;
  v[maxi] = 1e9;
  make_tree(n - 1);
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int type;
    cin >> type;
    if (type == 1 || type == 2) {
      int id;
      cin >> id;
      int a, b;
      a = e[id - 1].first;
      b = e[id - 1].second;
      if (a == maxi || v[a] > v[b]) swap(a, b);
      add(v[a], (type == 1 ? -1 : 1));
    } else {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      int result = -2;
      if (a == b)
        result = 0;
      else if (a != maxi && b != maxi && v[a] < rs[v[b]] && v[b] < rs[v[a]]) {
        if (v[a] > v[b]) swap(a, b);
        if (getsumm(v[a], v[b], 0, 0, rn) == 0)
          result = v[b] - v[a];
        else
          result = -1;
      } else {
        if (a == maxi) swap(a, b);
        if (getsumm(v[a], rs[v[a]], 0, 0, rn) == 0)
          result = rs[v[a]] - v[a];
        else
          result = -1;
        if (result != -1 && b != maxi) {
          if (getsumm(v[b], rs[v[b]], 0, 0, rn) == 0)
            result += rs[v[b]] - v[b];
          else
            result = -1;
        }
      }
      cout << result << "\n";
    }
  }
  return 0;
}
