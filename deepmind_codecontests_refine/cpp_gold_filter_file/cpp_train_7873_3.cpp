#include <bits/stdc++.h>
using namespace std;
struct Tree {
  set<pair<int, int> > all, e, leaf;
  set<int> ver, adj[100005];
  int n, deg[100005];
  void add(int x, int y) {
    e.insert(pair<int, int>(x, y));
    e.insert(pair<int, int>(y, x));
    adj[x].insert(y);
    adj[y].insert(x);
    deg[x]++;
    deg[y]++;
  }
  void init() {
    for (int i = 1; i <= n; i++) {
      ver.insert(i);
      all.insert(pair<int, int>(deg[i], i));
      if (deg[i] == 1) leaf.insert(pair<int, int>(*adj[i].begin(), i));
    }
  }
  int star() { return ver.size() - all.rbegin()->first - 1; }
  void erase(int x) {
    int y = *adj[x].begin();
    ver.erase(x);
    leaf.erase(pair<int, int>(y, x));
    all.erase(pair<int, int>(1, x));
    adj[x].erase(y);
    adj[y].erase(x);
    all.erase(pair<int, int>(deg[y], y));
    all.insert(pair<int, int>(--deg[y], y));
    if (deg[y] == 1) leaf.insert(pair<int, int>(*adj[y].begin(), y));
  }
  pair<int, int> leaves() {
    set<pair<int, int> > s;
    s.insert(*leaf.begin());
    s.insert(*++leaf.begin());
    s.insert(*leaf.rbegin());
    s.insert(*++leaf.rbegin());
    int big = -1;
    set<pair<int, int> >::iterator it;
    for (it = s.begin(); it != s.end(); it++)
      if (deg[it->first] > 2) {
        big = it->first;
        break;
      }
    if (big != -1) {
      int x = -1, y = -1;
      for (it = s.begin(); it != s.end(); it++)
        if (it->first == big)
          x = it->second;
        else
          y = it->second;
      return pair<int, int>(x, y);
    }
    return pair<int, int>(leaf.begin()->second, leaf.rbegin()->second);
  }
} T1, T2;
int ans[100005], n;
void solvestar(Tree &T1, Tree &T2) {
  int u = (++T1.all.rbegin())->second;
  int v = *T1.adj[u].begin();
  int w = *T1.adj[u].rbegin();
  if (T1.deg[w] == 1) swap(v, w);
  int W = T2.leaf.begin()->second;
  int V = T2.leaf.begin()->first;
  set<int>::iterator it;
  int U = -1;
  for (it = T2.ver.begin(); it != T2.ver.end(); it++)
    if (T2.e.find(pair<int, int>(*it, V)) == T2.e.end())
      if (T2.e.find(pair<int, int>(*it, W)) == T2.e.end()) {
        U = *it;
        break;
      }
  ans[u] = U;
  ans[v] = V;
  ans[w] = W;
  static vector<int> g, h;
  g.resize(0);
  h.resize(0);
  for (it = T1.ver.begin(); it != T1.ver.end(); it++)
    if (*it != u && *it != v && *it != w) g.push_back(*it);
  for (it = T2.ver.begin(); it != T2.ver.end(); it++)
    if (*it != U && *it != V && *it != W) h.push_back(*it);
  for (int i = 0; i < g.size(); i++) ans[g[i]] = h[i];
}
void solveBf() {
  vector<int> g, h;
  int n = T1.ver.size();
  set<int>::iterator it;
  for (it = T1.ver.begin(); it != T1.ver.end(); it++) g.push_back(*it);
  for (it = T2.ver.begin(); it != T2.ver.end(); it++) h.push_back(*it);
  do {
    bool fl = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < i; j++)
        if (T1.e.find(pair<int, int>(g[i], g[j])) != T1.e.end())
          if (T2.e.find(pair<int, int>(h[i], h[j])) != T2.e.end()) {
            fl = 0;
            i = j = n;
          }
    if (fl) {
      for (int i = 0; i < n; i++) ans[g[i]] = h[i];
      return;
    }
  } while (next_permutation(g.begin(), g.end()));
}
void solve() {
  if (T1.ver.size() <= 5)
    solveBf();
  else if (T1.star() == 1)
    solvestar(T1, T2);
  else if (T2.star() == 1) {
    solvestar(T2, T1);
    static int tmp[100005];
    for (int i = 1; i <= n; i++) tmp[ans[i]] = i;
    for (int i = 1; i <= n; i++) ans[i] = tmp[i];
  } else {
    pair<int, int> a = T1.leaves(), c = T2.leaves();
    pair<int, int> b =
        pair<int, int>(*T1.adj[a.first].begin(), *T1.adj[a.second].begin());
    pair<int, int> d =
        pair<int, int>(*T2.adj[c.first].begin(), *T2.adj[c.second].begin());
    T1.erase(a.first);
    T1.erase(a.second);
    T2.erase(c.first);
    T2.erase(c.second);
    solve();
    if (ans[b.first] != d.first && ans[b.second] != d.second)
      ans[a.first] = c.first, ans[a.second] = c.second;
    else
      ans[a.first] = c.second, ans[a.second] = c.first;
  }
}
int main() {
  scanf("%d", &n);
  T1.n = T2.n = n;
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    T1.add(x, y);
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    T2.add(x - n, y - n);
  }
  T1.init();
  T2.init();
  if (!T1.star() || !T2.star()) return puts("No"), 0;
  solve();
  puts("Yes");
  for (int i = 1; i <= n; i++) printf("%d ", ans[i] + n);
}
