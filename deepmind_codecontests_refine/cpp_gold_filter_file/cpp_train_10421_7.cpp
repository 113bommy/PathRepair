#include <bits/stdc++.h>
using namespace std;
const int N = 200050;
inline int read() {
  char ch;
  while ((ch = getchar()) < '0' || ch > '9')
    ;
  int res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + ch - '0';
  return res;
}
char s[N >> 1], t;
int tot, rt[N], lst, n, pre[N], qlm[N], len[N], tar[N][28];
struct node {
  int ls, rs;
} d[N * 42];
struct Seg {
  int rnm;
  void modify(int &k, int l, int r, int x) {
    if (!k) k = ++rnm;
    if (l == r) return;
    int mid = l + r >> 1;
    if (x <= mid)
      modify(d[k].ls, l, mid, x);
    else
      modify(d[k].rs, mid + 1, r, x);
  }
  bool query(int k, int l, int r, int x, int y) {
    if (!k || l > y || r < x) return 0;
    if (l >= x && r <= y) return 1;
    int mid = l + r >> 1;
    if (query(d[k].ls, l, mid, x, y)) return 1;
    if (query(d[k].rs, mid + 1, r, x, y)) return 1;
    return 0;
  }
  int mrge(int k1, int k2) {
    if (!k1 || !k2) return k1 | k2;
    int now = ++rnm;
    d[now].ls = mrge(d[k1].ls, d[k2].ls);
    d[now].rs = mrge(d[k1].rs, d[k2].rs);
    return now;
  }
} T;
int node(int l) {
  len[++tot] = l;
  return tot;
}
void ins(int c) {
  int i = lst;
  lst = node(len[i] + 1);
  qlm[lst] = 1;
  while (!tar[i][c]) {
    tar[i][c] = lst;
    if (!(i = pre[i])) return void(pre[lst] = 1);
  }
  int rtm = tar[i][c];
  if (len[rtm] == len[i] + 1) return void(pre[lst] = rtm);
  int gnn = node(len[i] + 1);
  pre[gnn] = pre[rtm];
  pre[rtm] = pre[lst] = gnn;
  memcpy(tar[gnn], tar[rtm], sizeof(tar[0]));
  do {
    tar[i][c] = gnn;
    i = pre[i];
  } while (i && tar[i][c] == rtm);
}
vector<int> G[N];
void dfs(int u) {
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    dfs(v);
    rt[u] = T.mrge(rt[u], rt[v]);
  }
  if (qlm[u]) T.modify(rt[u], 1, n, len[u]);
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  lst = tot = 1;
  for (int i = 1; i <= n; i++) ins(s[i] - 'a');
  for (int i = 2; i <= tot; i++) G[pre[i]].push_back(i);
  dfs(1);
  int q = read(), l, r;
  while (q--) {
    l = read();
    r = read();
    scanf("%s", s + 1);
    int pos = -1, u = 1, m = strlen(s + 1);
    s[++m] = 'a' - 1;
    for (int i = 1; i <= m; i++) {
      int c = s[i] - 'a';
      for (int j = c + 1; j < 26; j++)
        if (tar[u][j] && T.query(rt[tar[u][j]], 1, n, l + i - 1, r)) {
          pos = i;
          t = 'a' + j;
          break;
        }
      if (i == m || !tar[u][c] || !T.query(rt[tar[u][c]], 1, n, l + i - 1, r))
        break;
      u = tar[u][c];
    }
    if (pos == -1)
      printf("-1\n");
    else {
      for (int i = 1; i < pos; i++) printf("%c", s[i]);
      printf("%c\n", t);
    }
  }
  return 0;
}
