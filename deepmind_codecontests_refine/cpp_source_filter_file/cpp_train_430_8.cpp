#include <bits/stdc++.h>
#pragma "SINISTIN_PITUH"
#pragma "all_I_want-Moscows_prize_and_vseros"
using namespace std;
const bool sosat = false;
const long long inf = 1e9, MAXN = 10;
struct node {
  long long l, r;
  long long mx, add;
  node() {
    l = r = -1;
    mx = inf;
    add = 0;
  }
};
node T[4 * MAXN];
long long a[MAXN];
void push(long long i) {
  T[i].mx += T[i].add;
  if (T[i].l == T[i].r) {
    T[i].add = 0;
    return;
  }
  T[i * 2].add += T[i].add;
  T[i * 2 + 1].add += T[i].add;
  T[i].add = 0;
}
void build(long long i, long long l, long long r) {
  if (l > r) return;
  T[i].l = l, T[i].r = r;
  if (l == r) {
    T[i].mx = a[l];
    return;
  }
  long long mid = (l + r) / 2;
  build(i * 2, l, mid);
  build(i * 2 + 1, mid + 1, r);
  T[i].mx = max(T[i * 2].mx, T[i * 2 + 1].mx);
}
vector<long long> tmp(100, 0);
void change(long long i, long long l, long long r, long long op) {
  push(i);
  if (T[i].r < l || r < T[i].l) return;
  if (l <= T[i].l && T[i].r <= r) {
    T[i].add += op;
    push(i);
    return;
  }
  change(i * 2, l, r, op);
  change(i * 2 + 1, l, r, op);
  push(i * 2);
  push(i * 2 + 1);
  T[i].mx = max(T[i * 2].mx, T[i * 2 + 1].mx);
}
void print(long long i) {
  push(i);
  cout << T[i].l << " " << T[i].r << " " << T[i].mx << endl;
  if (T[i].l == T[i].r) return;
  print(i * 2);
  print(i * 2 + 1);
}
long long get(long long i) {
  push(i);
  if (T[i].l == T[i].r) {
    if (T[i].mx > 0) return T[i].l;
    return -1;
  }
  if (T[i * 2 + 1].mx + T[i * 2 + 1].add > 0) return get(i * 2 + 1);
  if (T[i * 2].mx + T[i * 2].add > 0) return get(i * 2);
  return -1;
}
signed main() {
  ios_base::sync_with_stdio(sosat);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  long long vr;
  vector<long long> l1(n), l2(m);
  for (long long i = 0; i < n; ++i) {
    cin >> l1[i];
    a[l1[i]]++;
  }
  for (long long i = 0; i < m; ++i) {
    cin >> l2[i];
    a[l2[i]]--;
  }
  for (long long i = MAXN - 1; i >= 0; --i) a[i] += a[i + 1];
  build(1, 0, MAXN);
  long long q;
  cin >> q;
  while (q--) {
    long long op, i, v;
    cin >> op >> i >> v;
    --i;
    if (op == 1) {
      change(1, 0, l1[i], -1);
      l1[i] = v;
      change(1, 0, l1[i], +1);
    } else {
      change(1, 0, l2[i], +1);
      l2[i] = v;
      change(1, 0, l2[i], -1);
    }
    cout << get(1) << endl;
  }
}
