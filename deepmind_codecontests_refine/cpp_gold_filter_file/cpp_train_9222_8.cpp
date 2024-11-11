#include <bits/stdc++.h>
using namespace std;
const int N = 200000, mod = 1000000007;
int add(int a, int b, int p = mod) { return a + b >= p ? a + b - p : a + b; }
int sub(int a, int b, int p = mod) { return a - b < 0 ? a - b + p : a - b; }
int mul(int a, int b, int p = mod) { return 1LL * a * b % p; }
void sadd(int &a, int b, int p = mod) { a = add(a, b, p); }
void ssub(int &a, int b, int p = mod) { a = sub(a, b, p); }
void smul(int &a, int b, int p = mod) { a = mul(a, b, p); }
int Power(int a, int k, int p = mod) {
  int res = 1;
  for (; k; k >>= 1, smul(a, a, p))
    if (k & 1) smul(res, a, p);
  return res;
}
int Get_inv(int a, int p = mod) { return Power(a, p - 2, p); }
int n, p[N + 9];
struct side {
  int y, next;
} e[N * 3 + 9];
int lin[2][N + 9], cs;
void Ins(int id, int x, int y) {
  e[++cs].y = y;
  e[cs].next = lin[id][x];
  lin[id][x] = cs;
}
void Ins2(int id, int x, int y) {
  Ins(id, x, y);
  Ins(id, y, x);
}
void into() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    p[x] = i;
  }
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    Ins2(0, x, y);
  }
}
int b[N + 9], pr[N + 9], cp;
int inv[N + 9], phi[N + 9], mu[N + 9], f[N + 9];
void Sieve() {
  inv[1] = phi[1] = mu[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = mul(mod - mod / i, inv[mod % i]);
    if (!b[i]) pr[++cp] = i, phi[i] = i - 1, mu[i] = -1;
    for (int j = 1; j <= cp && i * pr[j] <= n; ++j) {
      int t = i * pr[j];
      b[t] = 1;
      if (i % pr[j] == 0) {
        phi[t] = phi[i] * pr[j];
        mu[t] = 0;
        break;
      }
      phi[t] = phi[i] * (pr[j] - 1);
      mu[t] = -mu[i];
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!mu[i]) continue;
    for (int j = 1; i * j <= n; ++j) {
      int t = mul(j, inv[phi[j]]);
      mu[i] == 1 ? sadd(f[i * j], t) : ssub(f[i * j], t);
    }
  }
}
int fa[N + 9], son[N + 9], dep[N + 9], siz[N + 9], top[N + 9];
int dfs[N + 9], co;
void Dfs_ord0(int k, int fat) {
  fa[k] = fat;
  dep[k] = dep[fat] + 1;
  siz[k] = 1;
  for (int i = lin[0][k]; i; i = e[i].next)
    if (e[i].y ^ fat) {
      Dfs_ord0(e[i].y, k);
      siz[k] += siz[e[i].y];
      if (siz[e[i].y] > siz[son[k]]) son[k] = e[i].y;
    }
}
void Dfs_ord1(int k, int t) {
  top[k] = t;
  dfs[k] = ++co;
  if (son[k]) Dfs_ord1(son[k], t);
  for (int i = lin[0][k]; i; i = e[i].next)
    if (e[i].y ^ fa[k] && e[i].y ^ son[k]) Dfs_ord1(e[i].y, e[i].y);
}
int Query_lca(int x, int y) {
  for (; top[x] ^ top[y]; x = fa[top[x]])
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
  return dep[x] < dep[y] ? x : y;
}
int a[N + 9], lca[N + 9], sum[N + 9], ca;
int sta[N + 9], cst;
bool cmp(const int &a, const int &b) { return dfs[a] < dfs[b]; }
void Build(int d) {
  sta[cst = 1] = a[ca = 0] = 1;
  for (int i = d; i <= n; i += d) a[++ca] = p[i];
  sort(a + 1, a + ca + 1, cmp);
  for (int i = 1; i <= ca; ++i) {
    lca[i] = Query_lca(a[i], a[i - 1]);
    lin[1][a[i]] = lin[1][lca[i]] = sum[lca[i]] = 0;
  }
  for (int i = d; i <= n; i += d) sum[p[i]] = phi[i];
  for (int i = 1; i <= ca; ++i) {
    for (; cst > 1 && dep[lca[i]] < dep[sta[cst - 1]]; --cst)
      Ins(1, sta[cst - 1], sta[cst]);
    if (lca[i] ^ sta[cst]) {
      Ins(1, lca[i], sta[cst]);
      if (lca[i] ^ sta[--cst]) sta[++cst] = lca[i];
    }
    if (a[i] ^ sta[cst]) sta[++cst] = a[i];
  }
  for (; cst > 1; --cst) Ins(1, sta[cst - 1], sta[cst]);
}
void Dfs_sum(int k) {
  for (int i = lin[1][k]; i; i = e[i].next) {
    Dfs_sum(e[i].y);
    sadd(sum[k], sum[e[i].y]);
  }
}
int ans;
int Dfs_ans(int k) {
  int res = 0;
  for (int i = lin[1][k]; i; i = e[i].next) {
    sadd(res, Dfs_ans(e[i].y));
    sadd(res,
         mul(mul(sum[e[i].y], sub(sum[1], sum[e[i].y])), dep[e[i].y] - dep[k]));
  }
  return res;
}
void Get_ans() {
  int last = cs;
  for (int i = 1; i <= n; ++i) {
    cs = last;
    Build(i);
    Dfs_sum(1);
    sadd(ans, mul(Dfs_ans(1), f[i]));
  }
}
void work() {
  Sieve();
  Dfs_ord0(1, 0);
  Dfs_ord1(1, 1);
  Get_ans();
}
void outo() { printf("%d\n", mul(ans, Get_inv(1LL * n * (n - 1) / 2 % mod))); }
int main() {
  into();
  work();
  outo();
  return 0;
}
