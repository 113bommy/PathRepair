#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000000;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
struct m2 {
  m2() {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) x[i][j] = 0;
  };
  long long x[2][2];
};
m2 prod(m2 a, m2 b) {
  m2 c;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      c.x[i][j] = (a.x[i][0] * b.x[0][j] + a.x[i][1] * b.x[1][j]) % mod;
    }
  return c;
}
void mul(m2& a, long long x) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) a.x[i][j] = (a.x[i][j] * x) % mod;
}
m2 sum(m2 a, m2 b) {
  m2 c;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      c.x[i][j] = (a.x[i][j] + b.x[i][j]) % mod;
    }
  return c;
}
vector<m2> fp;
vector<m2> fpinv;
class stree {
 public:
  vector<m2> t;
  int s;
  void build(std::vector<int>& a, int v, int tl, int tr) {
    if (v == 1) {
      t.resize(a.size() * 4);
      s = a.size();
    }
    if (tl == tr) {
      t[v] = fp[tl];
      mul(t[v], a[tl]);
    } else {
      int tm = (tl + tr) / 2;
      build(a, v * 2, tl, tm);
      build(a, v * 2 + 1, tm + 1, tr);
      t[v] = sum(t[v * 2], t[v * 2 + 1]);
    }
  }
  void set(int v, int tl, int tr, int pos, int val) {
    if (pos == tl && tr == pos) {
      t[v] = fp[tl];
      mul(t[v], val);
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        set(v * 2, tl, tm, pos, val);
      else
        set(v * 2 + 1, tm + 1, tr, pos, val);
      t[v] = sum(t[v * 2], t[v * 2 + 1]);
    }
  }
  m2 get(int v, int tl, int tr, int l, int r) {
    if (l > r) return m2();
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    return sum(get(v * 2, tl, tm, l, min(r, tm)),
               get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
};
const int A = 200000;
int main() {
  m2 fib;
  m2 finv;
  finv.x[0][0] = -1;
  finv.x[0][1] = 1;
  finv.x[1][0] = 1;
  finv.x[1][1] = 0;
  fib.x[0][0] = 0;
  fib.x[0][1] = 1;
  fib.x[1][0] = 1;
  fib.x[1][1] = 1;
  fp.resize(2);
  fpinv.resize(2);
  fp[0].x[0][0] = 1;
  fp[0].x[1][1] = 1;
  fp[0].x[0][1] = 0;
  fp[0].x[1][0] = 0;
  fp[1] = fib;
  fpinv[1] = finv;
  fpinv[0] = fp[0];
  m2 cur = fib;
  m2 curi = finv;
  for (int i = 2; i < A + 1; i++) {
    cur = prod(cur, fib);
    curi = prod(curi, finv);
    fp.push_back(cur);
    fpinv.push_back(curi);
  }
  int n, m;
  scanf("%d %d", &n, &m);
  std::vector<int> a(n);
  stree st;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  st.build(a, 1, 0, n - 1);
  for (int i = 0; i < m; i++) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    if (t == 1) {
      st.set(1, 0, n - 1, x - 1, y);
    } else if (t == 2) {
      x--;
      y--;
      m2 res = st.get(1, 0, n - 1, x, y);
      res = prod(res, fpinv[x]);
      long long ans = res.x[0][0] + res.x[1][0];
      printf("%lld\n", ans % mod);
    }
  }
}
