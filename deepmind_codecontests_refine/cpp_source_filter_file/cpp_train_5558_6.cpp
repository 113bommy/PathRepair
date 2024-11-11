#include <bits/stdc++.h>
using namespace std;
const int Maxn = int(1e5) + 1000;
vector<pair<int, int> > ver[Maxn];
vector<pair<int, int> > store;
int n, sz[Maxn], W0, L0, fen[Maxn];
bool mark[Maxn];
long long ans = 0;
inline void add_fen(int x, int val) {
  if (x <= 0) return;
  for (; x < Maxn; x += x & -x) fen[x] += val;
}
inline long long get_fen(int x) {
  long long sum = 0;
  for (x = max(x, 0); x > 0; x -= x & -x) sum += fen[x];
  return sum;
}
void dfs_size(int v, int par) {
  sz[v] = 1;
  for (pair<int, int> nex : ver[v]) {
    if (!mark[nex.first] && nex.first != par)
      dfs_size(nex.first, v), sz[v] += sz[nex.first];
  }
}
void dfs_gen(int v, int par, int curL, int curW, int L, int W) {
  if (curW > W || curL > L) return;
  store.push_back(make_pair(curW, curL));
  for (pair<int, int> nex : ver[v])
    if (!mark[nex.first] && nex.first != par)
      dfs_gen(nex.first, v, curL + 1, curW + nex.second, L, W);
}
inline int find_center(int v) {
  dfs_size(v, -1);
  int par = -1, cap = sz[v] / 2;
  while (1) {
    bool found = false;
    for (pair<int, int> nex : ver[v])
      if (!mark[nex.first] && nex.first != par && sz[nex.first] > cap) {
        par = v, v = nex.first, found = true;
        break;
      }
    if (!found) return v;
  }
}
inline long long cnt(int u, int par, int L, int W) {
  long long ret = 0;
  store.clear();
  dfs_gen(u, par, 0, 0, L, W);
  sort(store.begin(), store.end());
  int po1 = 0;
  for (int po2 = store.size() - 1; po2 >= 0; --po2) {
    while (po1 < store.size() && store[po1].first + store[po2].first <= W)
      add_fen(store[po1].second + 1, 1), ++po1;
    ret += get_fen(L - store[po2].second + 1);
  }
  while (--po1 >= 0) add_fen(store[po1].second + 1, -1);
  return ret;
}
inline void solve(int v) {
  v = find_center(v);
  ans += cnt(v, -1, L0, W0) - 1;
  mark[v] = true;
  for (pair<int, int> nex : ver[v])
    if (!mark[nex.first]) ans -= cnt(nex.first, v, L0 - 2, W0 - 2 * nex.second);
  for (pair<int, int> nex : ver[v])
    if (!mark[nex.first]) solve(nex.first);
}
int main() {
  scanf("%d%d%d", &n, &L0, &W0);
  for (int i = 0; i < n - 1; ++i) {
    int a, b, w;
    scanf("%d%d", &a, &w);
    --a;
    ver[a].push_back(make_pair(i + 1, w));
    ver[i + 1].push_back(make_pair(a, w));
  }
  solve(0);
  printf("%d\n", ans / 2);
}
