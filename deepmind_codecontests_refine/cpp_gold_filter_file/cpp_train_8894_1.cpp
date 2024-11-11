#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10, inf = 1e9;
struct pony {
  long long A, R, M, D;
  friend bool operator<(const pony &i, const pony &j) { return i.D < j.D; }
  pony() {}
  pony(long long _A, long long _R, long long _M) {
    A = _A, R = _R, M = _M, D = (R == 0 ? inf : (M + R - 1) / R);
  }
  pony(long long _D) : D(_D) {}
} p[N];
struct Node {
  long long t = -2;
  vector<pony> vec;
  vector<long long> Rsum, Msum;
  long long cal(long long ts) {
    long long ans = 0;
    if (t == -2)
      for (pony i : vec) ans += min(i.M, i.A + i.R * ts);
    else {
      long long x =
          upper_bound(vec.begin(), vec.end(), pony(ts - t)) - vec.begin();
      ans = Rsum[x] * (ts - t) + Msum[x];
    }
    t = ts;
    return ans;
  }
} seg[N << 2];
void Merge(long long id) {
  merge(seg[id << 1].vec.begin(), seg[id << 1].vec.end(),
        seg[id << 1 | 1].vec.begin(), seg[id << 1 | 1].vec.end(),
        back_inserter(seg[id].vec));
  seg[id].Rsum.resize(seg[id].vec.size() + 1, 0);
  seg[id].Msum.resize(seg[id].vec.size() + 1, 0);
  for (long long i = 1; i <= seg[id].vec.size(); i++)
    seg[id].Msum[i] = seg[id].Msum[i - 1] + seg[id].vec[i - 1].M;
  for (long long i = seg[id].vec.size() - 1; i >= 0; i--)
    seg[id].Rsum[i] = seg[id].Rsum[i + 1] + seg[id].vec[i].R;
}
void build(long long L, long long R, long long id = 1) {
  if (R - L == 1) {
    seg[id].vec.push_back(p[L]);
    seg[id].Rsum = {p[L].R, 0};
    seg[id].Msum = {0, p[L].M};
    return;
  }
  build(L, (L + R) >> 1, id << 1);
  build((L + R) >> 1, R, id << 1 | 1);
  Merge(id);
}
long long get(long long l, long long r, long long t, long long L, long long R,
              long long id = 1) {
  if (r <= L || R <= l) return 0;
  if (l <= L && R <= r && seg[id].t != -1) return seg[id].cal(t);
  if (seg[id].t >= 0) seg[id << 1].t = seg[id << 1 | 1].t = seg[id].t;
  long long ans = get(l, r, t, L, (L + R) >> 1, id << 1) +
                  get(l, r, t, (L + R) >> 1, R, id << 1 | 1);
  seg[id].t = (seg[id << 1].t == seg[id << 1 | 1].t ? seg[id << 1].t : -1);
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long A, M, R;
    cin >> A >> M >> R;
    p[i] = pony(A, R, M);
  }
  build(0, n);
  long long q;
  cin >> q;
  while (q--) {
    long long l, r, t;
    cin >> t >> l >> r;
    cout << get(l - 1, r, t, 0, n) << "\n";
  }
  return 0;
}
