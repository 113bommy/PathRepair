#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
struct SegmentTree {
  struct Node {
    int sz = 1;
    bool hasCarry = 0;
    U carry = U();
    T val = T();
    Node() {}
    void join(const Node &l, const Node &r) {
      sz = l.sz + r.sz;
      val = l.val + r.val;
    }
    void update(const U &u) {
      carry += u;
      val += u * sz;
      hasCarry = 1;
    }
    void pushDown(Node &l, Node &r) {
      if (!hasCarry) return;
      l.update(carry);
      r.update(carry);
      carry = U();
      hasCarry = 0;
    }
  };
  vector<Node> V;
  int N;
  SegmentTree(int N) : V(4 * N), N(N) {}
  template <class I>
  void create(const vector<I> &VEC, int n = 1, int b = 0, int e = -1) {
    if (e == -1) e = N - 1;
    if (b == e) {
      V[n].val = T(VEC[b]);
    } else {
      int m = (b + e) / 2;
      create(VEC, 2 * n, b, m);
      create(VEC, 2 * n + 1, m + 1, e);
      V[n].join(V[2 * n], V[2 * n + 1]);
    }
  }
  long long query(int i, int j, int n = 1, int b = 0, int e = -1) {
    if (e == -1) e = N - 1;
    if (i <= b && e <= j) {
      return V[n].val.get();
    } else {
      if (V[n].hasCarry) {
        V[2 * n].update(V[n].carry);
        V[2 * n + 1].update(V[n].carry);
        V[n].carry = U();
        V[n].hasCarry = 0;
      }
      int m = (b + e) / 2;
      if (i > m) return query(i, j, 2 * n + 1, m + 1, e);
      if (j <= m) return query(i, j, 2 * n, b, m);
      return query(i, j, 2 * n, b, m) + query(i, j, 2 * n + 1, m + 1, e);
    }
  }
  void update(int i, int j, const U &v, int n = 1, int b = 0, int e = -1) {
    if (e == -1) e = N - 1;
    if (i <= b && e <= j) {
      V[n].update(v);
    } else if (i > e || j < b)
      return;
    else {
      if (V[n].hasCarry) {
        V[2 * n].update(V[n].carry);
        V[2 * n + 1].update(V[n].carry);
        V[n].carry = U();
        V[n].hasCarry = 0;
      }
      int m = (b + e) / 2;
      update(i, j, v, 2 * n, b, m);
      update(i, j, v, 2 * n + 1, m + 1, e);
      V[n].join(V[2 * n], V[2 * n + 1]);
    }
  }
};
struct Replace {
  vector<char> c;
  Replace(int from = 0, int to = 0) : c(10) {
    for (int i = 0; i < 10; ++i) {
      c[i] = i;
    }
    c[from] = to;
  }
  Replace operator*(const int sz) const { return *this; }
  void operator+=(const Replace &a) {
    static vector<char> nc(10);
    fill(nc.begin(), nc.end(), 0);
    for (int i = 0; i < 10; ++i) {
      nc[i] = a.c[c[i]];
    }
    copy(nc.begin(), nc.end(), c.begin());
  }
};
struct DigitSum {
  vector<long long> d;
  DigitSum(int v = 0) : d(10) {
    int p = 1;
    while (v > 0) {
      d[v % 10] += p;
      v /= 10;
      p *= 10;
    }
  }
  DigitSum operator+(const DigitSum &a) const {
    DigitSum r;
    for (int i = 0; i < 10; ++i) {
      r.d[i] = d[i] + a.d[i];
    }
    return r;
  }
  void operator+=(const Replace &a) {
    static vector<long long> nd(10);
    fill(nd.begin(), nd.end(), 0);
    for (int i = 0; i < 10; ++i) {
      nd[a.c[i]] += d[i];
    }
    copy(nd.begin(), nd.end(), d.begin());
  }
  long long get() const {
    long long r = 0;
    for (int i = 0; i < 10; ++i) {
      r += i * d[i];
    }
    return r;
  }
};
int a[100010];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  SegmentTree<DigitSum, Replace> ST(n);
  ST.create(vector<int>(a, a + n));
  vector<long long> A;
  A.reserve(q);
  while (q--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    l--, r--;
    if (op == 1) {
      int u, v;
      scanf("%d%d", &u, &v);
      Replace up(u, v);
      ST.update(l, r, up);
    } else {
      printf("%I64d\n", ST.query(l, r));
    }
  }
}
