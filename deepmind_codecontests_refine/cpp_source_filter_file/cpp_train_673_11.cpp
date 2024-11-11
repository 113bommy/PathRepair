#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
struct edge {
  int id;
  int tong;
  edge *next;
};
long long ttmp1[100050], ttmp2[100050];
edge edges[100050 << 1];
edge *adj[100050];
int ednum;
inline void addEdge(int a, int b, int c) {
  edge *tmp = &edges[ednum++];
  tmp->id = b;
  tmp->tong = c;
  tmp->next = adj[a];
  adj[a] = tmp;
}
int fa[100050], top[100050], son[100050], siz[100050], id[100050], fid[100050],
    dep[100050];
bool vis[100050];
void dfs1(int me, int deep) {
  int maxsiz = -1;
  vis[me] = 1;
  dep[me] = deep;
  siz[me] = 1;
  for (edge *it = adj[me]; it; it = it->next) {
    if (!vis[it->id]) {
      fa[it->id] = me;
      dfs1(it->id, deep + 1);
      if (maxsiz < siz[it->id]) {
        maxsiz = siz[it->id];
        son[me] = it->id;
      }
      siz[me] += siz[it->id];
    }
  }
}
int num;
void dfs2(int me, int t) {
  vis[me] = 1;
  top[me] = t;
  id[me] = ++num;
  fid[num] = me;
  if (son[me]) {
    dfs2(son[me], t);
  }
  for (edge *it = adj[me]; it; it = it->next) {
    if (!vis[it->id]) {
      dfs2(it->id, it->id);
    }
  }
}
void dfs3(int pos) {
  vis[pos] = 1;
  for (edge *it = adj[pos]; it; it = it->next) {
    if (!vis[it->id]) {
      if (it->tong == 1) {
        ttmp2[it->id] = 1;
      } else if (it->tong == 2) {
        ttmp1[it->id] = 1;
      }
      dfs3(it->id);
    }
  }
}
int solve(int a, int b) {
  while (1) {
    if (top[a] == top[b])
      return dep[a] <= dep[b] ? a : b;
    else if (dep[top[a]] >= dep[top[b]])
      a = fa[top[a]];
    else
      b = fa[top[b]];
  }
}
long long ans;
long long biaoge[1000050];
int jia1[100050], jia2[100050];
struct ss {
  int dep;
  int pos;
  ss(int a, int b) {
    pos = a;
    dep = b;
  }
};
bool operator<(const ss &a, const ss &b) { return a.dep > b.dep; }
multiset<ss> ms;
void dfs4(int pos) {
  vis[pos] = 1;
  ms.insert(ss(pos, dep[pos]));
  for (edge *it = adj[pos]; it; it = it->next) {
    if (!vis[it->id]) {
      dfs4(it->id);
    }
  }
}
int main() {
  long long ttt = 1;
  for (int i = 1; i <= 1000008; i++) {
    biaoge[i] = biaoge[i - 1] + ttt;
    biaoge[i] %= mod;
    ttt <<= 1;
    ttt %= mod;
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b, typ;
    scanf("%d%d%d", &a, &b, &typ);
    if (typ == 0) {
      addEdge(a, b, 0);
      addEdge(b, a, 0);
    } else {
      addEdge(a, b, 1);
      addEdge(b, a, 2);
    }
  }
  dfs1(1, 1);
  memset(vis, 0, sizeof(vis));
  dfs2(1, 1);
  memset(vis, 0, sizeof(vis));
  dfs3(1);
  int bef = 1, now;
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d", &now);
    int gra = solve(bef, now);
    jia2[bef]++;
    jia2[gra]--;
    jia1[now]++;
    jia1[gra]--;
    bef = now;
  }
  memset(vis, 0, sizeof(vis));
  dfs4(1);
  while (!ms.empty()) {
    ss tmp = *ms.begin();
    ms.erase(ms.begin());
    if (ttmp1[tmp.pos]) {
      ans += biaoge[jia2[tmp.pos]];
      ans %= mod;
    }
    if (ttmp2[tmp.pos]) {
      ans += biaoge[jia1[tmp.pos]];
      ans %= mod;
    }
    jia1[fa[tmp.pos]] += jia1[tmp.pos];
    jia2[fa[tmp.pos]] += jia2[tmp.pos];
  }
  printf("%I64d\n", ans);
}
