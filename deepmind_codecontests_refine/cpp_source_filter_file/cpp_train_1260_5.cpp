#include <bits/stdc++.h>
const int N = 200005, LN = 60;
int n, head[N], tot, ans;
struct edge {
  int to, nxt, val;
} e[N << 1];
void link(int x, int y, int v) {
  e[++tot] = (edge){y, head[x], v}, head[x] = tot;
  e[++tot] = (edge){x, head[y], v}, head[y] = tot;
}
namespace sam {
int lc[N * LN], rc[N * LN], sum[N * LN], cnt;
int idx = 1, lst = 1;
int fail[N], nxt[N][26], max[N], pos[N];
int head[N], next[N], root[N];
int merge(int x, int y) {
  if (!x || !y) return x | y;
  int now = ++cnt;
  sum[now] = sum[x] + sum[y];
  lc[now] = merge(lc[x], lc[y]);
  rc[now] = merge(rc[x], rc[y]);
  return now;
}
void insert(int &root, int pos, int l = 1, int r = n) {
  if (!root) root = ++cnt;
  ++sum[root];
  if (l == r) return;
  int mid = l + r >> 1;
  if (pos <= mid)
    insert(lc[root], pos, l, mid);
  else
    insert(rc[root], pos, mid + 1, r);
}
int query(int root, int L, int R, int l = 1, int r = n) {
  if (L <= l && r <= R) return sum[root];
  int mid = l + r >> 1, ret = 0;
  if (L <= mid) ret += query(lc[root], L, R, l, mid);
  if (R > mid) ret += query(rc[root], L, R, mid + 1, r);
  return ret;
}
int count(int l, int r, int x, int len) {
  return r - l + 1 >= len ? query(root[x], l + len - 1, r) : 0;
}
void link(int x, int y) { next[y] = head[x], head[x] = y; }
void append(int ch, int id) {
  int p = lst, np = lst = ++idx;
  max[np] = max[p] + 1, pos[np] = id;
  for (; p && !nxt[p][ch]; p = fail[p]) nxt[p][ch] = np;
  if (!p)
    fail[np] = 1;
  else {
    int q = nxt[p][ch];
    if (max[p] + 1 == max[q])
      fail[np] = q;
    else {
      int nq = ++idx;
      max[nq] = max[p] + 1;
      fail[nq] = fail[q], fail[q] = fail[np] = nq;
      std::memcpy(nxt[nq], nxt[q], 26 << 2);
      for (; nxt[p][ch] == q; p = fail[p]) nxt[p][ch] = nq;
    }
  }
}
int dfs(int x) {
  if (pos[x]) insert(root[x], pos[x]);
  for (int i = head[x]; i; i = next[i]) root[x] = merge(root[x], dfs(i));
  return root[x];
}
void init() {
  for (int i = 2; i <= idx; ++i) link(fail[i], i);
  dfs(1);
}
}  // namespace sam
int f[N], size[N], son[N], top[N], dep[N], dfn[N], clk;
int len;
std::string s, t, nowS;
int dfs0(int x) {
  dep[x] = dep[f[x]] + 1;
  for (int i = head[x]; i; i = e[i].nxt)
    if (e[i].to != f[x]) {
      f[e[i].to] = x, size[x] += dfs0(e[i].to);
      if (size[e[i].to] > size[son[x]]) son[x] = e[i].to;
    }
  return ++size[x];
}
void dfs1(int x, int v = 0) {
  sam::append(v, dfn[x] = ++clk), t[clk] = v;
  for (int i = head[x]; i; i = e[i].nxt)
    if (e[i].to == son[x]) top[son[x]] = top[x], dfs1(son[x], e[i].val);
  for (int i = head[x]; i; i = e[i].nxt)
    if (e[i].to != son[x] && e[i].to != f[x])
      top[e[i].to] = e[i].to, dfs1(e[i].to, e[i].val);
}
int next[N];
void build_KMP() {
  for (int i = 1, j = next[0] = -1; i <= len; next[i++] = ++j)
    while (j >= 0 && s[j] != s[i - 1]) j = next[j];
}
int transfer(int x, int ch) {
  while (x >= 0 && s[x] != ch) x = next[x];
  return ++x;
}
int query() {
  int now = 0, ret = 0;
  for (int i = 0; i < nowS.size(); ++i)
    now = transfer(now, nowS[i]), ret = now == len;
  return ret;
}
void insertA(int l, int r) {
  for (int i = r; i > r - len + 1 && i >= l; --i) nowS += t[i];
  ans += query();
  if (r - l + 1 >= len) {
    nowS = std::string(t.begin() + l, t.begin() + l + len - 1);
    std::reverse(nowS.begin(), nowS.end());
  } else if (nowS.size() >= len)
    nowS = nowS.substr(nowS.size() - len + 1);
}
void insertB(int l, int r) {
  for (int i = l; i < l + len - 1 && i <= r; ++i) nowS += t[i];
  ans += query();
  if (r - l + 1 >= len)
    nowS = std::string(t.begin() + r - len + 2, t.begin() + r + 1);
  else if (nowS.size() >= len)
    nowS = nowS.substr(nowS.size() - len + 1);
}
void solve() {
  int x, y, pA = 1, pB = 1;
  ans = 0;
  std::cin >> x >> y >> s, len = s.size();
  build_KMP();
  for (int i = 0; i < len; ++i) s[i] -= 'a';
  for (int i = 0; i < len; ++i) pA = sam::nxt[pA][s[i]];
  for (int i = len - 1; ~i; --i) pB = sam::nxt[pB][s[i]];
  std::vector<std::pair<int, int>> chainA, chainB;
  while (top[x] != top[y]) {
    if (dep[top[x]] > dep[top[y]])
      chainA.emplace_back(dfn[top[x]], dfn[x]), x = f[top[x]];
    else
      chainB.emplace_back(dfn[top[y]], dfn[y]), y = f[top[y]];
  }
  if (x != y) {
    if (dep[x] < dep[y])
      chainB.emplace_back(dfn[x] + 1, dfn[y]);
    else
      chainA.emplace_back(dfn[y] + 1, dfn[x]);
  }
  std::reverse(chainB.begin(), chainB.end());
  for (auto s : chainA) ans += sam::count(s.first, s.second, pB, len);
  for (auto s : chainB) ans += sam::count(s.first, s.second, pA, len);
  nowS.clear();
  for (auto s : chainA) insertA(s.first, s.second);
  for (auto s : chainB) insertB(s.first, s.second);
  std::cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n, t.resize(n + 1);
  char c;
  for (int i = 1, u, v; i < n; ++i)
    std::cin >> u >> v >> c, link(u, v, c - 'a');
  dfs0(1), top[1] = 1, dfs1(1), sam::init();
  int q;
  std::cin >> q;
  while (q--) solve();
  return 0;
}
