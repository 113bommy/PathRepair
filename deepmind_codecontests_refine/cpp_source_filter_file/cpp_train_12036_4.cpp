#include <bits/stdc++.h>
using namespace std;
const int N = 50005, M = 256;
int n, q, sl, fh, ans, fa[N], dep[N], vis[N], lst[N], val[N], f[N][M], mx[N][M],
    t, h[M], idx;
vector<int> v[N];
int trie[1024][2];
void add(int uu, int vv) {
  v[uu].push_back(vv);
  v[vv].push_back(uu);
  h[uu] = vv;
  h[vv] = uu;
}
void ins(int x) {
  int rt = 0;
  for (int i = 7; i >= 0; --i) {
    if (!trie[rt][(x >> i) & 1]) {
      trie[rt][(x >> i) & 1] = ++idx;
      trie[idx][0] = trie[idx][1] = 0;
    }
    rt = trie[rt][(x >> i) & 1];
  }
}
int query(int pos, int tt) {
  int d, v = 0, rt = 0, ret = 0;
  for (int i = 7; i >= 0; --i) {
    d = ((pos >> i) & 1) ^ 1;
    if (trie[rt][d])
      rt = trie[rt][d], ret |= 1 << i;
    else
      rt = trie[rt][d ^= 1];
    v |= d << i;
  }
  return ret << 8 | mx[tt][v];
}
inline void smx(int &x, int y) {
  if (x < y) x = y;
}
void dfs(int pos) {
  if (dep[pos] >= M) {
    idx = 0;
    trie[0][0] = trie[0][1] = 0;
    int i;
    for (i = pos; dep[pos] - dep[i] < M; i = fa[i]) {
      smx(mx[pos][val[i] >> 8], ((dep[pos] - dep[i]) ^ val[i]) & 255);
      if (vis[val[i] >> 8] != pos) ins(val[i] >> 8), vis[val[i] >> 8] = pos;
    }
    lst[pos] = i;
    for (int i = 0; i < M; i++) f[pos][i] = query(i, pos);
  }
  for (auto &i : v[pos]) {
    if (i == fa[pos]) continue;
    dep[i] = dep[pos] + 1;
    fa[i] = pos;
    dfs(i);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> q;
  int t1, t2, dis;
  for (int i = 1; i <= n; i++) cin >> val[i];
  for (int i = 1; i < n; i++) cin >> t1 >> t2, add(t1, t2);
  dep[1] = 1;
  dfs(1);
  while (q--) {
    dis = ans = 0;
    for (cin >> t1 >> t2; dep[t2] - dep[t1] >= M; t2 = lst[t2], ++dis)
      ans = max(ans, f[t2][dis]);
    for (dis <<= 8; t2 != fa[t1]; t2 = fa[t2], ++dis)
      ans = max(ans, val[t2] ^ dis);
    cout << ans << endl;
  }
  return 0;
}
