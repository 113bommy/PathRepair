#include <bits/stdc++.h>
using namespace std;
const int MXN = 4e5 + 30;
const int MAXN = 100;
const long long INF = 1e9 + 7;
const long long BINF = 1e15;
const int mod = 1e9 + 7;
const long double EPS = 1e-6;
const long long dx[] = {0, 0, 1, -1};
const long long dy[] = {1, -1, 0, 0};
const int SZ = 22;
int n;
int a[MXN];
int q;
int l, r;
int t[MXN * 4][2];
int sdfsdfs[MXN];
vector<pair<long long, long long> > g[MXN];
int ans[MXN];
void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v][0] = 1;
    t[v][1] = 1;
    return;
  }
  int tm = (tl + tr) / 2;
  build(v * 2, tl, tm);
  build(v * 2 + 1, tm + 1, tr);
  t[v][0] = t[v * 2][0] * t[v * 2 + 1][0];
  t[v][1] = t[v][0];
}
int get(int v, int tl, int tr, int l, int r, int w) {
  if (tr < l || r < tl) {
    return 1;
  }
  if (l <= tl && tr <= r) {
    return t[v][w];
  }
  int tm = (tl + tr) / 2;
  return (get(v * 2, tl, tm, l, r, w) * 1LL *
          get(v * 2 + 1, tm + 1, tr, l, r, w)) %
         mod;
}
void upd(int v, int tl, int tr, int pos, int val, int w) {
  if (tl == tr) {
    t[v][w] *= val;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm)
    upd(v * 2, tl, tm, pos, val, w);
  else
    upd(v * 2 + 1, tm + 1, tr, pos, val, w);
  t[v][w] = (t[v * 2][w] * 1LL * t[v * 2 + 1][w]) % mod;
}
void upd2(int v, int tl, int tr, int pos, int val, int w) {
  if (tl == tr) {
    t[v][w] /= val;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm)
    upd2(v * 2, tl, tm, pos, val, w);
  else
    upd2(v * 2 + 1, tm + 1, tr, pos, val, w);
  t[v][w] = (t[v * 2][w] * 1LL * t[v * 2 + 1][w]) % mod;
}
int binpow(int a, int n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    int x = binpow(a, n / 2);
    return x * 1LL * x % mod;
  } else {
    return binpow(a, n - 1) * 1LL * a % mod;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> l >> r;
    g[r].push_back(make_pair(l, i));
  }
  for (int r = 1; r <= n; r++) {
    int x = a[r];
    int res = 1, cnt = 1;
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        while (x % i == 0) {
          if ((x / i) % i == 0) res = res * i;
          x /= i;
        }
        cnt *= (i - 1);
        if (sdfsdfs[i]) {
          upd2(1, 1, n, sdfsdfs[i], i - 1, 0);
          upd(1, 1, n, sdfsdfs[i], i, 1);
        }
        sdfsdfs[i] = r;
      }
    }
    if (x != 1) {
      cnt *= (x - 1);
      if (sdfsdfs[x]) {
        upd2(1, 1, n, sdfsdfs[x], x - 1, 0);
        upd(1, 1, n, sdfsdfs[x], x, 1);
      }
      sdfsdfs[x] = r;
    }
    upd(1, 1, n, r, cnt, 0);
    upd(1, 1, n, r, res, 1);
    for (int i = 0; i < g[r].size(); i++) {
      pair<long long, long long> to = g[r][i];
      ans[to.second] =
          (get(1, 1, n, to.first, r, 0) * 1LL * get(1, 1, n, to.first, r, 1)) %
          mod;
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
