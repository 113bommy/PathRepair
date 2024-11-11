#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const double inf = 1e9;
int n, t, q, L[N], P[N];
double ans;
template <typename _Tp>
inline void IN(_Tp& x) {
  char ch;
  bool flag = 0;
  x = 0;
  while (ch = getchar(), !isdigit(ch))
    if (ch == '-') flag = 1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  if (flag) x = -x;
}
double calc(int t, int i) {
  return (double)(P[i] * L[i]) / (double)(t + L[i]) / (double)(t + L[i] - 1);
}
double _calc(int t, int i) { return (double)(t * P[i]) / (t + L[i]); }
struct Segment_Tree {
  int cnt[N];
  double Mx[N * 4], Mi[N * 4];
  void pushup(int x) {
    Mx[x] = max(Mx[((x) << 1)], Mx[((x) << 1 | 1)]),
    Mi[x] = min(Mi[((x) << 1)], Mi[((x) << 1 | 1)]);
  }
  void build(int x, int l, int r) {
    if (l == r) {
      Mi[x] = 1e9, Mx[x] = calc(1, l), cnt[x] = 0;
      return void();
    }
    int mid = (l + r) >> 1;
    build(((x) << 1), l, mid), build(((x) << 1 | 1), mid + 1, r), pushup(x);
  }
  void add(int x, int l, int r) {
    if (l == r) {
      if (Mx[x] != -inf) ans += Mx[x];
      Mi[x] = (cnt[l] + 1 > L[l]) ? -inf : calc(cnt[l] + 1, l);
      Mx[x] = (cnt[l] + 1 >= L[l]) ? -inf : calc(cnt[l] + 2, l);
      return cnt[l]++, void();
    }
    int mid = (l + r) >> 1;
    (Mx[((x) << 1)] > Mx[((x) << 1 | 1)]) ? add(((x) << 1), l, mid)
                                          : add(((x) << 1 | 1), mid + 1, r);
    pushup(x);
  }
  void del(int x, int l, int r) {
    if (l == r) {
      if (Mi[x] != -inf) ans -= Mi[x];
      Mi[x] = (cnt[l] - 1 > L[l]) ? -inf
                                  : ((cnt[l] - 1) ? calc(cnt[l] - 1, l) : inf);
      Mx[x] = (cnt[l] - 1 >= L[l]) ? -inf : calc(cnt[l], l);
      return cnt[l]--, void();
    }
    int mid = (l + r) >> 1;
    (Mi[((x) << 1)] < Mi[((x) << 1 | 1)]) ? del(((x) << 1), l, mid)
                                          : del(((x) << 1 | 1), mid + 1, r);
    pushup(x);
  }
  void update(int x, int l, int r, int pos, int val) {
    if (l == r) {
      ans -= _calc(min(cnt[l], L[l]), l), L[l] += val,
          ans += _calc(min(cnt[l], L[l]), l);
      Mi[x] = (cnt[l] > L[l]) ? -inf : ((cnt[l]) ? calc(cnt[l], l) : inf);
      Mx[x] = (cnt[l] >= L[l]) ? -inf : calc(cnt[l] + 1, l);
      return void();
    }
    int mid = (l + r) >> 1;
    (pos <= mid) ? update(((x) << 1), l, mid, pos, val)
                 : update(((x) << 1 | 1), mid + 1, r, pos, val);
    pushup(x);
  }
} Tree;
int main() {
  IN(n), IN(t), IN(q);
  for (int i = 1; i <= n; ++i) IN(P[i]);
  for (int i = 1; i <= n; ++i) IN(L[i]);
  Tree.build(1, 1, n);
  for (int i = 1; i <= t; ++i) Tree.add(1, 1, n);
  while (q--) {
    int op, pos;
    IN(op), IN(pos);
    Tree.update(1, 1, n, pos, (op == 1) ? 1 : -1);
    while (Tree.Mi[1] < Tree.Mx[1]) Tree.add(1, 1, n), Tree.del(1, 1, n);
    printf("%.10f\n", ans);
  }
  return 0;
}
