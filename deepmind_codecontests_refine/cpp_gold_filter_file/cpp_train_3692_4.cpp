#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
struct node {
  int son[2];
  long long val, size, cnt, tag;
  long long sum, all;
};
node tr[100100];
vector<int> g[100100];
int fa[100100];
int que[100100], top;
long long ans;
double coe;
int n, q;
void upd(int x) {
  tr[x].size = tr[x].cnt + tr[tr[x].son[0]].size + tr[tr[x].son[1]].size;
  tr[x].sum =
      tr[tr[x].son[0]].sum + tr[tr[x].son[1]].sum + tr[x].val * tr[x].cnt;
}
void modify(int x, int y) {
  tr[x].tag += y;
  tr[x].all += y * tr[x].cnt;
}
void push_down(int x) {
  if (tr[x].tag) {
    if (tr[x].son[0]) modify(tr[x].son[0], tr[x].tag);
    if (tr[x].son[1]) modify(tr[x].son[1], tr[x].tag);
    tr[x].tag = 0;
  }
}
bool is_root(int x) { return tr[fa[x]].son[0] != x && tr[fa[x]].son[1] != x; }
void rotate(int x) {
  int y = fa[x];
  int z = fa[y];
  int l = (tr[y].son[1] == x);
  int r = l ^ 1;
  if (!is_root(y)) tr[z].son[tr[z].son[1] == y] = x;
  fa[x] = z;
  fa[y] = x;
  fa[tr[x].son[r]] = y;
  tr[y].son[l] = tr[x].son[r];
  tr[x].son[r] = y;
  upd(y);
}
void splay(int x) {
  int y, z;
  que[top = 1] = x;
  for (int i = x; !is_root(i); i = fa[i]) que[++top] = fa[i];
  while (top) push_down(que[top--]);
  for (; !is_root(x); rotate(x)) {
    y = fa[x];
    z = fa[y];
    if (!is_root(y))
      rotate(((tr[z].son[0] == y) ^ (tr[y].son[0] == x)) ? x : y);
  }
  upd(x);
}
int access(int x) {
  int y = 0;
  for (; x; y = x, x = fa[x]) {
    splay(x);
    tr[x].cnt += tr[tr[x].son[1]].size;
    tr[x].son[1] = y;
    tr[x].cnt -= tr[y].size;
    upd(x);
  }
  return y;
}
void dfs(int v) {
  tr[v].cnt = 1;
  tr[v].all = 1;
  for (int i = 0; i < g[v].size(); i++) {
    int u = g[v][i];
    dfs(u);
    tr[v].all += tr[v].cnt * tr[u].cnt * 2;
    tr[v].cnt += tr[u].cnt;
  }
  ans += tr[v].val * tr[v].all;
  upd(v);
}
void move(int x, int y) {
  int z;
  access(y);
  splay(x);
  for (z = x; !is_root(z); z = tr[z].son[0])
    ;
  if (fa[z])
    access(x);
  else
    swap(x, y);
  if (!tr[x].son[0])
    z = fa[x];
  else
    for (z = tr[x].son[0]; tr[z].son[1]; z = tr[z].son[1])
      ;
  if (z == y) return;
  access(z);
  splay(z);
  splay(x);
  tr[z].cnt -= tr[x].size;
  modify(z, -2 * tr[x].size);
  upd(z);
  ans -= tr[z].sum * tr[x].size * 2;
  access(y);
  splay(y);
  ans += tr[y].sum * tr[x].size * 2;
  modify(y, 2 * tr[x].size);
  tr[y].cnt += tr[x].size;
  upd(y);
  fa[x] = y;
}
void add(int x, int y) {
  splay(x);
  ans += (y - tr[x].val) * tr[x].all;
  tr[x].val = y;
}
int main() {
  n = read();
  for (int i = 2; i <= n; i++) {
    fa[i] = read();
    g[fa[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) tr[i].val = read();
  dfs(1);
  coe = 1.0 / n / n;
  printf("%.9lf\n", coe * ans);
  q = read();
  char op[5];
  while (q--) {
    scanf("%s", op);
    int x = read();
    int y = read();
    if (op[0] == 'P') {
      move(x, y);
    } else {
      add(x, y);
    }
    printf("%.9lf\n", coe * ans);
  }
  return 0;
}
