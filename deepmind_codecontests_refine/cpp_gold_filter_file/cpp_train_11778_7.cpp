#include <bits/stdc++.h>
using namespace std;
const int N = 200007;
const int INFINITE = 1000000007;
struct Point {
  int k;
  vector<int> x;
  Point() {}
  Point(int k) : k(k) { x.resize(k); }
  Point(int k, vector<int> x) : k(k), x(x) {}
  int get(int mask) {
    int part = 0;
    for (int i = 0; i < (k); ++i) part += (mask & (1 << i) ? -1 : 1) * x[i];
    return part;
  }
};
int n, K;
Point a[N];
struct SegmentTree {
  int mask;
  vector<int> T;
  vector<int> Left, Right, Leaf;
  void init(int _n, int _mask) {
    n = _n, mask = _mask;
    T.resize(n * 4 + 1);
    Left.resize(n * 4 + 1);
    Right.resize(n * 4 + 1);
    Leaf.resize(n + 1);
  }
  void build(int p, int l, int r) {
    Left[p] = l, Right[p] = r;
    if (l == r) {
      T[p] = a[l].get(mask);
      Leaf[l] = p;
      return;
    }
    int mid = (l + r) >> 1;
    build((p << 1), l, mid);
    build((p << 1) | 1, mid + 1, r);
    T[p] = max(T[(p << 1)], T[(p << 1) | 1]);
  }
  int get(int p, int l, int r) {
    int L = Left[p], R = Right[p];
    if (l <= L && R <= r) return T[p];
    if (R < l || r < L) return -INFINITE;
    return max(get((p << 1), l, r), get((p << 1) | 1, l, r));
  }
  void update(int pos, vector<int> x) {
    int p = Leaf[pos];
    Point akari(K, x);
    T[p] = akari.get(mask);
    while (p > 1) {
      p /= 2;
      T[p] = max(T[(p << 1)], T[(p << 1) | 1]);
    }
  }
};
SegmentTree T[1 << 5];
void Read() {
  cin >> n >> K;
  for (int i = (1); i <= (n); ++i) {
    vector<int> x(K);
    for (auto &X : x) cin >> X;
    a[i] = Point(K, x);
  }
}
void Init() {
  for (int mask = 0; mask < ((1 << K)); ++mask) {
    T[mask].init(n, mask);
    T[mask].build(1, 1, n);
  }
}
void Solve() {
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int pos;
      cin >> pos;
      for (auto &X : a[pos].x) cin >> X;
      for (int mask = 0; mask < ((1 << K)); ++mask)
        T[mask].update(pos, a[pos].x);
    } else {
      int l, r;
      cin >> l >> r;
      int res = -INFINITE;
      for (int mask = 0; mask < ((1 << K)); ++mask) {
        res = max(res,
                  T[mask].get(1, l, r) + T[(1 << K) - mask - 1].get(1, l, r));
      }
      cout << res << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  Read();
  Init();
  Solve();
  return 0;
}
