#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v[100010];
int query(int a, int b) {
  printf("? %d %d\n", a, b);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  if (ret == -1) exit(0);
  return ret;
}
bool vis[100010];
int low[100010], dfn[100010], tim, stk[100010], top;
vector<int> blk[100010];
int bel[100010], bcnt = 0, s[100010];
void dfs(int np) {
  dfn[np] = low[np] = ++tim;
  vis[np] = 1;
  stk[++top] = np;
  for (int i = 0; i < v[np].size(); i++) {
    int x = v[np][i];
    if (!dfn[x]) {
      dfs(x);
      low[np] = min(low[np], low[x]);
    } else if (vis[x])
      low[np] = min(low[np], dfn[x]);
  }
  if (low[np] == dfn[np]) {
    ++bcnt;
    int tmp;
    while ((tmp = stk[top--])) {
      bel[tmp] = bcnt;
      blk[bcnt].push_back(tmp);
      vis[tmp] = 0;
      if (tmp == np) break;
    }
    s[bcnt] = blk[bcnt].size();
  }
}
int a[100010], b[100010], deg[100010];
set<pair<int, int> > st;
int pos[100010], pcnt;
vector<int> v2[100010];
void add(int id) {
  for (int i = 0; i < blk[id].size(); i++) {
    int x = blk[id][i];
    pos[x] = ++pcnt;
    st.insert(make_pair(pos[x], x));
  }
}
void del(int id) {
  st.erase(make_pair(pos[id], id));
  id = bel[id];
  s[id]--;
  if (!s[id]) {
    for (int i = 0; i < v2[id].size(); i++) {
      int x = v2[id][i];
      deg[x]--;
      if (!deg[x]) add(x);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a[i], &b[i]);
    v[a[i]].push_back(b[i]);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) dfs(i);
  for (int i = 1; i <= m; i++) {
    if (bel[a[i]] != bel[b[i]]) {
      v2[bel[a[i]]].push_back(bel[b[i]]);
      deg[bel[b[i]]]++;
    }
  }
  int tp = 0;
  for (int i = 1; i <= n; i++) {
    if (!deg[bel[i]]) {
      tp = i;
      break;
    }
  }
  for (int i = 1; i <= bcnt; i++)
    if (!deg[i]) add(i);
  while (1) {
    set<pair<int, int> >::iterator c = st.end();
    c--;
    if (bel[st.begin()->second] == bel[tp] && bel[c->second] == bel[tp]) {
      printf("! %d\n", tp);
      return 0;
    }
    if (bel[st.begin()->second] != bel[tp]) {
      int y = st.begin()->second;
      if (query(tp, y))
        del(y);
      else
        del(tp), tp = y;
    } else {
      int y = c->second;
      if (query(tp, y))
        del(y);
      else
        del(tp), tp = y;
    }
  }
  return 0;
}
