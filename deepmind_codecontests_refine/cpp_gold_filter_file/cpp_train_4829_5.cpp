#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 10;
long long ans;
long long n, k;
long long s[maxn];
long long l[maxn];
long long r[maxn];
long long seg[4 * maxn];
long long lazy[4 * maxn];
vector<long long> bois[maxn];
void in();
void solve();
long long doaz(long long);
long long get(long long, long long, long long, long long, long long);
void upd(long long, long long, long long, long long, long long);
void push(long long, long long, long long);
void out();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  in();
  solve();
  out();
}
void in() {
  cin >> n >> k;
  for (long long i = 0; i < n; i++) cin >> s[i];
  for (long long i = 0; i < k; i++) cin >> l[i] >> r[i];
}
void solve() {
  sort(s, s + n);
  for (long long i = 0; i < k; i++) {
    l[i] = lower_bound(s, s + n, l[i]) - s;
    r[i] = upper_bound(s, s + n, r[i]) - s;
    bois[l[i]].push_back(i);
    bois[r[i]].push_back(i);
  }
  for (long long i = 0; i < n; i++) {
    l[k + i] = i;
    r[k + i] = i + 1;
    bois[i].push_back(k + i);
  }
  ans = n * (n - 1) * (n - 2) / 6;
  for (long long i = 0; i < n; i++) {
    for (auto j : bois[i]) upd(1, 0, n, l[j], r[j]);
    ans -= doaz(get(1, 0, n, 0, n) - get(1, 0, n, i, i + 1));
  }
}
long long get(long long id, long long l, long long r, long long L,
              long long R) {
  if (r <= L || R <= l) return 0;
  if (L <= l && r <= R) return seg[id];
  if (lazy[id]) push(id, l, r);
  long long mid = (l + r) >> 1;
  return get(id << 1, l, mid, L, R) + get(id << 1 | 1, mid, r, L, R);
}
void upd(long long id, long long l, long long r, long long L, long long R) {
  if (r <= L || R <= l) return;
  if (L <= l && r <= R) {
    seg[id] = r - l - seg[id];
    lazy[id] = 1 - lazy[id];
    return;
  }
  if (lazy[id]) push(id, l, r);
  long long mid = (l + r) >> 1;
  upd(id << 1, l, mid, L, R);
  upd(id << 1 | 1, mid, r, L, R);
  seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
void push(long long id, long long l, long long r) {
  long long mid = (l + r) >> 1;
  lazy[id] = 0;
  lazy[id << 1] = 1 - lazy[id << 1];
  lazy[id << 1 | 1] = 1 - lazy[id << 1 | 1];
  seg[id << 1] = mid - l - seg[id << 1];
  seg[id << 1 | 1] = r - mid - seg[id << 1 | 1];
}
bool cmp(long long i, long long j) { return s[i] < s[j]; }
long long doaz(long long x) { return x * (x - 1) / 2; }
void out() { cout << ans; }
