#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
struct edge {
  int v, nxt;
} e[maxn << 1];
int head[maxn], ecnt = 0;
void add(int u, int v) { e[++ecnt] = (edge){v, head[u]}, head[u] = ecnt; }
vector<int> p[maxn];
int pos[maxn];
int tree[maxn];
void update(int x, int v) {
  for (; x < maxn; x += x & -x) tree[x] += v;
}
long long query(int x) {
  long long ret = 0;
  for (; x; x -= x & -x) ret += tree[x];
  return ret;
}
namespace ACAM {
int son[maxn][26], fail[maxn], cnt;
void insert(char *s, int id) {
  int len = strlen(s + 1), u = 0;
  p[id].push_back(u);
  for (int i = 1; i <= len; i++) {
    int c = s[i] - 'a';
    if (!son[u][c]) son[u][c] = ++cnt;
    u = son[u][c];
    p[id].push_back(u);
  }
  pos[id] = u;
}
void build() {
  queue<int> que;
  for (int c = 0; c < 26; c++) {
    int u = son[0][c];
    if (u) que.push(u);
  }
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int c = 0; c < 26; c++) {
      int v = son[u][c];
      if (!v)
        son[u][c] = son[fail[u]][c];
      else
        fail[v] = son[fail[u]][c], que.push(v);
    }
  }
  for (int i = 1; i <= cnt; i++) add(fail[i], i);
}
}  // namespace ACAM
int n, q, siz[maxn], dfn[maxn], idx = 0;
char s[maxn];
vector<pair<int, int> > op[maxn];
void dfs(int u) {
  siz[u] = 1, dfn[u] = ++idx;
  for (int i = head[u]; ~i; i = e[i].nxt) {
    int v = e[i].v;
    dfs(v);
    siz[u] += siz[v];
  }
}
long long ans[maxn];
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    ACAM::insert(s, i);
  }
  ACAM::build();
  for (int i = 1; i <= q; i++) {
    int k, l, r;
    scanf("%d%d%d", &l, &r, &k);
    op[l - 1].push_back(make_pair(i, -k));
    op[r].push_back(make_pair(i, k));
  }
  dfs(0);
  for (int i = 1; i <= n; i++) {
    for (auto t : p[i]) update(dfn[t], 1);
    for (auto qr : op[i]) {
      int id = qr.first, u = qr.second;
      if (u < 0)
        u = -u, u = pos[u],
        ans[id] -= query(dfn[u] + siz[u] - 1) - query(dfn[u] - 1);
      else
        u = pos[u], ans[id] += query(dfn[u] + siz[u] - 1) - query(dfn[u] - 1);
    }
  }
  for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
}
