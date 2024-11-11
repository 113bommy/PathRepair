#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MINF = 0x3f3f3f3f;
const int MAXN = 11;
const int MAXQ = 27;
const int MAXSS = (1 << 9) + 7;
const int MAXS = 73;
struct spT {
  bool operator<(const spT &a) const { return p < a.p; }
  int p, w;
} sp[MAXQ];
struct mT {
  mT() { clear(); }
  void clear() { memset(a, MINF, sizeof(a)); }
  void setunit() {
    clear();
    for (int i = 0; i < MAXS; ++i) a[i][i] = 0;
  }
  mT operator*(const mT &x) const {
    mT ans;
    for (int i = 0; i < MAXS; ++i) {
      for (int j = 0; j < MAXS; ++j) {
        for (int k = 0; k < MAXS; ++k) {
          ans.a[i][j] =
              (((ans.a[i][j]) < (a[i][k] + x.a[k][j])) ? (ans.a[i][j])
                                                       : (a[i][k] + x.a[k][j]));
        }
      }
    }
    return ans;
  }
  void operator*=(const mT &x) { (*this) = x * (*this); }
  long long a[MAXS][MAXS];
};
int n, m, q, K;
int c[MAXN];
int id[MAXSS];
int pcnt[MAXSS], pctz[MAXSS];
void init();
void input();
void work();
mT qpow(mT &a, int b) {
  mT base = a, ans;
  ans.setunit();
  while (b) {
    if (b & 1) ans *= base;
    base *= base;
    b >>= 1;
  }
  return ans;
}
int main() {
  init();
  input();
  work();
}
void init() {
  ios::sync_with_stdio(false);
  pcnt[0] = 0;
  for (int i = 1; i < MAXSS; ++i) pcnt[i] = pcnt[i ^ (i & -i)] + 1;
  for (int i = 0; i < 9; ++i) pctz[1 << i] = i;
}
void input() {
  scanf("%d%d%d%d", &m, &n, &K, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
  for (int i = 1; i <= q; ++i) scanf("%d%d", &sp[i].p, &sp[i].w);
}
void work() {
  sort(sp + 1, sp + 1 + q);
  K -= m - 1;
  long long ans = 0;
  while (q && sp[q].p >= K) ans += sp[q].w, --q;
  int ms = (1 << n), kc = 0;
  for (int i = 0; i < ms; ++i) {
    if (pcnt[i] == m) id[i] = ++kc;
  }
  mT bs;
  for (int i = 0; i < ms; ++i) {
    if (id[i]) {
      if (i & 1) {
        for (int j = 0; j < ms; ++j) {
          if (id[j]) {
            int cand = i & (j << 1);
            int xi = i ^ cand, xj = (j << 1) ^ cand;
            if ((xi == (i & -i)) && (xi == 1) && (pcnt[xj] == 1)) {
              bs.a[id[j]][id[i]] = c[pctz[xj]];
            }
          }
        }
      } else {
        bs.a[id[i >> 1]][id[i]] = 0;
      }
    }
  }
  int pre = 0;
  mT cur, ts;
  cur.setunit();
  for (int i = 1; i <= q; ++i) {
    cur *= qpow(bs, sp[i].p - pre - 1);
    ts = bs;
    for (int j = 0; j < ms; ++j) {
      if (id[j]) {
        if (j & 1) {
          for (int k = 0; k < ms; ++k) {
            if (id[k]) {
              int cand = j & (k << 1);
              int xj = j ^ cand, xk = (k << 1) ^ cand;
              if ((xj == (j & -j)) && (xj == 1) && (pcnt[xk] == 1)) {
                ts.a[id[k]][id[j]] += sp[i].w;
              }
            }
          }
        }
      }
    }
    cur *= ts;
    pre = sp[i].p;
  }
  cur *= qpow(bs, K - pre - 1);
  printf("%I64d\n", cur.a[id[(1 << m) - 1]][id[(1 << m) - 1]] + ans);
}
