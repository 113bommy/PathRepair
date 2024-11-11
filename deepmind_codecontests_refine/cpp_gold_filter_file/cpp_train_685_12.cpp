#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct {
  int f, l, r;
  void read() { scanf("%d%d%d", &f, &l, &r); }
} Q[maxn];
int A[maxn], N, M;
set<int> S[maxn];
int rt[4 * maxn + 5], ls[150 * maxn + 5], rs[150 * maxn + 5], SZ;
long long sum[150 * maxn + 5];
void addY(int &o, int l, int r, int ll0, int rr0, long long x) {
  if (!o) o = ++SZ;
  if (ll0 <= l && rr0 >= r) {
    sum[o] += x;
    return;
  }
  int mid = l + r >> 1;
  if (ll0 <= mid) addY(ls[o], l, mid, ll0, rr0, x);
  if (rr0 > mid) addY(rs[o], mid + 1, r, ll0, rr0, x);
}
void addX(int o, int l, int r, int l0, int r0, int ll0, int rr0, long long x) {
  if (l0 <= l && r0 >= r) {
    addY(rt[o], 1, N, ll0, rr0, x);
    return;
  }
  int mid = l + r >> 1;
  if (l0 <= mid) addX((o << 1), l, mid, l0, r0, ll0, rr0, x);
  if (r0 > mid) addX((o << 1 | 1), mid + 1, r, l0, r0, ll0, rr0, x);
}
long long queryY(int o, int l, int r, int r0) {
  if (l == r) return sum[o];
  int mid = l + r >> 1;
  long long ret = sum[o];
  if (r0 <= mid)
    ret += queryY(ls[o], l, mid, r0);
  else
    ret += queryY(rs[o], mid + 1, r, r0);
  return ret;
}
long long queryX(int o, int l, int r, int l0, int r0) {
  if (l == r) {
    return queryY(rt[o], 1, N, r0);
  }
  int mid = l + r >> 1;
  long long ret = queryY(rt[o], 1, N, r0);
  if (l0 <= mid)
    ret += queryX((o << 1), l, mid, l0, r0);
  else
    ret += queryX((o << 1 | 1), mid + 1, r, l0, r0);
  return ret;
}
void add(int val, int pos) {
  auto it = S[val].insert(pos).first;
  auto pre = it, nxt = it;
  int l = *(--pre), r = *(++nxt);
  if (l >= 1) addX(1, 1, N, 1, l, pos, r - 1, pos - l);
  if (r <= N) addX(1, 1, N, l + 1, pos, r, N, r - pos);
}
void del(int val, int pos) {
  auto it = S[val].find(pos);
  auto pre = it, nxt = it;
  int l = *(--pre), r = *(++nxt);
  S[val].erase(it);
  if (l >= 1) addX(1, 1, N, 1, l, pos, r - 1, -(pos - l));
  if (r <= N) addX(1, 1, N, l + 1, pos, r, N, -(r - pos));
}
void input() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
  for (int i = 0; i < M; i++) {
    Q[i].read();
  }
}
void solve() {
  SZ = 0;
  for (int i = 1; i <= N; i++) {
    S[i].insert(0);
    S[i].insert(N + 1);
  }
  for (int i = 1; i <= N; i++) {
    add(A[i], i);
  }
  for (int i = 0; i < M; i++) {
    if (Q[i].f == 1) {
      del(A[Q[i].l], Q[i].l);
      A[Q[i].l] = Q[i].r;
      add(A[Q[i].l], Q[i].l);
    } else {
      printf("%I64d\n", queryX(1, 1, N, Q[i].l, Q[i].r));
    }
  }
}
int main() {
  input();
  solve();
  return 0;
}
