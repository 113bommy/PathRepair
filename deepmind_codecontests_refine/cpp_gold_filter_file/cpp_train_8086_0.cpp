#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char c;
  for (c = getchar(); !isdigit(c); c = getchar())
    ;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
}
const int N = 5e5 + 50, P = 998244353;
int n, m;
long long tr[N << 2], tagB[N << 2], tagK[N << 2];
inline void up(int v) { tr[v] = (tr[v << 1] + tr[v << 1 ^ 1]) % P; }
inline void build(int v, int l, int r) {
  tagK[v] = 1;
  if (l == r)
    return;
  else {
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build(v << 1 ^ 1, mid + 1, r);
  }
}
inline void down(int v, int l, int r, int ls, int rs) {
  if (tagK[v] != 1) {
    long long x = tagK[v];
    tagK[v] = 1;
    (tagB[ls] *= x) %= P, (tagK[ls] *= x) %= P, (tr[ls] *= x) %= P;
    (tagB[rs] *= x) %= P, (tagK[rs] *= x) %= P, (tr[rs] *= x) %= P;
  }
  if (tagB[v] != 0) {
    long long x = tagB[v];
    tagB[v] = 0;
    int mid = (l + r) >> 1;
    (tagB[ls] += x) %= P, (tr[ls] += x * (mid - l + 1)) %= P;
    (tagB[rs] += x) %= P, (tr[rs] += x * (r - mid)) %= P;
  }
}
inline void update(int v, int l, int r, int s, int t, int x, int type) {
  if (s <= l && r <= t) {
    if (type == 2) {
      (tagB[v] += x) %= P;
      (tr[v] += x * (r - l + 1)) %= P;
    } else {
      (tagB[v] *= x) %= P;
      (tagK[v] *= x) %= P;
      (tr[v] *= x) %= P;
    }
    return;
  }
  down(v, l, r, v << 1, v << 1 ^ 1);
  int mid = (l + r) >> 1;
  if (s <= mid) update(v << 1, l, mid, s, t, x, type);
  if (t > mid) update(v << 1 ^ 1, mid + 1, r, s, t, x, type);
  up(v);
}
inline int query(int v, int l, int r, int s, int t) {
  if (s <= l && r <= t) return tr[v];
  down(v, l, r, v << 1, v << 1 ^ 1);
  int ret = 0, mid = (l + r) >> 1;
  if (s <= mid) (ret += query(v << 1, l, mid, s, t)) %= P;
  if (t > mid) (ret += query(v << 1 ^ 1, mid + 1, r, s, t)) %= P;
  return ret;
}
struct Pair {
  int x, y;
};
bool operator<(Pair a, Pair b) { return a.y < b.y; }
set<Pair> rng[N];
void xiJiaYi(int l, int r) {
  ;
  update(1, 1, n, l, r, 1, 2);
}
void xiChengEr(int l, int r) {
  ;
  update(1, 1, n, l, r, 2, 1);
}
void process(int x, int l, int r) {
  ;
  vector<Pair> a;
  auto &s = rng[x];
  auto p = s.lower_bound((Pair){0, l});
  if (p == s.end()) {
    s.insert((Pair){l, r});
    xiJiaYi(l, r);
    return;
  }
  for (; p != s.end(); ++p) {
    if (p->y < l || p->x > r) break;
    a.push_back(*p);
    ;
  }
  if (a.empty()) {
    s.insert((Pair){l, r});
    xiJiaYi(l, r);
    return;
  }
  if (a[0].x > l) xiJiaYi(l, a[0].x - 1);
  for (size_t i = 1; i < a.size(); ++i) {
    xiJiaYi(a[i - 1].y + 1, a[i].x - 1);
  }
  if (a[a.size() - 1].y < r) xiJiaYi(a[a.size() - 1].y + 1, r);
  for (auto i : a) {
    int L = max(l, i.x), R = min(r, i.y);
    xiChengEr(L, R);
    s.erase(i);
  }
  s.insert((Pair){min(l, a[0].x), max(r, a[a.size() - 1].y)});
  ;
}
int main() {
  int q;
  read(n), read(q);
  build(1, 1, n);
  for (int i = 1; i <= (q); ++i) {
    int t, l, r, x;
    read(t), read(l), read(r);
    if (t == 1) {
      read(x);
      process(x, l, r);
    } else {
      long long sum = query(1, 1, n, l, r);
      printf("%lld\n", sum);
    }
  }
  return 0;
}
