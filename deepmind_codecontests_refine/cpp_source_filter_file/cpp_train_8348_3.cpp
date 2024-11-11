#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
int n, Link[100010], sum[100010], dep[100010], F[100010], son[100010],
    T = 0, dfn[100010], top[100010], cnt = 0;
int inv[100010];
struct das {
  int v, nex;
} e[200010];
struct dsa {
  int L, R, id, len;
} a[100010];
struct SubTree {
  int l, r, sum, tag;
} t[400010];
bool cmp(dsa p1, dsa p2) { return p1.L < p2.L; }
void Insert(int x, int y) {
  e[++T].nex = Link[x];
  e[T].v = y;
  Link[x] = T;
}
void dfs(int now, int fa) {
  sum[now] = 1;
  F[now] = fa;
  dep[now] = dep[fa] + 1;
  for (int i = Link[now]; i; i = e[i].nex) {
    if (e[i].v == fa) continue;
    dfs(e[i].v, now);
    sum[now] += sum[e[i].v];
    if (sum[e[i].v] > sum[son[now]]) son[now] = e[i].v;
  }
  return;
}
void dfs1(int now, int to) {
  dfn[now] = ++cnt;
  top[now] = to;
  if (son[now]) dfs1(son[now], to);
  for (int i = Link[now]; i; i = e[i].nex) {
    if (e[i].v == F[now] || e[i].v == son[now]) continue;
    dfs1(e[i].v, e[i].v);
  }
  return;
}
void Build(int p, int l, int r) {
  t[p].l = l;
  t[p].r = r;
  if (l == r) return;
  int mid = (t[p].l + t[p].r) >> 1;
  Build(p * 2, l, mid);
  Build(p * 2 + 1, mid + 1, r);
  return;
}
void Pass(int p) {
  t[p * 2].sum =
      (t[p * 2].sum + 1LL * t[p].tag * (t[p * 2].r - t[p * 2].l + 1) % Mod) %
      Mod;
  t[p * 2 + 1].sum =
      (t[p * 2 + 1].sum +
       1LL * t[p].tag * (t[p * 2 + 1].r - t[p * 2 + 1].l + 1) % Mod) %
      Mod;
  t[p * 2].tag = (t[p * 2].tag + t[p].tag) % Mod;
  t[p * 2 + 1].tag = (t[p * 2 + 1].tag + t[p].tag) % Mod;
  t[p].tag = 0;
  return;
}
void Modiffy(int p, int l, int r, int val) {
  if (t[p].l == l && t[p].r == r) {
    t[p].tag = (t[p].tag + val) % Mod;
    t[p].sum = (t[p].sum + 1LL * val * (t[p].r - t[p].l + 1) % Mod) % Mod;
    return;
  }
  Pass(p);
  int mid = (t[p].l + t[p].r) >> 1;
  if (r <= mid)
    Modiffy(p * 2, l, r, val);
  else if (l > mid)
    Modiffy(p * 2 + 1, l, r, val);
  else
    Modiffy(p * 2, l, mid, val), Modiffy(p * 2 + 1, mid + 1, r, val);
  t[p].sum = (t[p * 2].sum + t[p * 2 + 1].sum) % Mod;
}
int Query(int p, int l, int r) {
  if (t[p].l == l && t[p].r == r) return t[p].sum;
  Pass(p);
  int mid = (t[p].l + t[p].r) >> 1;
  if (r <= mid) return Query(p * 2, l, r);
  if (l > mid) return Query(p * 2 + 1, l, r);
  return (Query(p * 2, l, mid) + Query(p * 2 + 1, mid + 1, r)) % Mod;
}
int Query_Path(int x) {
  int sum = 0, fx = top[x];
  while (fx != 1) {
    sum = (sum + Query(1, dfn[fx], dfn[x])) % Mod;
    x = F[fx];
    fx = top[x];
  }
  sum = (sum + Query(1, 1, dfn[x])) % Mod;
  return sum;
}
void Modiffy_Path(int x, int v) {
  v = (v + Mod) % Mod;
  int fx = top[x];
  while (fx != 1) {
    Modiffy(1, dfn[fx], dfn[x], v);
    x = F[fx];
    fx = top[x];
  }
  Modiffy(1, 1, dfn[x], v);
  return;
}
int main() {
  scanf("%d", &n);
  int Max = 0, P = 1, Max_c = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].L, &a[i].R);
    a[i].len = a[i].R - a[i].L + 1;
    Max = max(Max, a[i].len);
    a[i].id = i;
    Max_c = max(Max_c, a[i].R);
    P = 1LL * P * a[i].len % Mod;
  }
  inv[1] = 1;
  inv[0] = 1;
  for (int i = 2; i <= Max; i++)
    inv[i] = 1LL * (Mod - Mod / i) * inv[Mod % i] % Mod;
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    Insert(x, y);
    Insert(y, x);
  }
  dfs(1, 0);
  dfs1(1, 1);
  Build(1, 1, n);
  sort(a + 1, a + n + 1, cmp);
  int k = 0, s = 0, s1 = 0, ans = 0, s2 = 0;
  priority_queue<pair<int, int> > q;
  for (int c = 1; c <= Max_c; c++) {
    while (q.size()) {
      int x = q.top().second;
      if (a[x].R < c) {
        q.pop();
        s = (s - inv[a[x].len] + Mod) % Mod;
        Modiffy_Path(a[x].id, -inv[a[x].len]);
        int val = Query_Path(a[x].id);
        s1 = (s1 - 1LL * dep[a[x].id] * inv[a[x].len] % Mod + Mod) % Mod;
        s2 = (s2 - 1LL * inv[a[k].len] * P % Mod * s1 % Mod + Mod) % Mod;
        s2 =
            (s2 - 1LL * dep[a[k].id] * inv[a[k].len] % Mod * P % Mod * s % Mod +
             Mod) %
            Mod;
        s2 = (s2 + 2LL * val % Mod * inv[a[k].len] % Mod * P % Mod) % Mod;
      } else
        break;
    }
    while (k < n && a[k + 1].L <= c) {
      k++;
      int val = Query_Path(a[k].id);
      s2 = (s2 + 1LL * inv[a[k].len] * P % Mod * s1 % Mod) % Mod;
      s2 = (s2 + 1LL * dep[a[k].id] * inv[a[k].len] % Mod * P % Mod * s % Mod) %
           Mod;
      s2 = (s2 - 2LL * val % Mod * inv[a[k].len] % Mod * P % Mod + Mod) % Mod;
      s = (s + inv[a[k].len]) % Mod;
      s1 = (s1 + 1LL * dep[a[k].id] * inv[a[k].len] % Mod) % Mod;
      Modiffy_Path(a[k].id, inv[a[k].len]);
      q.push(make_pair(-a[k].R, k));
    }
    ans = (ans + s2) % Mod;
  }
  cout << ans;
  return 0;
}
