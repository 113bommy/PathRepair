#include <bits/stdc++.h>
using namespace std;
const int MAX_Q = 100000;
const int MAX_M = MAX_Q + 2;
enum { REQ, ARV, LV };
struct Opr {
  int o, a, b;
  Opr() {}
};
template <typename T, const int MAX_N>
struct BIT {
  int n;
  T bits[MAX_N + 1];
  BIT() {}
  void init(int _n) {
    n = _n;
    memset(bits, 0, sizeof(bits));
  }
  T sum(int x) {
    T s = 0;
    while (x > 0) {
      s += bits[x];
      x -= (x & -x);
    }
    return s;
  }
  void add(int x, T v) {
    while (x <= n) {
      bits[x] += v;
      x += (x & -x);
    }
  }
};
template <typename T, const int MAX_NY, const int MAX_NX>
struct BIT2D {
  int n;
  BIT<T, MAX_NX> bits[MAX_NY + 1];
  BIT2D() {}
  BIT2D(int _ny, int _nx) { init(_ny, _nx); }
  void init(int _ny, int _nx) {
    n = _ny;
    for (int y = 1; y <= n; y++) bits[y].init(_nx);
  }
  T sum(int y, int x) {
    T s = 0;
    while (y > 0) {
      s += bits[y].sum(x);
      y -= (y & -y);
    }
    return s;
  }
  void add(int y, int x, T v) {
    while (y <= n) {
      bits[y].add(x, v);
      y += (y & -y);
    }
  }
};
map<int, int> pmap;
set<pair<int, int> > rset, wset;
Opr ops[MAX_Q];
int xs[MAX_M];
BIT<int, MAX_M> bit;
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  rset.insert(pair<int, int>(0, n));
  wset.insert(pair<int, int>(n, 0));
  xs[0] = 0, xs[1] = n;
  int m = 2;
  for (int i = 0; i < q; i++) {
    Opr &opi = ops[i];
    int cmd;
    scanf("%d", &cmd);
    if (cmd != REQ) {
      map<int, int>::iterator mit = pmap.find(cmd);
      if (mit == pmap.end()) {
        set<pair<int, int> >::iterator wit = wset.end();
        wit--;
        int a = wit->second, b = a + wit->first;
        rset.erase(pair<int, int>(a, b));
        wset.erase(wit);
        int c0 = (a + b) / 2, c1 = c0 + 1;
        rset.insert(pair<int, int>(a, c0));
        rset.insert(pair<int, int>(c1, b));
        wset.insert(pair<int, int>(c0 - a, a));
        wset.insert(pair<int, int>(b - c1, c1));
        pmap[cmd] = c0;
        xs[m++] = c0;
        opi.o = ARV, opi.a = c0;
      } else {
        int c = mit->second;
        pmap.erase(mit);
        opi.o = LV, opi.a = c;
        set<pair<int, int> >::iterator rit0 =
            rset.lower_bound(pair<int, int>(c + 1, c + 1));
        set<pair<int, int> >::iterator rit1 = rit0--;
        int a = rit0->first, b = rit1->second;
        set<pair<int, int> >::iterator wit0 =
            wset.find(pair<int, int>(rit0->second - a, a));
        set<pair<int, int> >::iterator wit1 =
            wset.find(pair<int, int>(b - rit1->first, rit1->first));
        rset.erase(rit0);
        rset.erase(rit1);
        rset.insert(pair<int, int>(a, b));
        wset.erase(wit0);
        wset.erase(wit1);
        wset.insert(pair<int, int>(b - a, a));
      }
    } else {
      opi.o = REQ;
      scanf("%d%d", &opi.a, &opi.b);
      opi.a--;
    }
  }
  sort(xs, xs + m);
  m = unique(xs, xs + m) - xs;
  bit.init(m);
  for (int i = 0; i < q; i++) {
    Opr &opi = ops[i];
    if (opi.o == REQ) {
      int j0 = lower_bound(xs, xs + m, opi.a) - xs;
      int j1 = lower_bound(xs, xs + m, opi.b) - xs;
      printf("%d\n", bit.sum(j1) - bit.sum(j0));
    } else if (opi.o == ARV) {
      int j = lower_bound(xs, xs + m, opi.a) - xs;
      bit.add(j + 1, 1);
    } else {
      int j = lower_bound(xs, xs + m, opi.a) - xs;
      bit.add(j + 1, -1);
    }
  }
  return 0;
}
