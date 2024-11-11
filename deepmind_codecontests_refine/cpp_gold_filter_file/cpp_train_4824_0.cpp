#include <bits/stdc++.h>
using namespace std;
const int iinf = 1e9 + 7;
const long long linf = 1ll << 60;
const double dinf = 1e10;
template <typename T>
inline void scf(T &x) {
  bool f = 0;
  x = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (f) x = -x;
  return;
}
template <typename T1, typename T2>
void scf(T1 &x, T2 &y) {
  scf(x);
  return scf(y);
}
template <typename T1, typename T2, typename T3>
void scf(T1 &x, T2 &y, T3 &z) {
  scf(x);
  scf(y);
  return scf(z);
}
template <typename T1, typename T2, typename T3, typename T4>
void scf(T1 &x, T2 &y, T3 &z, T4 &w) {
  scf(x);
  scf(y);
  scf(z);
  return scf(w);
}
const int N = 1e5 + 100;
const int lgN = 18;
int n, lb, rb, ID, rt;
int ls[N], rs[N], dp[N][2], pd[N][2], lc[N], rc[N], lab[N];
vector<int> M;
pair<int, int> pnt[N];
int y[N];
namespace ST {
pair<int, int> st[N][lgN];
int LOG[N], POW[lgN];
void init() {
  for (int i = 0; i < (lgN); i++) POW[i] = 1 << i;
  for (int i = 0; i < (N); i++) {
    while (POW[LOG[i]] < i) LOG[i]++;
    LOG[i]--;
  }
  for (int lg = 0; lg < (lgN - 1); lg++) {
    int len = POW[lg];
    for (int i = (1); i <= (n - len - len + 1); i++)
      st[i][lg + 1] = max(st[i][lg], st[i + len][lg]);
  }
  return;
}
inline int query(const int &l, const int &r) {
  if (l > r) return 0;
  if (l == r) return st[l][0].second;
  int lg = LOG[r - l + 1];
  return max(st[l][lg], st[r - POW[lg] + 1][lg]).second;
}
}  // namespace ST
inline void build_tree(const int &u, const int &l = 1, const int &r = n) {
  int &lc = ls[u] = ST::query(l, pnt[u].first - 1);
  int &rc = rs[u] = ST::query(pnt[u].first + 1, r);
  if (lc) build_tree(ls[u], l, pnt[u].first - 1);
  if (rc) build_tree(rs[u], pnt[u].first + 1, r);
  int ml = max(dp[lc][0], dp[lc][1]);
  int mr = max(dp[rc][0], dp[rc][1]);
  dp[u][0] = ml + mr;
  dp[u][1] = max((lc ? dp[lc][0] + mr : -1), (rc ? dp[rc][0] + ml : -1)) + 1;
  return;
}
void init() {
  static const long long mod = 1e9 + 9ll;
  int k, tot = 0;
  scf(n, k);
  for (int i = (1); i <= (k); i++) {
    int x, y;
    scf(x, y);
    pnt[i] = {x, y};
    M.push_back(x);
  }
  long long a, b, c, d;
  scf(a, b, c, d);
  for (int i = (k + 1); i <= (n); i++) {
    long long x = (long long)pnt[i - 1].first;
    long long y = (long long)pnt[i - 1].second;
    ((x *= a) += b) %= mod;
    ((y *= c) += d) %= mod;
    pnt[i] = {(int)x, (int)y};
    M.push_back(pnt[i].first);
  }
  M.push_back(-1);
  sort(M.begin(), M.end());
  for (int i = (1); i <= (n); i++)
    pnt[i].first = lower_bound(M.begin(), M.end(), pnt[i].first) - M.begin(),
    ST::st[pnt[i].first][0] = {pnt[i].second, i};
  ST::init();
  build_tree(ST::query(1, n));
  return;
}
inline void dfsl(const int &u, const int &lb, const int &rb) {
  lab[u] = ID;
  lc[u] = ST::query(lb, pnt[u].first - 1);
  rc[u] = ST::query(pnt[u].first + 1, rb);
  if (lc[u])
    dfsl(lc[u], lb, pnt[u].first - 1);
  else if (rc[u])
    dfsl(rc[u], pnt[u].first + 1, rb);
  if (u == rt) return;
  int &ls = lc[u], &rs = rc[u];
  bool fl = (lab[ls] == ID);
  bool fr = (lab[rs] == ID);
  int ml = fl ? max(pd[ls][0], pd[ls][1]) : max(dp[ls][0], dp[ls][1]);
  int mr = fr ? max(pd[rs][0], pd[rs][1]) : max(dp[rs][0], dp[rs][1]);
  pd[u][0] = ml + mr;
  pd[u][1] = max((ls ? (fl ? pd[ls][0] : dp[ls][0]) : -1) + mr,
                 (rs ? (fr ? pd[rs][0] : dp[rs][0]) : -1) + ml) +
             1;
  return;
}
inline void dfsr(const int &u, const int &lb, const int &rb) {
  if (!u) return;
  lab[u] = ID;
  lc[u] = ST::query(lb, pnt[u].first - 1);
  rc[u] = ST::query(pnt[u].first + 1, rb);
  if (rc[u])
    dfsr(rc[u], pnt[u].first + 1, rb);
  else if (lc[u])
    dfsr(lc[u], lb, pnt[u].first - 1);
  int &ls = lc[u], &rs = rc[u];
  bool fl = (lab[ls] == ID);
  bool fr = (lab[rs] == ID);
  int ml = fl ? max(pd[ls][0], pd[ls][1]) : max(dp[ls][0], dp[ls][1]);
  int mr = fr ? max(pd[rs][0], pd[rs][1]) : max(dp[rs][0], dp[rs][1]);
  pd[u][0] = ml + mr;
  pd[u][1] = max((ls ? (fl ? pd[ls][0] : dp[ls][0]) : -1) + mr,
                 (rs ? (fr ? pd[rs][0] : dp[rs][0]) : -1) + ml) +
             1;
  return;
}
int main() {
  init();
  int q;
  scf(q);
  while (q--) {
    ++ID;
    scf(lb, rb);
    lb = lower_bound(M.begin(), M.end(), lb) - M.begin();
    rb = lower_bound(M.begin(), M.end(), rb + 1) - M.begin() - 1;
    rt = ST::query(lb, rb);
    dfsl(rt, lb, rb);
    dfsr(rt, lb, rb);
    printf("%d\n", max(pd[rt][0], pd[rt][1]));
  }
  return 0;
}
