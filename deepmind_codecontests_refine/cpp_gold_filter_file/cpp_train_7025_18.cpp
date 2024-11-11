#include <bits/stdc++.h>
const int mod = 998244353;
using namespace std;
inline int read(void) {
  int f = 1, x = 0;
  char s = getchar();
  while (!isdigit(s)) {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (isdigit(s)) {
    x = (x << 1) + (x << 3) + (s ^ 48), s = getchar();
  }
  return x * f;
}
int n, q, tot, dfn[200100], siz[200100], cnt, tr[200100], ans[500100],
    pos[200100], k[500100];
struct ac_automaton {
  int nxt, ch[26];
} t[200100];
vector<int> st[200100], e[200100], qu[200100];
char s[200100];
queue<int> que;
struct Fenwick_Tree {
  inline int lowbit(int x) { return x & -x; }
  inline void modify(int a, int x) {
    while (a <= tot + 1) tr[a] += x, a += lowbit(a);
  }
  inline int query(int a) {
    int ans = 0;
    while (a > 0) ans += tr[a], a -= lowbit(a);
    return ans;
  }
} tree;
inline void insert(int p) {
  int now = 0;
  for (int i = 0; i < st[p].size(); i++) {
    if (!t[now].ch[st[p][i]]) t[now].ch[st[p][i]] = ++tot;
    now = t[now].ch[st[p][i]];
  }
  pos[p] = now;
}
inline void get_fail(void) {
  for (int i = 0; i < 26; i++)
    if (t[0].ch[i]) que.push(t[0].ch[i]);
  while (!que.empty()) {
    int h = que.front();
    que.pop();
    for (int i = 0; i < 26; i++) {
      if (t[h].ch[i]) {
        t[t[h].ch[i]].nxt = t[t[h].nxt].ch[i];
        que.push(t[h].ch[i]);
      } else
        t[h].ch[i] = t[t[h].nxt].ch[i];
    }
  }
}
inline void dfs(int rt) {
  dfn[rt] = ++cnt, siz[rt] = 1;
  for (int i = 0; i < e[rt].size(); i++)
    dfs(e[rt][i]), siz[rt] += siz[e[rt][i]];
}
signed main(void) {
  n = read(), q = read();
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int j = 1; j <= len; j++) st[i].push_back(s[j] - 'a');
    insert(i);
  }
  get_fail();
  for (int i = 1; i <= tot; i++) e[t[i].nxt].push_back(i);
  dfs(0);
  for (int i = 1; i <= q; i++) {
    int l = read(), r = read();
    k[i] = read();
    qu[l - 1].push_back(-i), qu[r].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    int now = 0;
    for (int j = 0; j < st[i].size(); j++) {
      now = t[now].ch[st[i][j]];
      tree.modify(dfn[now], 1);
    }
    for (int j = 0; j < qu[i].size(); j++) {
      if (qu[i][j] < 0)
        ans[-qu[i][j]] -=
            tree.query(dfn[pos[k[-qu[i][j]]]] + siz[pos[k[-qu[i][j]]]] - 1) -
            tree.query(dfn[pos[k[-qu[i][j]]]] - 1);
      else
        ans[qu[i][j]] +=
            tree.query(dfn[pos[k[qu[i][j]]]] + siz[pos[k[qu[i][j]]]] - 1) -
            tree.query(dfn[pos[k[qu[i][j]]]] - 1);
    }
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
