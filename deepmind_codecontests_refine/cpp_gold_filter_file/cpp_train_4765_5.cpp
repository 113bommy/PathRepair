#include <bits/stdc++.h>
using namespace std;
static inline void canhazfast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
template <typename T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T extgcd(T a, T b, T &x, T &y) {
  T x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b) {
    T q = a / b;
    a %= b;
    swap(a, b);
    x0 -= q * x1;
    swap(x0, x1);
    y0 -= q * y1;
    swap(y0, y1);
  }
  x = x0;
  y = y0;
  return a;
}
static inline int ctz(unsigned x) { return __builtin_ctz(x); }
static inline int ctzll(unsigned long long x) { return __builtin_ctzll(x); }
static inline int clz(unsigned x) { return __builtin_clz(x); }
static inline int clzll(unsigned long long x) { return __builtin_clzll(x); }
static inline int popcnt(unsigned x) { return __builtin_popcount(x); }
static inline int popcntll(unsigned long long x) {
  return __builtin_popcountll(x);
}
static inline int bsr(unsigned x) { return 31 ^ clz(x); }
static inline int bsrll(unsigned long long x) { return 63 ^ clzll(x); }
struct Mov {
  int i, r, c;
};
int a[5][128];
vector<Mov> ans;
int n, k;
int fi = 0, fj = 0;
int ti, tj;
pair<int, int> nxt(pair<int, int> p) {
  if (p.first == 2)
    return p.second == n ? make_pair(3, n) : make_pair(2, p.second + 1);
  else
    return p.second == 1 ? make_pair(2, 1) : make_pair(3, p.second - 1);
}
int nei(int x) { return ((x - 1) ^ 1) + 1; }
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= 4; ++i) {
    for (int j = 1; j <= n; ++j) scanf("%d", a[i] + j);
  }
  for (int j = 1; j <= n; ++j) {
    if (a[1][j] && a[1][j] == a[2][j]) {
      ans.push_back({a[1][j], 1, j});
      a[2][j] = 0;
      --k;
    }
    if (a[4][j] && a[4][j] == a[3][j]) {
      ans.push_back({a[4][j], 4, j});
      a[3][j] = 0;
      --k;
    }
  }
  for (int j = 1; j <= n && !fi; ++j) {
    if (!a[2][j])
      fi = 2, fj = j;
    else if (!a[3][j])
      fi = 3, fj = j;
  }
  if (!fi) return puts("-1"), 0;
  for (; k; fi = ti, fj = tj) {
    tie(ti, tj) = nxt({fi, fj});
    swap(a[ti][tj], a[fi][fj]);
    if (!a[fi][fj]) continue;
    ans.push_back({a[fi][fj], fi, fj});
    if (a[fi][fj] != a[nei(fi)][fj]) continue;
    ans.push_back({a[fi][fj], nei(fi), fj});
    a[fi][fj] = 0;
    --k;
  }
  printf("%zu\n", ans.size());
  for (const Mov &m : ans) printf("%d %d %d\n", m.i, m.r, m.c);
  return 0;
}
