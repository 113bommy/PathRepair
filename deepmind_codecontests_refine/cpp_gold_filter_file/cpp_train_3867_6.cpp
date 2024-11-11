#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 100;
const long long mod = 1e9 + 7;
long long sum[N << 2], pi[N << 2], tag[N << 2], ptag[N << 2], inv[320],
    las[320], pri[320];
int cnt = -1, vis[320];
void init() {
  inv[1] = 1;
  for (int i = 2; i <= 300; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    if (!vis[i]) {
      pri[++cnt] = i;
      for (int j = i + i; j <= 300; j += i) vis[j] = 1;
    }
  }
  for (int i = 0; i <= cnt; i++) las[i] = (pri[i] - 1) * inv[pri[i]] % mod;
}
long long qpow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret % mod;
}
void pushup(int id) {
  sum[id] = sum[id << 1] * sum[id << 1 | 1] % mod;
  pi[id] = pi[id << 1] | pi[id << 1 | 1];
}
void modify(int id, long long len, long long val, long long f) {
  sum[id] = sum[id] * qpow(val, len) % mod;
  pi[id] |= f;
  tag[id] = tag[id] * val % mod;
  ptag[id] |= f;
}
void pushdown(int id, int l, int r) {
  int mid = l + r >> 1;
  if (tag[id] != 1 || ptag[id]) {
    modify(id << 1, (long long)(mid - l + 1), tag[id], ptag[id]);
    modify(id << 1 | 1, (long long)(r - mid), tag[id], ptag[id]);
    ptag[id] = 0;
    tag[id] = 1ll;
  }
}
void build(int id, int l, int r) {
  tag[id] = 1ll;
  if (l == r) {
    scanf("%lld", &sum[id]);
    for (int i = 0; i <= cnt; i++)
      if (sum[id] % pri[i] == 0) pi[id] |= (1ll << i);
    return;
  }
  int mid = l + r >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  pushup(id);
}
void update(int id, int l, int r, int L, int R, long long val, long long f) {
  if (L <= l && R >= r) {
    modify(id, (long long)(r - l + 1), val, f);
    return;
  }
  pushdown(id, l, r);
  int mid = l + r >> 1;
  if (L <= mid) update(id << 1, l, mid, L, R, val, f);
  if (R > mid) update(id << 1 | 1, mid + 1, r, L, R, val, f);
  pushup(id);
}
pair<long long, long long> query(int id, int l, int r, int L, int R) {
  if (L <= l && R >= r) {
    return make_pair(sum[id], pi[id]);
  }
  int mid = l + r >> 1;
  pair<long long, long long> ans = make_pair(1ll, 0), q;
  pushdown(id, l, r);
  if (L <= mid) {
    q = query(id << 1, l, mid, L, R);
    ans.first *= q.first, ans.second |= q.second;
    ans.first %= mod;
  }
  if (R > mid) {
    q = query(id << 1 | 1, mid + 1, r, L, R);
    ans.first *= q.first, ans.second |= q.second;
    ans.first %= mod;
  }
  return ans;
}
int main() {
  init();
  int n, m;
  scanf("%d%d", &n, &m);
  build(1, 1, n);
  char op[30];
  int l, r;
  long long x;
  for (int i = 1; i <= m; i++) {
    scanf("%s%d%d", op, &l, &r);
    if (op[0] == 'T') {
      pair<long long, long long> ret = query(1, 1, n, l, r);
      long long ans = ret.first;
      for (int i = 0; i <= cnt; i++)
        if ((ret.second >> i) & 1) ans = ans * las[i] % mod;
      printf("%lld\n", ans);
    } else {
      scanf("%lld", &x);
      long long c = 0;
      for (int i = 0; i <= cnt; i++)
        if (x % pri[i] == 0) c |= (1ll << i);
      update(1, 1, n, l, r, x, c);
    }
  }
  return 0;
}
