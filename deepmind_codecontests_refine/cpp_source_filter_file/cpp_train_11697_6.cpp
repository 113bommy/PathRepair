#include <bits/stdc++.h>
#pragma "SINITSIN_PITUH"
using namespace std;
const long long MAXN = 10, INF = 1e9 + 47;
struct node {
  long long l, r;
  long long v;
  node() {
    l = r = -1;
    v = 0;
  }
};
node Tf[4 * MAXN], Tb[4 * MAXN];
void build(long long l = 0, long long r = MAXN - 1, long long i = 1) {
  if (l > r) return;
  Tf[i].l = l, Tf[i].r = r;
  Tb[i].l = l, Tb[i].r = r;
  if (l == r) {
    return;
  }
  long long mid = (l + r) / 2;
  build(l, mid, i * 2);
  build(mid + 1, r, i * 2 + 1);
}
void upf(long long ind, long long op, long long i = 1) {
  if (ind < Tf[i].l || ind > Tf[i].r) return;
  if (Tf[i].l == ind && Tf[i].r == ind) {
    Tf[i].v += op;
    return;
  }
  upf(ind, op, i * 2);
  upf(ind, op, i * 2 + 1);
  Tf[i].v = Tf[i * 2].v + Tf[i * 2 + 1].v;
}
long long sumf(long long l, long long r, long long i = 1) {
  if (r < Tf[i].l || Tf[i].r < l) return 0;
  if (l <= Tf[i].l && Tf[i].r <= r) return Tf[i].v;
  return sumf(l, r, i * 2) + sumf(l, r, i * 2 + 1);
}
void upb(long long ind, long long op, long long i = 1) {
  if (ind < Tb[i].l || ind > Tb[i].r) return;
  if (Tb[i].l == ind && Tb[i].r == ind) {
    Tb[i].v += op;
    return;
  }
  upb(ind, op, i * 2);
  upb(ind, op, i * 2 + 1);
  Tb[i].v = Tb[i * 2].v + Tb[i * 2 + 1].v;
}
long long sumb(long long l, long long r, long long i = 1) {
  if (r < Tb[i].l || Tb[i].r < l) return 0;
  if (l <= Tb[i].l && Tb[i].r <= r) return Tb[i].v;
  return sumb(l, r, i * 2) + sumb(l, r, i * 2 + 1);
}
long long I = 0, ans = 0;
void addLeft(long long vr) {
  I += sumf(vr + 1, MAXN - 1) + sumb(0, vr - 1);
  upf(vr, 1);
}
void deleteRight(long long vr) {
  I -= sumf(vr + 1, MAXN - 1) + sumb(0, vr - 1);
  upb(vr, -1);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  build();
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<long long> b = a;
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  map<long long, long long> trans;
  for (long long i = 0; i < (long long)b.size(); i++) trans[b[i]] = i + 1;
  for (long long i = 0; i < n; i++) a[i] = trans[a[i]];
  long long l = -1, r;
  for (r = n - 1; r >= 0; --r) {
    long long temp = sumb(0, a[r] - 1);
    I += temp;
    upb(a[r], 1);
  }
  ++r;
  for (l = 0; l < n; ++l) {
    addLeft(a[l]);
    while (r < l + 1) {
      deleteRight(a[r]);
      ++r;
    }
    while (I > k && r < n) {
      deleteRight(a[r]);
      ++r;
    }
    if (I > k) break;
    ans += n - r;
  }
  cout << ans << endl;
}
