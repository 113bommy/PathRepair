#include <bits/stdc++.h>
using namespace std;
struct node {
  int to, nxt;
} e[200005 * 2];
int head[200005], cnt, in[200005], out[200005], dfn;
void build(int a, int b) {
  e[++cnt].to = b;
  e[cnt].nxt = head[a];
  head[a] = cnt;
}
struct qs {
  int id, way, q, bl;
} Q[200005 * 2];
int n, t[200005][27], tot, pos[200005], fail[200005], zq, tr[200005],
    ztr[200005];
long long ans[200005];
char fw[200005];
void build(int id) {
  int p = 0, len = strlen(fw);
  ztr[id] = ztr[id - 1];
  for (int i = 0; i < len; ++i) {
    fw[i] -= 'a';
    if (!t[p][fw[i]]) t[p][fw[i]] = ++tot;
    p = t[p][fw[i]];
    tr[++ztr[id]] = p;
  }
  pos[id] = p;
}
void getfail() {
  queue<int> q;
  for (int i = 0; i < 26; ++i) {
    if (t[0][i]) {
      build(0, t[0][i]);
      q.push(t[0][i]);
    }
  }
  int p;
  while (!q.empty()) {
    p = q.front();
    q.pop();
    for (int v, i = 0; i < 26; ++i) {
      if (t[p][i]) {
        v = fail[p];
        while (v && !t[v][i]) v = fail[v];
        fail[t[p][i]] = t[v][i];
        q.push(t[p][i]);
        build(t[v][i], t[p][i]);
      }
    }
  }
}
void dfs(int p) {
  in[p] = ++dfn;
  for (int i = head[p]; i; i = e[i].nxt) {
    dfs(e[i].to);
  }
  out[p] = dfn;
}
bool cmp(qs a, qs b) { return a.q < b.q; }
int T[200005];
void add(int p, int v) {
  while (p <= dfn) {
    T[p] += v;
    p += p & (-p);
  }
}
inline int query(int p) {
  int ans = 0;
  while (p > 0) {
    ans += T[p];
    p -= p & (-p);
  }
  return ans;
}
int main() {
  int q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", fw);
    build(i);
  }
  getfail();
  dfs(0);
  for (int a, b, c, i = 1; i <= q; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    if (a != 1) {
      Q[++zq].id = pos[c];
      Q[zq].q = a - 1;
      Q[zq].way = -1;
      Q[zq].bl = i;
    }
    Q[++zq].id = pos[c];
    Q[zq].q = b;
    Q[zq].way = 1;
    Q[zq].bl = i;
  }
  sort(Q + 1, Q + 1 + zq, cmp);
  int hc = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = ztr[i - 1] + 1; j <= ztr[i]; ++j) {
      add(in[tr[j]], 1);
    }
    while (hc <= zq && Q[hc].q == i) {
      int mmp = (query(out[Q[hc].id]) - query(in[Q[hc].id] - 1)) * Q[hc].way;
      ans[Q[hc].bl] += mmp;
      ++hc;
    }
  }
  for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
  return 0;
}
