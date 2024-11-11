#include <bits/stdc++.h>
using namespace std;
int sig(double x) { return abs(x) < 1e-9 ? 0 : (x > 0 ? 1 : -1); }
int n, k, dord[100003], vord[100003], O = 0, A[100003][17], level[100003];
vector<int> adj[100003];
void dfs(int cur = 0, int par = -1, int lvl = 0) {
  dord[cur] = O++;
  level[cur] = lvl;
  vord[O - 1] = cur;
  A[cur][0] = par;
  for (auto nxt : adj[cur])
    if (nxt != par) dfs(nxt, cur, lvl + 1);
}
set<int> set1;
int lca(int p, int q) {
  if (level[p] < level[q]) swap(p, q);
  for (int i = ceil(log2(n)); i >= 0; i--)
    if (level[p] - (1 << i) >= level[q]) p = A[p][i];
  if (p == q) return p;
  for (int i = ceil(log2(n)); i >= 0; i--)
    if (A[p][i] != -1 && A[p][i] != A[q][i]) {
      p = A[p][i];
      q = A[q][i];
    }
  return A[p][0];
}
int dist(int i, int j) { return level[i] + level[j] - 2 * level[lca(i, j)]; }
int count(int x) {
  if (set1.size() == 0) return 1;
  if (set1.size() == 1) return dist(x, vord[*set1.begin()]);
  set<int>::iterator nxt = set1.upper_bound(dord[x]);
  if (nxt == set1.end()) {
    int a, b;
    a = vord[*set1.begin()];
    b = vord[*(--nxt)];
    return (dist(a, x) + dist(b, x) - dist(b, a)) / 2;
  } else if (nxt == set1.begin()) {
    int a, b;
    a = vord[*set1.begin()];
    b = vord[*(--set1.end())];
    return (dist(a, x) + dist(b, x) - dist(b, a)) / 2;
  } else {
    int a, b;
    a = vord[*(nxt)];
    b = vord[*(--nxt)];
    return (dist(a, x) + dist(b, x) - dist(b, a)) / 2;
  }
}
int size;
void add(int x) {
  int c = count(x);
  size += c;
  set1.insert(dord[x]);
}
void remove(int x) {
  set1.erase(dord[x]);
  int c = count(x);
  size -= c;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }
  dfs();
  for (int j = 1; j <= ceil(log2(n)); j++)
    for (int i = 0; i < n; i++)
      if (A[i][j - 1] != -1)
        A[i][j] = A[A[i][j - 1]][j - 1];
      else
        A[i][j] = -1;
  int l = 0, r = 0, ans = 0;
  while (r < n) {
    if (size <= k) add(r++);
    if (size > k) remove(l++);
    ans = max(ans, r - l);
  }
  cout << ans;
  return 0;
};
