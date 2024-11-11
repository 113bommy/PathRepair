#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, P = 1e9 + 7;
int n, a[N], fact[N] = {1};
struct node {
  int sum, cnt, lazy;
  inline void add(int x) {
    (sum += 1LL * x * cnt % P) %= P;
    (lazy += x) %= P;
  }
} seg[N << 2];
inline node merge(node a, node b) {
  return {(a.sum + b.sum) % P, a.cnt + b.cnt, 0};
}
inline void shift(int id) {
  seg[id << 1].add(seg[id].lazy);
  seg[id << 1 | 1].add(seg[id].lazy);
  seg[id].lazy = 0;
}
void build(int id = 1, int st = 0, int en = n) {
  seg[id] = {0, en - st, 0};
  if (en - st == 1) return;
  int mid = st + en >> 1;
  build(id << 1, st, mid);
  build(id << 1 | 1, mid, en);
}
void update(int l, int r, int x, int id = 1, int st = 0, int en = n) {
  if (r <= st || en <= l) return;
  if (l <= st && en <= r) return seg[id].add(x);
  shift(id);
  int mid = st + en >> 1;
  update(l, r, x, id << 1, st, mid);
  update(l, r, x, id << 1 | 1, mid, en);
  seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}
void remove(int p, int id = 1, int st = 0, int en = n) {
  if (en - st == 1) {
    seg[id] = {0, 0, 0};
    return;
  }
  shift(id);
  int mid = st + en >> 1;
  if (p < mid)
    remove(p, id << 1, st, mid);
  else
    remove(p, id << 1 | 1, mid, en);
  seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}
node get(int l, int r, int id = 1, int st = 0, int en = n) {
  if (r <= st || en <= l) return {};
  if (l <= st && en <= r) return seg[id];
  shift(id);
  int mid = st + en >> 1;
  return merge(get(l, r, id << 1, st, mid), get(l, r, id << 1 | 1, mid, en));
}
inline int calc(int x) {
  return x * (x - 1LL) / 2 % P * fact[x] % P * 500000004 % P;
}
inline void read_input() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
}
inline void solve() {
  build();
  int ans = 0, left = 0;
  for (int i = 1; i < n; i++) fact[i] = 1LL * fact[i - 1] * i % P;
  for (int i = 0; i < n; i++) {
    node x = get(0, --a[i]);
    (ans += 1LL * x.cnt * calc(n - i - 1) % P) %= P;
    (ans += x.cnt * (x.cnt - 1LL) / 2 % P * fact[n - i - 1] % P) %= P;
    (ans += 1LL * x.cnt * fact[n - i - 1] % P * (left + seg[1].sum) % P) %= P;
    (left += get(a[i], a[i] + 1).sum) %= P, update(0, a[i], 1), remove(a[i]);
  }
  cout << (ans + left) % P;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input(), solve();
  return 0;
}
