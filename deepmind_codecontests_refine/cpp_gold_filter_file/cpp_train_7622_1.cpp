#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5, mod = 1e9 + 7;
int n;
int a[N], p[N];
long long X[N], Y[N];
pair<int, int> q[N];
unordered_map<int, int> idx;
vector<int> nums;
struct segment_tree {
  int l, r;
  long long cnt, res, pre, suf;
} T[N << 2];
long long quickpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
void update(int p) {
  int lp = p << 1, rp = lp | 1;
  long long x = X[T[lp].cnt], y = Y[T[lp].cnt];
  T[p].cnt = T[lp].cnt + T[rp].cnt;
  T[p].res =
      (T[lp].res + T[rp].res + T[lp].pre * T[rp].suf % mod * y % mod) % mod;
  T[p].pre = (T[lp].pre + T[rp].pre * x % mod) % mod;
  T[p].suf = (T[lp].suf + T[rp].suf * y % mod) % mod;
  return;
}
void build(int p, int l, int r) {
  T[p].l = l, T[p].r = r;
  if (l == r) return;
  int mid = l + r >> 1, lp = p << 1, rp = lp | 1;
  build(lp, l, mid);
  build(rp, mid + 1, r);
  return;
}
void change(int p, int pos, int x) {
  if (T[p].l == T[p].r) {
    if (x) {
      T[p].cnt = 1;
      T[p].res = 0;
      T[p].pre = x;
      T[p].suf = x * Y[1] % mod;
    } else
      T[p].cnt = T[p].res = T[p].pre = T[p].suf = 0;
    return;
  }
  int mid = T[p].l + T[p].r >> 1, lp = p << 1, rp = lp | 1;
  if (pos <= mid)
    change(lp, pos, x);
  else
    change(rp, pos, x);
  update(p);
  return;
}
int main() {
  for (int i = 0; i < N; i++) {
    X[i] = quickpow(2, i);
    Y[i] = quickpow(X[i], mod - 2);
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    nums.push_back(a[i]);
  }
  int Q;
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++) {
    scanf("%d %d", &q[i].first, &q[i].second);
    nums.push_back(q[i].second);
  }
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i++)
    if (!idx[nums[i]]) idx[nums[i]] = i + 1;
  build(1, 1, nums.size());
  for (int i = 1; i <= n; i++) change(1, p[i] = idx[a[i]]++, a[i]);
  printf("%lld\n", T[1].res);
  for (int i = 1; i <= Q; i++) {
    int pos = q[i].first, x = q[i].second;
    change(1, p[pos], 0);
    change(1, p[pos] = idx[x]++, x);
    printf("%lld\n", T[1].res);
  }
  return 0;
}
