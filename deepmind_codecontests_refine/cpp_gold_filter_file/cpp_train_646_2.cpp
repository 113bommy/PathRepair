#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m, K;
int head[150010], nxt[150010 * 2], to[150010 * 2], tot;
void add(int u, int v) {
  tot++;
  nxt[tot] = head[u];
  head[u] = tot;
  to[tot] = v;
}
int dfn[150010], cnt_dfn, up[150010][22], dep[150010], size[150010], lg[150010];
void pre_dfs(int x, int las) {
  dfn[x] = ++cnt_dfn;
  size[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == las) continue;
    up[to[i]][0] = x;
    dep[to[i]] = dep[x] + 1;
    pre_dfs(to[i], x);
    size[x] += size[to[i]];
  }
}
int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int d = lg[dep[x] - dep[y]];
  for (int i = d; i >= 0; i--)
    if (dep[y] + (1 << i) <= dep[x]) x = up[x][i];
  if (x == y) return x;
  d = lg[dep[x]];
  for (int i = d; i >= 0; i--)
    if (up[x][i] != up[y][i]) x = up[x][i], y = up[y][i];
  return up[x][0];
}
int get_up(int x, int y) {
  int d = lg[y];
  for (int i = d; i >= 0; i--)
    if ((1 << i) <= y) y -= (1 << i), x = up[x][i];
  return x;
}
struct P {
  int s, t;
} p[150010];
vector<int> v[150010];
struct BIT {
  int t[150010];
  int lowbit(int x) { return x & (-x); }
  void modi(int x, int y) {
    for (int i = x; i <= n; i += lowbit(i)) t[i] += y;
  }
  int queryx(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += t[i];
    return res;
  }
  int query(int l, int r) { return queryx(r) - queryx(l - 1); }
} B, Ts, Tt;
long long ans;
struct Part1 {
  void dfs(int x, int las) {
    for (int i = 0; i < v[x].size(); i++) {
      int id = v[x][i], s = p[id].s, t = p[id].t;
      if (dep[s] - dep[x] >= K) {
        int y = get_up(s, dep[s] - dep[x] - K);
        ans += B.query(dfn[y], dfn[y] + size[y] - 1);
      }
      if (dep[t] - dep[x] >= K) {
        int y = get_up(t, dep[t] - dep[x] - K);
        ans += B.query(dfn[y], dfn[y] + size[y] - 1);
      }
    }
    for (int i = 0; i < v[x].size(); i++) {
      int id = v[x][i], s = p[id].s, t = p[id].t;
      B.modi(dfn[s], 1);
      B.modi(dfn[t], 1);
    }
    for (int i = head[x]; i; i = nxt[i])
      if (to[i] != las) dfs(to[i], x);
    for (int i = 0; i < v[x].size(); i++) {
      int id = v[x][i], s = p[id].s, t = p[id].t;
      B.modi(dfn[s], -1);
      B.modi(dfn[t], -1);
    }
  }
} p1;
bool cmp(int x, int y) { return dfn[x] < dfn[y]; }
int rt[150010];
struct Segment_Tree {
  int t[150010 * 30], ls[150010 * 30], rs[150010 * 30], cnt;
  int newnode() {
    cnt++;
    t[cnt] = ls[cnt] = rs[cnt] = 0;
    return cnt;
  }
  void update(int k) { t[k] = t[ls[k]] + t[rs[k]]; }
  void modi(int &k, int l, int r, int x) {
    if (!k) k = newnode();
    if (l == r) return t[k]++, void();
    int mid = (l + r) / 2;
    if (mid >= x)
      modi(ls[k], l, mid, x);
    else
      modi(rs[k], mid + 1, r, x);
    update(k);
  }
  int query(int k, int l, int r, int x, int y) {
    if (l >= x && r <= y) return t[k];
    int mid = (l + r) / 2, res = 0;
    if (mid >= x) res += query(ls[k], l, mid, x, y);
    if (mid < y) res += query(rs[k], mid + 1, r, x, y);
    return res;
  }
} S;
struct Part2 {
  int a[150010], cnt, book[150010], s[150010], top;
  vector<int> e[150010], q[150010];
  void _add(int u, int v) {
    if (u == v) return;
    e[u].push_back(v);
  }
  void Build_Tree(int x) {
    s[top = 1] = x;
    sort(a + 1, a + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++) {
      int x = a[i], f;
      while (top > 0) {
        f = LCA(s[top], x);
        if (top > 1 && dep[f] < dep[s[top - 1]])
          _add(s[top - 1], s[top]), top--;
        else if (dep[f] < dep[s[top]]) {
          _add(f, s[top]);
          top--;
          break;
        } else
          break;
      }
      if (s[top] != f) s[++top] = f;
      s[++top] = x;
    }
    while (top > 1) _add(s[top - 1], s[top]), top--;
  }
  void merge(int x, int y, int root) {
    if (q[x].size() < q[y].size()) swap(q[x], q[y]), swap(rt[x], rt[y]);
    if (dep[x] - dep[root] >= K)
      ans += 1ll * q[x].size() * q[y].size();
    else {
      for (int i = 0; i < q[y].size(); i++) {
        int id = q[y][i], t = p[id].t;
        if (dep[t] + dep[x] - 2 * dep[root] >= K) {
          int z = get_up(t, dep[t] + dep[x] - 2 * dep[root] - K);
          ans += S.query(rt[x], 1, n, dfn[z], dfn[z] + size[z] - 1);
        }
      }
    }
    while (q[y].size()) {
      int id = q[y].back();
      q[y].pop_back();
      int t = p[id].t;
      q[x].push_back(id);
      S.modi(rt[x], 1, n, dfn[t]);
    }
  }
  void dfs(int x, int root) {
    for (int i = 0; i < e[x].size(); i++) {
      int to = e[x][i];
      dfs(to, root);
      merge(x, to, root);
    }
  }
  void reco(int x) {
    book[x] = 0;
    q[x].clear();
    rt[x] = 0;
    for (int i = 0; i < e[x].size(); i++) reco(e[x][i]);
    e[x].clear();
  }
  void solve(int x) {
    cnt = 0;
    for (int i = 0; i < v[x].size(); i++) {
      int id = v[x][i];
      if (!book[p[id].s]) book[p[id].s] = 1, a[++cnt] = p[id].s;
    }
    Build_Tree(x);
    for (int i = 0; i < v[x].size(); i++) {
      int id = v[x][i], s = p[id].s, t = p[id].t;
      if (dep[s] + dep[t] - dep[x] * 2 >= K) {
        if (dep[s] - dep[x] >= K)
          ans += q[s].size();
        else {
          int z = get_up(t, dep[s] + dep[t] - dep[x] * 2 - K);
          ans += S.query(rt[s], 1, n, dfn[z], dfn[z] + size[z] - 1);
        }
      }
      S.modi(rt[s], 1, n, dfn[t]);
      q[s].push_back(id);
    }
    dfs(x, x);
    reco(x);
    S.cnt = 0;
  }
} p2;
struct Part3 {
  void dfs(int x, int las) {
    for (int i = 0; i < v[x].size(); i++) {
      int id = v[x][i], s = p[id].s, t = p[id].t;
      if (dep[s] - dep[x] >= K) {
        int y = get_up(s, dep[s] - dep[x] - K);
        ans += Tt.query(dfn[y], dfn[y] + size[y] - 1);
      }
      if (dep[t] - dep[x] >= K) {
        int y = get_up(t, dep[t] - dep[x] - K);
        ans += Ts.query(dfn[y], dfn[y] + size[y] - 1);
      }
      Ts.modi(dfn[s], 1);
      Tt.modi(dfn[t], 1);
    }
    for (int i = 0; i < v[x].size(); i++) {
      int id = v[x][i], s = p[id].s, t = p[id].t;
      Ts.modi(dfn[s], -1);
      Tt.modi(dfn[t], -1);
    }
    for (int i = head[x]; i; i = nxt[i])
      if (to[i] != las) dfs(to[i], x);
  }
} p3;
int main() {
  n = read();
  m = read();
  K = read();
  for (int i = 1; i < n; i++) {
    int q = read(), w = read();
    add(q, w);
    add(w, q);
  }
  lg[1] = 0;
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  pre_dfs(1, 0);
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++) up[i][j] = up[up[i][j - 1]][j - 1];
  for (int i = 1; i <= m; i++) {
    p[i].s = read(), p[i].t = read();
    if (dfn[p[i].s] > dfn[p[i].t]) swap(p[i].s, p[i].t);
    v[LCA(p[i].s, p[i].t)].push_back(i);
  }
  p1.dfs(1, 0);
  for (int i = 1; i <= n; i++) p2.solve(i);
  p3.dfs(1, 0);
  cout << ans << endl;
  return 0;
}
