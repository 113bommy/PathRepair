#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100, MOD = 1000 * 1000 * 1000 + 7;
int sum(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
void _sum(int &a, int b) { a = sum(a, b); }
int mul(int a, int b) { return 1LL * a * b % MOD; }
void _mul(int &a, int b) { a = mul(a, b); }
int power(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) _mul(res, a);
    _mul(a, a);
    b >>= 1;
  }
  return res;
}
int inv(int x) { return power(x, MOD - 2); }
int q, n, T, d[N], type[N], par[N], v[N], val[N], l[N], r[N];
vector<int> child[N];
struct node {
  int sum, lazy;
  node() { lazy = 1; }
  void MUL(int x) {
    _mul(lazy, x);
    _mul(sum, x);
  }
};
struct segment {
  node seg[N << 2];
  void updc(int v, int lc, int rc) {
    seg[lc].MUL(seg[v].lazy);
    seg[rc].MUL(seg[v].lazy);
    seg[v].lazy = 1;
  }
  int get(int l, int r, int v = 1, int s = 0, int e = N) {
    if (r <= s || e <= l) return 0;
    if (l <= s && e <= r) return seg[v].sum;
    int mid = (s + e) >> 1, lc = v << 1, rc = lc | 1;
    updc(v, lc, rc);
    return sum(get(l, r, lc, s, mid), get(l, r, rc, mid, e));
  }
  void change(int dex, int val, int v = 1, int s = 0, int e = N) {
    if (dex < s || e <= dex) return;
    if (e - s == 1) {
      seg[v].sum = val;
      return;
    }
    int mid = (s + e) >> 1, lc = v << 1, rc = lc | 1;
    updc(v, lc, rc);
    change(dex, val, lc, s, mid);
    change(dex, val, rc, mid, e);
    seg[v].sum = seg[lc].sum + seg[rc].sum;
  }
  void mul(int l, int r, int val, int v = 1, int s = 0, int e = N) {
    if (r <= s || e <= l) return;
    if (l <= s && e <= r) {
      seg[v].MUL(val);
      return;
    }
    int mid = (s + e) >> 1, lc = v << 1, rc = lc | 1;
    updc(v, lc, rc);
    mul(l, r, val, lc, s, mid);
    mul(l, r, val, rc, mid, e);
    seg[v].sum = sum(seg[lc].sum, seg[rc].sum);
  }
} tree;
void dfs(int v = 0) {
  l[v] = T++;
  for (int u : child[v]) dfs(u);
  r[v] = T;
}
void input_ready() {
  cin >> val[0] >> q;
  val[0];
  n++;
  for (int i = 0; i < q; i++) {
    cin >> type[i];
    if (type[i] == 1) {
      cin >> par[n] >> val[n];
      child[--par[n]].push_back(n);
      n++;
    } else {
      cin >> v[i];
      v[i]--;
    }
  }
  dfs();
}
int Z(int v) { return mul(tree.get(l[v], l[v] + 1), inv(val[v])); }
void solve() {
  n = 1;
  tree.change(l[0], val[0]);
  for (int i = 0; i < q; i++)
    if (type[i] == 1) {
      tree.mul(l[par[n]], r[par[n]], mul(inv(d[par[n]] + 1), d[par[n]] + 2));
      tree.change(l[n], mul(val[n], Z(par[n])));
      d[par[n]]++;
      n++;
    } else
      cout << mul(tree.get(l[v[i]], r[v[i]]), inv(v[i] == 0 ? 1 : Z(par[v[i]])))
           << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  input_ready();
  solve();
}
