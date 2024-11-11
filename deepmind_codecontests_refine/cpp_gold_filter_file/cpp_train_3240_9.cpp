#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
using namespace std;
namespace ywy {
inline long long mi(int a, int b) {
  long long ans = 1, tmp = a;
  while (b) {
    if (b & 1) ans = (ans * tmp) % 998244353;
    tmp = (tmp * tmp) % 998244353;
    b >>= 1;
  }
  return (ans);
}
int lsh[300], cnt[2001];
int data[2001];
inline void up(int tree, int l, int r) {
  if (cnt[tree])
    data[tree] = lsh[r] - lsh[l - 1];
  else
    data[tree] = data[(tree << 1)] + data[((tree << 1) | 1)];
}
void add(int rl, int rr, int l, int r, int tree, int x) {
  if (rl == l && rr == r) {
    cnt[tree] += x;
    if (!cnt[tree]) {
      if (l == r)
        data[tree] = 0;
      else
        data[tree] = data[(tree << 1)] + data[((tree << 1) | 1)];
    } else
      data[tree] = lsh[r] - lsh[l - 1];
    return;
  }
  int mid = (l + r) >> 1;
  if (rl > mid)
    add(rl, rr, mid + 1, r, ((tree << 1) | 1), x);
  else {
    if (rr <= mid)
      add(rl, rr, l, mid, (tree << 1), x);
    else {
      add(rl, mid, l, mid, (tree << 1), x);
      add(mid + 1, rr, mid + 1, r, ((tree << 1) | 1), x);
    }
  }
  up(tree, l, r);
}
long long inv2, inv6;
inline long long sig2(long long n) {
  long long cjr = n;
  cjr *= (n + 1);
  cjr %= 998244353;
  cjr *= (n * 2 + 1);
  cjr %= 998244353;
  cjr *= inv6;
  return (cjr % 998244353);
}
inline long long sig(long long n) {
  long long cjr = n;
  cjr *= (n + 1);
  cjr %= 998244353;
  cjr *= inv2;
  return (cjr % 998244353);
}
typedef struct _n {
  int l;
  int r;
} node;
vector<node> adds[300], dels[300];
inline void clear(vector<node> &v) {
  vector<node> tmp;
  v = tmp;
}
int xs[60], ys[60];
int n;
void build(int l, int r, int tree) {
  cnt[tree] = data[tree] = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(l, mid, (tree << 1));
  build(mid + 1, r, ((tree << 1) | 1));
}
inline long long getS(int t) {
  int ptr = 1;
  for (register int i = 1; i <= n; i++) {
    lsh[ptr] = xs[i] - t - 1;
    ptr++;
    lsh[ptr] = xs[i] + t;
    ptr++;
    lsh[ptr] = ys[i] - t - 1;
    ptr++;
    lsh[ptr] = ys[i] + t;
    ptr++;
  }
  ptr--;
  sort(lsh + 1, lsh + 1 + ptr);
  ptr = unique(lsh + 1, lsh + 1 + ptr) - lsh - 1;
  build(1, ptr, 1);
  for (register int i = 1; i <= ptr; i++) clear(adds[i]), clear(dels[i]);
  for (register int i = 1; i <= n; i++) {
    node cjr;
    cjr.l = lower_bound(lsh + 1, lsh + 1 + ptr, ys[i] - t - 1) - lsh + 1;
    cjr.r = lower_bound(lsh + 1, lsh + 1 + ptr, ys[i] + t) - lsh;
    int l = lower_bound(lsh + 1, lsh + 1 + ptr, xs[i] - t - 1) - lsh;
    int r = lower_bound(lsh + 1, lsh + 1 + ptr, xs[i] + t) - lsh;
    adds[l].push_back(cjr);
    dels[r].push_back(cjr);
  }
  long long ans = 0;
  for (register int i = 1; i <= ptr; i++) {
    ans = (ans + data[1] * (long long)(lsh[i] - lsh[i - 1])) % 998244353;
    for (register int j = 0; j < adds[i].size(); j++)
      add(adds[i][j].l, adds[i][j].r, 1, ptr, 1, 1);
    for (register int j = 0; j < dels[i].size(); j++)
      add(dels[i][j].l, dels[i][j].r, 1, ptr, 1, -1);
  }
  return (ans);
}
int tme[100001];
void ywymain() {
  inv2 = mi(2, 998244353 - 2);
  inv6 = mi(6, 998244353 - 2);
  int t;
  cin >> n >> t;
  for (register int i = 1; i <= n; i++) cin >> xs[i] >> ys[i];
  int ptr = 1;
  for (register int i = 1; i <= n; i++) {
    for (register int j = 1; j < i; j++) {
      tme[ptr] = max(((xs[i] - xs[j] < 0) ? -(xs[i] - xs[j]) : xs[i] - xs[j]),
                     ((ys[i] - ys[j] < 0) ? -(ys[i] - ys[j]) : ys[i] - ys[j])) /
                 2;
      if (tme[ptr] <= t) ptr++;
      tme[ptr] = max(((xs[i] - xs[j] < 0) ? -(xs[i] - xs[j]) : xs[i] - xs[j]),
                     ((ys[i] - ys[j] < 0) ? -(ys[i] - ys[j]) : ys[i] - ys[j])) /
                     2 +
                 1;
      if (tme[ptr] <= t) ptr++;
    }
  }
  tme[ptr] = 0;
  ptr++;
  tme[ptr] = t;
  sort(tme + 1, tme + 1 + ptr);
  ptr = unique(tme + 1, tme + 1 + ptr) - tme - 1;
  long long ans = (getS(t) * t) % 998244353;
  for (register int i = 1; i < ptr; i++) {
    if (tme[i + 1] - tme[i] <= 2) {
      for (register int j = tme[i]; j < tme[i + 1]; j++)
        ans = (ans + 998244353 - getS(j)) % 998244353;
      continue;
    }
    long long c = getS(tme[i]), A = getS(tme[i] + 1), B = getS(tme[i] + 2);
    long long a = (B - A * 2 + c) * inv2;
    a %= 998244353;
    a += 998244353;
    a %= 998244353;
    long long b = A - c - a;
    b %= 998244353;
    b += 998244353;
    b %= 998244353;
    ans -= a * sig2(tme[i + 1] - tme[i] - 1);
    ans %= 998244353;
    ans += 998244353;
    ans %= 998244353;
    ans -= b * sig(tme[i + 1] - tme[i] - 1);
    ans %= 998244353;
    ans += 998244353;
    ans %= 998244353;
    ans -= c * (tme[i + 1] - tme[i]);
    ans %= 998244353;
    ans += 998244353;
    ans %= 998244353;
  }
  cout << ans << endl;
}
}  // namespace ywy
int main() {
  ywy::ywymain();
  return (0);
}
