#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 4010;
const int mod = 1e9 + 7;
int n, k, l, x[N], y[N], z[N];
int nx, ny, cx[N], cy[N], py[N], le[N], ri[N];
int mul(int x, int y) { return 1LL * x * y % mod; }
map<int, int> M;
vector<int> v[N];
set<int> S[N];
long long ss, ans;
int a[N], t[N], w[N], fl[N], fr[N];
void push_down(int l, int r, int rt) {
  if (w[rt] >= 0) {
    int mid = l + r >> 1;
    w[rt << 1] = w[rt], w[rt << 1 | 1] = w[rt];
    fl[rt << 1] = w[rt], fr[rt << 1] = w[rt];
    fl[rt << 1 | 1] = w[rt], fr[rt << 1 | 1] = w[rt];
    t[rt << 1] = 1LL * w[rt] * (py[mid] - py[l - 1]) % mod;
    t[rt << 1 | 1] = 1LL * w[rt] * (py[r] - py[mid]) % mod;
    w[rt] = -1;
  }
}
void build(int l, int r, int rt) {
  w[rt] = -1;
  fl[rt] = a[l], fr[rt] = a[r];
  if (l == r) {
    t[rt] = 1LL * a[l] * cy[l] % mod;
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  t[rt] = t[rt << 1] + t[rt << 1 | 1];
  if (t[rt] >= mod) t[rt] -= mod;
}
void modify(int l, int r, int rt, int L, int v) {
  if (r < L || fl[rt] <= v) return;
  if (L <= l && v <= fr[rt]) {
    w[rt] = v;
    fl[rt] = v;
    fr[rt] = v;
    t[rt] = 1LL * v * (py[r] - py[l - 1]) % mod;
    return;
  }
  int mid = l + r >> 1;
  push_down(l, r, rt);
  modify(l, mid, rt << 1, L, v);
  modify(mid + 1, r, rt << 1 | 1, L, v);
  fl[rt] = fl[rt << 1];
  fr[rt] = fr[rt << 1 | 1];
  t[rt] = t[rt << 1] + t[rt << 1 | 1];
  if (t[rt] >= mod) t[rt] -= mod;
}
int main() {
  n = read();
  k = read();
  l = read();
  for (int i = 1; i <= n; i++) x[i] = read(), y[i] = read(), z[i] = read();
  M[-1] = 1;
  M[l] = 1;
  for (int i = 1; i <= n; i++) M[x[i]] = 1;
  nx = -1;
  for (map<int, int>::iterator it = M.begin(); it != M.end(); it++)
    (*it).second = ++nx, cx[nx] = (*it).first;
  for (int i = 1; i <= n; i++) x[i] = M[x[i]];
  M.clear();
  for (int i = nx; i >= 1; i--) cx[i] -= cx[i - 1];
  M[-1] = 1, M[l] = 1;
  for (int i = 1; i <= n; i++) M[y[i]] = 1;
  ny = -1;
  for (map<int, int>::iterator it = M.begin(); it != M.end(); it++)
    (*it).second = ++ny, py[ny] = (*it).first;
  for (int i = 1; i <= ny; i++) cy[i] = py[i] - py[i - 1];
  for (int i = 1; i <= n; i++) y[i] = M[y[i]];
  M.clear();
  for (int i = 1; i <= n; i++) v[x[i]].push_back(i);
  for (int j = 1; j <= nx; j++) {
    ss = 0;
    for (int i = 1; i <= k; i++) S[i].clear(), S[i].insert(0), S[i].insert(ny);
    for (int i = j; i <= nx - 1; i++)
      for (int p = 0; p < ((v[i]).size()); p++) {
        int e = v[i][p];
        auto it1 = S[z[e]].lower_bound(y[e]);
        if ((*it1) == y[e])
          le[e] = -1, ri[e] = -1;
        else
          ri[e] = (*it1), it1--, le[e] = (*it1);
        S[z[e]].insert(y[e]);
      }
    for (int i = 1; i <= ny - 1; i++) a[i] = 0;
    for (int i = 1; i <= k; i++) {
      int o = 0;
      for (auto it1 : S[i]) {
        if (it1 == 0) continue;
        a[o + 1] = max(a[o + 1], it1);
        o = it1;
      }
    }
    for (int i = 2; i <= ny - 1; i++) a[i] = max(a[i], a[i - 1]);
    for (int i = 1; i <= ny - 1; i++) a[i] = l - py[a[i]];
    build(1, ny - 1, 1);
    for (int i = nx; i > j;) {
      ss += 1LL * t[1] * cx[i] % mod;
      ss %= mod;
      i--;
      for (int o = v[i].size(); o--;) {
        int e = v[i][o];
        if (le[e] != -1) modify(1, ny - 1, 1, le[e] + 1, l - py[ri[e]]);
      }
    }
    ans += 1LL * ss * cx[j] % mod;
    ans %= mod;
  }
  printf("%d\n", ans);
  return 0;
}
