#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
struct SegmentTree {
  struct Node {
    bool hasCarry = 0;
    int b = 0, e = 0;
    U carry = U();
    T val = T();
    Node() {}
    void join(const Node &l, const Node &r) {
      val = l.val + r.val;
      b = l.b;
      e = r.e;
    }
    void update(const U &u) {
      carry += u;
      u.update(val, b, e);
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
      V[n].val = T(VEC[b]), V[n].b = b, V[n].e = e;
    } else {
      int m = (b + e) / 2;
      create(VEC, 2 * n, b, m);
      create(VEC, 2 * n + 1, m + 1, e);
      V[n].join(V[2 * n], V[2 * n + 1]);
    }
  }
  T query(int i, int j, int n = 1, int b = 0, int e = -1) {
    if (e == -1) e = N - 1;
    if (i <= b && e <= j)
      return V[n].val;
    else {
      V[n].pushDown(V[2 * n], V[2 * n + 1]);
      int m = (b + e) / 2;
      if (i > m) return query(i, j, 2 * n + 1, m + 1, e);
      if (j <= m) return query(i, j, 2 * n, b, m);
      return query(i, j, 2 * n, b, m) + query(i, j, 2 * n + 1, m + 1, e);
    }
  }
  void update(int i, int j, const U &v, int n = 1, int b = 0, int e = -1) {
    if (e == -1) e = N - 1;
    if (i <= b && e <= j)
      V[n].update(v);
    else if (i > e || j < b)
      return;
    else {
      V[n].pushDown(V[2 * n], V[2 * n + 1]);
      int m = (b + e) / 2;
      update(i, j, v, 2 * n, b, m);
      update(i, j, v, 2 * n + 1, m + 1, e);
      V[n].join(V[2 * n], V[2 * n + 1]);
    }
  }
  int findOkPrefix(int i, const function<bool(T)> &isOk) {
    vector<int> stk;
    stk.reserve(20);
    stk.push_back(1);
    T acum;
    int sz = 0;
    while (stk.size()) {
      int t = stk.back();
      stk.pop_back();
      Node &n = V[t];
      if (n.e < i) continue;
      T newAcum = sz == 0 ? n.val : (acum + n.val);
      if (i <= n.b) {
        if (isOk(newAcum)) {
          sz += n.e - n.b + 1;
          acum = newAcum;
        } else {
          if (n.b == n.e) return sz;
          V[t].pushDown(V[t << 1], V[t << 1 | 1]);
          stk.push_back(2 * t + 1);
          stk.push_back(2 * t);
        }
      } else {
        V[t].pushDown(V[t << 1], V[t << 1 | 1]);
        stk.push_back(2 * t + 1);
        stk.push_back(2 * t);
      }
    }
  }
};
struct RRange {
  int tL, tR, sz;
  RRange(int v = 0) : tR(v), tL(v), sz(1) {}
  RRange operator+(const RRange &m) const {
    RRange r;
    r.sz = sz + m.sz;
    r.tL = max(tL, m.tL - sz);
    r.tR = max(tR - m.sz, m.tR);
    return r;
  }
  friend ostream &operator<<(ostream &os, const RRange &range) {
    os << "(" << range.tL << "," << range.tR << ")";
    return os;
  }
  void normalize(int N) {
    if (tL + tR + 1 >= N) {
      tL = 0;
      tR = N - 1;
    }
    sz = 1;
  }
  int size() { return tL + tR + 1; }
};
struct Void {
  void update(RRange &m, int b, int e) const {}
  void operator+=(const Void &s) {}
};
int main() {
  int N;
  cin >> N;
  vector<RRange> V(N);
  for (int i = 0; i < N; ++i) {
    int n;
    cin >> n;
    V[i] = RRange(n);
    V[i].normalize(N);
  }
  vector<vector<RRange>> T(20, vector<RRange>(N));
  vector<SegmentTree<RRange, Void>> STS;
  T[0] = V;
  auto fn = [](int i, int j, SegmentTree<RRange, Void> &ST, int N) {
    RRange r = ST.query(max(i, 0), min(j, N - 1));
    if (i < 0) r = ST.query(N + i, N - 1) + r;
    if (j >= N) r = r + ST.query(0, j % N);
    return r;
  };
  for (int i = 1; i < 20; ++i) {
    STS.push_back(SegmentTree<RRange, Void>(N));
    STS.back().create(T[i - 1]);
    auto &ST = STS.back();
    for (int j = 0; j < N; ++j) {
      T[i][j] = fn(j - T[i - 1][j].tL, j + T[i - 1][j].tR, ST, N);
      T[i][j].tL += T[i - 1][j].tL;
      T[i][j].tR += T[i - 1][j].tR;
      T[i][j].normalize(N);
    }
  }
  for (int i = 0; i < N; ++i) {
    RRange mx(0);
    int ans = 0;
    for (int j = STS.size() - 1; j >= 0; --j) {
      RRange t = fn(i - mx.tL, i + mx.tR, STS[j], N);
      t.tL += mx.tL;
      t.tR += mx.tR;
      t.normalize(N);
      if (t.size() < N) {
        mx = t;
        ans |= 1 << j;
      }
    }
    if (mx.size() < N) ans++;
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}
