#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q, mod, a[N], all;
map<int, int> id;
void add(int& x, int y) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
}
void sub(int& x, int y) {
  x -= y;
  if (x < 0) {
    x += mod;
  }
}
int mul(int x, int y) { return (long long)x * y % mod; }
int qpow(int v, int p) {
  int result = 1;
  for (; p; p >>= 1, v = mul(v, v)) {
    if (p & 1) {
      result = mul(result, v);
    }
  }
  return result;
}
inline void exgcd(int a, int b, int& d, int& x, int& y) {
  if (!b) {
    d = a, x = 1, y = 0;
  } else {
    exgcd(b, a % b, d, y, x), y -= x * (a / b);
  }
}
int inv(int v) {
  int d, x, y;
  exgcd(v, mod, d, x, y);
  return (x % mod + mod) % mod;
}
struct seg_tree {
  int sumv[N << 2], mulv[N << 2], addv[N << 2];
  bool opt;
  void tmul(int o, int v) {
    sumv[o] = mul(sumv[o], v);
    mulv[o] = mul(mulv[o], v);
  }
  void build(int l, int r, int o) {
    if (opt) {
      mulv[o] = 1;
    }
    if (l == r) {
      sumv[o] = a[l] % mod;
    } else {
      int mid = l + r >> 1;
      build(l, mid, o << 1);
      build(mid + 1, r, o << 1 | 1);
      sumv[o] = (sumv[o << 1] + sumv[o << 1 | 1]) % mod;
    }
  }
  void push_down(int o) {
    if (opt) {
      if (mulv[o] != 1) {
        tmul(o << 1, mulv[o]);
        tmul(o << 1 | 1, mulv[o]);
        mulv[o] = 1;
      }
    } else {
      if (addv[o]) {
        addv[o << 1] += addv[o];
        addv[o << 1 | 1] += addv[o];
        addv[o] = 0;
      }
    }
  }
  void modify(int l, int r, int o, int ql, int qr, int v) {
    if (ql <= l && r <= qr) {
      return opt ? tmul(o, v) : (void)(addv[o] += v);
    } else {
      int mid = l + r >> 1;
      push_down(o);
      if (qr <= mid) {
        modify(l, mid, o << 1, ql, qr, v);
      } else if (ql > mid) {
        modify(mid + 1, r, o << 1 | 1, ql, qr, v);
      } else {
        modify(l, mid, o << 1, ql, qr, v);
        modify(mid + 1, r, o << 1 | 1, ql, qr, v);
      }
      sumv[o] = (sumv[o << 1] + sumv[o << 1 | 1]) % mod;
    }
  }
  void modify(int l, int r, int o, int p, int v) {
    if (l == r) {
      sumv[o] = v;
    } else {
      int mid = l + r >> 1;
      push_down(o);
      if (p <= mid) {
        modify(l, mid, o << 1, p, v);
      } else {
        modify(mid + 1, r, o << 1 | 1, p, v);
      }
      sumv[o] = (sumv[o << 1] + sumv[o << 1 | 1]) % mod;
    }
  }
  int query(int l, int r, int o, int ql, int qr) {
    if (ql <= l && r <= qr) {
      return sumv[o];
    } else {
      int mid = l + r >> 1;
      push_down(o);
      if (qr <= mid) {
        return query(l, mid, o << 1, ql, qr);
      } else if (ql > mid) {
        return query(mid + 1, r, o << 1 | 1, ql, qr);
      } else {
        return (query(l, mid, o << 1, ql, qr) +
                query(mid + 1, r, o << 1 | 1, ql, qr)) %
               mod;
      }
    }
  }
  int query(int l, int r, int o, int p) {
    if (l == r) {
      return addv[o];
    } else {
      int mid = l + r >> 1;
      push_down(o);
      if (p <= mid) {
        return query(l, mid, o << 1, p);
      } else {
        return query(mid + 1, r, o << 1 | 1, p);
      }
    }
  }
} trees[12];
int main() {
  scanf("%d%d", &n, &mod);
  int t = mod;
  for (int i = 2; i * i <= t; ++i) {
    if (t % i == 0) {
      id[i] = ++all;
      for (; t % i == 0; t /= i)
        ;
    }
  }
  if (t != 1) {
    id[t] = ++all;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  trees[0].opt = true;
  trees[0].build(1, n, 1);
  for (int i = 1; i <= n; ++i) {
    for (auto v : id) {
      if (a[i] % v.first == 0) {
        int t = 0;
        for (; a[i] % v.first == 0; a[i] /= v.first, ++t)
          ;
        trees[v.second].modify(1, n, 1, i, i, t);
      }
    }
  }
  trees[all + 1].opt = true;
  trees[all + 1].build(1, n, 1);
  scanf("%d", &q);
  while (q--) {
    int opt, l, r, p, x, d;
    scanf("%d", &opt);
    switch (opt) {
      case 1:
        scanf("%d%d%d", &l, &r, &x);
        d = x;
        for (auto v : id) {
          if (d % v.first == 0) {
            int t = 0;
            for (; d % v.first == 0; d /= v.first, ++t)
              ;
            trees[v.second].modify(1, n, 1, l, r, t);
          }
        }
        trees[all + 1].modify(1, n, 1, l, r, d);
        trees[0].modify(1, n, 1, l, r, x);
        break;
      case 2:
        scanf("%d%d", &p, &x);
        d = 1;
        for (auto v : id) {
          if (x % v.first == 0) {
            int t = 0;
            for (; x % v.first == 0; x /= v.first, ++t)
              ;
            trees[v.second].modify(1, n, 1, p, p, -t);
          }
          d = mul(d, qpow(v.first, trees[v.second].query(1, n, 1, p)));
        }
        x = inv(x);
        d = mul(d, mul(trees[all + 1].query(1, n, 1, p, p), x));
        trees[all + 1].modify(1, n, 1, p, p, x);
        trees[0].modify(1, n, 1, p, d);
        break;
      case 3:
        scanf("%d%d", &l, &r);
        printf("%d\n", trees[0].query(1, n, 1, l, r));
        break;
    }
  }
  return 0;
}
