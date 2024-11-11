#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}
struct segtree {
  static const long long SEG = 1 << 19;
  vector<long long> sum, ma, put;
  segtree() : sum(SEG * 2), ma(SEG * 2), put(SEG * 2, -1) {}
  inline void push(long long k, long long l, long long r) {
    if (put[k] == -1) return;
    sum[k] = (r - l) * put[k];
    ma[k] = put[k];
    if (k < SEG - 1) {
      put[k * 2 + 1] = put[k];
      put[k * 2 + 2] = put[k];
    }
    put[k] = -1;
  }
  void update(long long a, long long b, long long x, long long k = 0,
              long long l = 0, long long r = SEG) {
    push(k, l, r);
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      put[k] = x;
      push(k, l, r);
      return;
    }
    update(a, b, x, k * 2 + 1, l, (l + r) / 2);
    update(a, b, x, k * 2 + 2, (l + r) / 2, r);
    sum[k] = sum[k * 2 + 1] + sum[k * 2 + 2];
    ma[k] = max(ma[k * 2 + 1], ma[k * 2 + 2]);
  }
  long long getsum(long long a, long long b, long long k = 0, long long l = 0,
                   long long r = SEG) {
    push(k, l, r);
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return sum[k];
    return getsum(a, b, k * 2 + 1, l, (l + r) / 2) +
           getsum(a, b, k * 2 + 2, (l + r) / 2, r);
  }
  long long getmax(long long a, long long b, long long k = 0, long long l = 0,
                   long long r = SEG) {
    push(k, l, r);
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return ma[k];
    return max(getmax(a, b, k * 2 + 1, l, (l + r) / 2),
               getmax(a, b, k * 2 + 2, (l + r) / 2, r));
  }
  long long getidx(long long x, long long k = 0, long long l = 0,
                   long long r = SEG) {
    push(k, l, r);
    if (l + 1 == r) {
      return ma[k] >= x;
    }
    push(k * 2 + 1, l, (l + r) / 2);
    push(k * 2 + 2, (l + r) / 2, r);
    if (ma[k * 2 + 2] < x) return getidx(x, k * 2 + 1, l, (l + r) / 2);
    return (r - l) / 2 + getidx(x, k * 2 + 2, (l + r) / 2, r);
  }
};
long long N;
vector<pair<long long, long long> > evs[555555];
long long P, Q, R;
long long p[555555], q[555555], r[555555];
signed main() {
  scanf("%lld%lld%lld%lld", &N, &P, &Q, &R);
  for (long long i = 0; i < (N); i++) {
    scanf("%lld%lld%lld", &p[i], &q[i], &r[i]);
    evs[P].push_back({q[i], r[i]});
    evs[p[i]].push_back({Q, r[i]});
    evs[p[i]].push_back({q[i], R});
  }
  segtree seg;
  long long ans = 0;
  for (long long i = P; i > 0; i--) {
    for (auto &p : evs[i]) {
      long long t = seg.getidx(p.second);
      if (t >= p.first) continue;
      seg.update(t, p.first, p.second);
    }
    ans += seg.getsum(0, N + 114);
  }
  cout << P * Q * R - ans << endl;
  return 0;
}
