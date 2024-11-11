#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n, m;
int pos;
struct event {
  int op, x, v, u;
} a[210000];
int v[210000];
vector<int> f[210000];
int cnt;
int b[210000];
int l[210000], r[210000];
int cx[210000];
void dfs(int x, int fa) {
  b[++cnt] = x;
  cx[x] = cnt;
  l[x] = cnt;
  for (int i = 0; i < f[x].size(); i++) dfs(f[x][i], x);
  r[x] = cnt;
}
long long pow_mod(long long a, long long e) {
  long long res = 1;
  for (; e; a = a * a % mod, e >>= 1)
    if (e & 1) res = res * a % mod;
  return res;
}
int sz[210000];
struct node {
  long long f, v, sum, lazy;
  int l, r;
} tr[1100000];
void update(int k) { tr[k].sum = (tr[k << 1].sum + tr[k << 1 | 1].sum) % mod; }
void pushdown(int k) {
  if (tr[k].lazy != 1 && tr[k].l != tr[k].r) {
    int p = k << 1;
    tr[p].f = tr[p].f * tr[k].lazy % mod;
    tr[p].sum = tr[p].sum * tr[k].lazy % mod;
    tr[p].lazy = tr[p].lazy * tr[k].lazy % mod;
    p = k << 1 | 1;
    tr[p].f = tr[p].f * tr[k].lazy % mod;
    tr[p].sum = tr[p].sum * tr[k].lazy % mod;
    tr[p].lazy = tr[p].lazy * tr[k].lazy % mod;
    tr[k].lazy = 1;
  }
}
void build(int k, int l, int r) {
  tr[k].l = l, tr[k].r = r;
  tr[k].lazy = tr[k].f = 1;
  if (l == r) {
    if (l == 1) tr[k].f = 1, tr[k].v = v[1], tr[k].sum = v[1];
    return;
  }
  int mid = (l + r) / 2;
  build(k << 1, l, mid), build(k << 1 | 1, mid + 1, r);
  update(k);
}
void change(int k, int a, long long b) {
  int l = tr[k].l, r = tr[k].r;
  pushdown(k);
  if (l == r) {
    tr[k].v = b;
    tr[k].sum = tr[k].f * b % mod;
    return;
  }
  int mid = (l + r) / 2;
  if (a <= mid)
    change(k << 1, a, b);
  else
    change(k << 1 | 1, a, b);
  update(k);
}
void change2(int k, int a, int b, long long c) {
  int l = tr[k].l, r = tr[k].r;
  pushdown(k);
  if (l == a && r == b) {
    tr[k].f = tr[k].f * c % mod;
    tr[k].sum = tr[k].sum * c % mod;
    tr[k].lazy = c;
    return;
  }
  int mid = (l + r) / 2;
  if (b <= mid)
    change2(k << 1, a, b, c);
  else if (a > mid)
    change2(k << 1 | 1, a, b, c);
  else
    change2(k << 1, a, mid, c), change2(k << 1 | 1, mid + 1, b, c);
  update(k);
}
long long ask(int k, int a) {
  int l = tr[k].l, r = tr[k].r;
  pushdown(k);
  if (l == r) return pow_mod(tr[k].f, mod - 2);
  int mid = (l + r) / 2;
  long long res;
  if (a <= mid)
    res = ask(k << 1, a);
  else
    res = ask(k << 1 | 1, a);
  update(k);
  return res;
}
long long ask2(int k, int a, int b) {
  int l = tr[k].l, r = tr[k].r;
  pushdown(k);
  if (l == a && r == b) return tr[k].sum;
  int mid = (l + r) / 2;
  long long res;
  if (b <= mid)
    res = ask2(k << 1, a, b);
  else if (a > mid)
    res = ask2(k << 1 | 1, a, b);
  else
    res = (ask2(k << 1, a, mid) + ask2(k << 1 | 1, mid + 1, b)) % mod;
  update(k);
  return res;
}
int main() {
  pos = 1;
  scanf("%d %d", &v[1], &m);
  for (int i = 1; i <= m; i++) {
    int op;
    scanf("%d", &op);
    a[i].op = op;
    if (op == 1) {
      int x;
      pos++;
      scanf("%d %d", &x, &v[pos]);
      f[x].push_back(pos);
      a[i].x = x, a[i].u = v[pos];
    } else {
      int x;
      scanf("%d", &x);
      a[i].u = x;
    }
  }
  sz[1] = 1;
  dfs(1, 0);
  build(1, 1, pos);
  pos = 1;
  for (int i = 1; i <= m; i++) {
    if (a[i].op == 1) {
      pos++;
      change(1, cx[pos], v[pos]);
      long long tmp =
          (long long)(sz[a[i].x] + 1) * pow_mod(sz[a[i].x], mod - 2) % mod;
      sz[a[i].x]++;
      sz[pos]++;
      change2(1, l[a[i].x], r[a[i].x], tmp);
    } else {
      long long tmp = ask(1, cx[a[i].u]) * ask2(1, l[a[i].u], r[a[i].u]) % mod;
      tmp = tmp * (long long)sz[a[i].u] % mod;
      cout << tmp << endl;
    }
  }
  return 0;
}
