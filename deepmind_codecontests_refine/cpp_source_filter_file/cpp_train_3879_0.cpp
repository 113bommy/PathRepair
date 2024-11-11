#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (isdigit(ch)) {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res * f;
}
namespace qiqi {
const int N = 2e5 + 5;
int n, m, cnt, dfn[N], pos[N], ecnt, head[N], tag[N * 4], val[N * 4];
bool in[N];
char s[N];
vector<char> a[N];
vector<int> id[N];
vector<pair<int, int> > o[N];
struct Edge {
  int v, nxt;
} e[N];
inline void add(int u, int v) {
  e[++ecnt] = (Edge){v, head[u]};
  head[u] = ecnt;
  in[v] = 1;
}
void dfs(int u) {
  dfn[u] = ++cnt;
  for (int i = head[u], v = e[i].v; i; v = e[i = e[i].nxt].v) dfs(v);
  pos[u] = cnt;
}
inline void ins(int x, int y) {
  if (dfn[x] > dfn[y]) swap(x, y);
  o[dfn[x]].push_back(pair<int, int>(y, 1));
  o[pos[x] + 1].push_back(pair<int, int>(y, -1));
}
inline int ls(int x) { return x << 1; }
inline int rs(int x) { return x << 1 | 1; }
inline void push_up(int x, int l, int r) {
  val[x] = tag[x] ? r - l + 1 : val[ls(x)] + val[rs(x)];
}
void upd(int x, int l, int r, int pl, int pr, int k) {
  if (pl <= l && r <= pr) {
    tag[x] += k;
    return push_up(x, l, r);
  }
  int mid = (l + r) / 2;
  if (pl <= mid) upd(ls(x), l, mid, pl, pr, k);
  if (pr > mid) upd(rs(x), mid + 1, r, pl, pr, k);
  push_up(x, l, r);
}
void main() {
  n = read();
  m = read();
  for (int i = (1); i <= (n); ++i) {
    a[i].resize(m + 1);
    id[i].resize(m + 1);
  }
  for (int i = (1); i <= (n); ++i) {
    scanf("%s", s + 1);
    for (int j = (1); j <= (m); ++j) {
      a[i][j] = s[j];
      id[i][j] = ++cnt;
    }
  }
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) {
      if (a[i][j] == 'U') {
        if (i >= 2 && i < n) add(id[i - 1][j], id[i + 1][j]);
        if (i < n - 1) add(id[i + 2][j], id[i][j]);
      }
      if (a[i][j] == 'L') {
        if (j >= 2 && j < m) add(id[i][j - 1], id[i][j + 1]);
        if (j < m - 1) add(id[i][j + 2], id[i][j]);
      }
    }
  cnt = 0;
  for (int k = (0); k <= (1); ++k)
    for (int i = (1); i <= (n); ++i)
      for (int j = (1); j <= (m); ++j)
        if (!in[id[i][j]] && ((i ^ j) & 1) == k) dfs(id[i][j]);
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) {
      if (a[i][j] == 'U') ins(id[i][j], id[i + 1][j]);
      if (a[i][j] == 'L') ins(id[i][j], id[i][j + 1]);
    }
  long long ans = 0;
  for (int i = (1); i <= (n * m / 2); ++i) {
    for (int j = (0); j <= ((int)o[i].size() - 1); ++j)
      upd(1, 1, n * m, dfn[o[i][j].first], pos[o[i][j].first], o[i][j].second);
    ans += val[1];
  }
  printf("%lld\n", ans);
}
}  // namespace qiqi
int main() {
  qiqi::main();
  return 0;
}
