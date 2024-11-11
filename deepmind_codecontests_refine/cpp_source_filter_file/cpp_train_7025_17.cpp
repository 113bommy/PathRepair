#include <bits/stdc++.h>
using namespace std;
const int N = 400100;
inline int read() {
  char ch;
  while ((ch = getchar()) < '0' || ch > '9')
    ;
  int res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + ch - '0';
  return res;
}
int tar[N][26], pre[N], n, Q, st[N], len[N], lst, tot = 1;
int ans[N], in[N], out[N], cnt, K[500100], ed[N];
vector<int> T[N], op[2][N];
int node(int l) {
  len[++tot] = l;
  return tot;
}
void dfs(int u) {
  in[u] = ++cnt;
  for (int i = 0; i < T[u].size(); i++) {
    int v = T[u][i];
    dfs(v);
  }
  out[u] = cnt;
}
void ins(int c) {
  int i = lst;
  int *op = tar[i][c] ? &lst : &pre[lst = node(len[i] + 1)];
  while (!tar[i][c]) {
    tar[i][c] = lst;
    while (!(i = pre[i])) return void(*op = 1);
  }
  int rtm = tar[i][c];
  if (len[rtm] == len[i] + 1) return void(*op = rtm);
  int gnn = node(len[i] + 1);
  memcpy(tar[gnn], tar[rtm], sizeof(tar[0]));
  pre[gnn] = pre[rtm];
  *op = pre[rtm] = gnn;
  do {
    tar[i][c] = gnn;
    i = pre[i];
  } while (i && tar[i][c] == rtm);
}
struct Tree {
  int d[N];
  inline int lowbit(int x) { return x & -x; }
  void upt(int x) {
    for (int i = x; i <= tot; i += lowbit(i)) d[i]++;
  }
  int qry(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += d[i];
    return res;
  }
  int query(int l, int r) { return qry(r) - qry(l - 1); }
} t;
char s[N];
int main() {
  n = read();
  Q = read();
  for (int i = 1; i <= n; i++) {
    lst = 1;
    scanf("%s", s + st[i]);
    int ln = strlen(s + st[i]);
    st[i + 1] = st[i] + ln;
    for (int j = st[i]; j < st[i + 1]; j++) ins(s[j] - 'a');
    ed[i] = lst;
  }
  for (int i = 2; i <= tot; i++) T[pre[i]].push_back(i);
  dfs(1);
  int l, r;
  for (int i = 1; i <= Q; i++) {
    l = read();
    r = read();
    K[i] = read();
    op[0][l - 1].push_back(i);
    op[1][r].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    int u = 1;
    for (int j = st[i]; j < st[i + 1]; j++)
      u = tar[u][s[j] - 'a'], t.upt(in[u]);
    for (int j = 0; j < op[0][i].size(); j++)
      ans[op[0][i][j]] -=
          t.query(in[ed[K[op[0][i][j]]]], out[ed[K[op[0][i][j]]]]);
    for (int j = 0; j < op[1][i].size(); j++)
      ans[op[1][i][j]] +=
          t.query(in[ed[K[op[1][i][j]]]], out[ed[K[op[1][i][j]]]]);
  }
  for (int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
  return 0;
}
