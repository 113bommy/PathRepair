#include <bits/stdc++.h>
using std::map;
using std::pair;
using std::vector;
const double eps = 1e-8;
const double INF = 1e20;
const double PI = acos(-1.);
const int MXN = 50;
const long long MOD = 1000000007;
const int N = 100011;
int a[N], n;
int query[N * 3];
long long ans[N];
map<int, int> Q;
inline void swap(int &a, int &b) {
  int t = b;
  b = a;
  a = t;
}
int gcd(int a, int b) {
  while (1) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    swap(a, b);
    b = b % a;
  }
}
class SegmentTree {
 public:
  struct Value {
    int v;
    Value(int v = 1) : v(v) {}
  };
  struct node {
    Value val;
  } pl[N * 4];
  int allz, ally;

 private:
  void update(Value &root, Value &A, Value &B) { root.v = gcd(A.v, B.v); }
  void build(int p, int pz, int py) {
    pl[p].val.v = a[pz];
    if (pz == py) return;
    int mid = (pz + py) >> 1;
    build(p << 1, pz, mid);
    build(p << 1 | 1, mid + 1, py);
    update(pl[p].val, pl[p << 1].val, pl[p << 1 | 1].val);
  }
  Value query(int p, int pz, int py, int zz, int yy) {
    int mid = (pz + py) >> 1;
    if (pz == zz && py == yy) return pl[p].val;
    if (yy <= mid)
      return query(p << 1, pz, mid, zz, yy);
    else if (mid < zz)
      return query(p << 1 | 1, mid + 1, py, zz, yy);
    else {
      Value A = query(p << 1, pz, mid, zz, mid);
      Value B = query(p << 1 | 1, mid + 1, py, mid + 1, yy);
      Value ret;
      update(ret, A, B);
      return ret;
    }
  }
  void split(int p, int pz, int py, int lmt,
             vector<pair<pair<int, int>, int> > &L) {
    int mid = (pz + py) >> 1;
    if (pz >= lmt) {
      L.push_back(std::make_pair(std::make_pair(pz, py), p));
      return;
    }
    if (lmt <= mid) {
      split(p << 1, pz, mid, lmt, L);
      L.push_back(std::make_pair(std::make_pair(mid + 1, py), p << 1 | 1));
    } else
      split(p << 1 | 1, mid + 1, py, lmt, L);
  }
  int biquery(int p, int pz, int py, int pre) {
    int mid = (pz + py) >> 1;
    if (pz == py) {
      if (gcd(pl[p].val.v, pre) == pre)
        return py;
      else
        return pz - 1;
    }
    if (gcd(pl[p << 1].val.v, pre) == pre)
      return biquery(p << 1 | 1, mid + 1, py, pre);
    else
      return biquery(p << 1, pz, mid, pre);
  }

 public:
  void init(int leftmost, int rightmost) {
    allz = leftmost;
    ally = rightmost;
    build(1, allz, ally);
  }
  Value query(int zz, int yy) { return query(1, allz, ally, zz, yy); }
  int biquery(int ll, int pre) {
    int i, p;
    vector<pair<pair<int, int>, int> > L;
    L.clear();
    split(1, allz, ally, ll, L);
    for (i = 0; i < L.size(); i++)
      if (gcd(pl[L[i].second].val.v, pre) < pre) break;
    if (i == L.size()) return n;
    return biquery(L[i].second, L[i].first.first, L[i].first.second, pre);
  }
} ST;
int main() {
  int i, j, q, now;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  Q.clear();
  scanf("%d", &q);
  for (i = 1; i <= q; i++) {
    scanf("%d", &query[i]);
    Q[query[i]] = i;
    ans[i] = 0;
  }
  ST.init(1, n);
  for (i = 1; i <= n; i++) {
    j = i;
    while (j <= n) {
      now = ST.query(i, j).v;
      int l = ST.biquery(j, now);
      if (Q.find(now) == Q.end())
        ;
      else {
        int th = Q[now];
        ans[th] += l - j + 1;
      }
      j = l + 1;
    }
  }
  for (i = q; i >= 1; i--) {
    int th = Q[query[i]];
    ans[i] = ans[th];
  }
  for (i = 1; i <= q; i++) printf("%I64d\n", ans[i]);
  return 0;
}
