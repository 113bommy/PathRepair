#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
struct Interval {
  long long a, b, ind;
  bool operator<(const Interval& ano) const { return b < ano.b; }
} a[200010];
bool used[200010];
set<long long> st;
struct SEG {
  long long sum[800010], tg1[800010], tg2[800010];
  inline void pushup(long long u) {
    sum[u] = (sum[u << 1] + sum[u << 1 | 1]) % mod;
  }
  inline void pushdown(long long u, long long l, long long r) {
    long long mid = (l + r) >> 1;
    if (tg1[u]) {
      tg1[u << 1] = tg1[u], tg2[u << 1] = 0;
      sum[u << 1] = tg1[u] * (mid - l + 1) % mod;
      tg1[u << 1 | 1] = tg1[u], tg2[u << 1 | 1] = 0;
      sum[u << 1 | 1] = tg1[u] * (r - mid) % mod;
      tg1[u] = 0;
    }
    if (tg2[u]) {
      tg2[u << 1] = (tg2[u << 1] + tg2[u]) % mod;
      sum[u << 1] = (sum[u << 1] + (mid - l + 1) * tg2[u]) % mod;
      tg2[u << 1 | 1] = (tg2[u << 1 | 1] + tg2[u]) % mod;
      sum[u << 1 | 1] = (sum[u << 1 | 1] + (r - mid) * tg2[u]) % mod;
      tg2[u] = 0;
    }
  }
  void Build(long long u, long long l, long long r) {
    if (l == r) {
      sum[u] = tg1[u] = tg2[u] = 0;
      return;
    }
    long long mid = (l + r) >> 1;
    Build(u << 1, l, mid);
    Build(u << 1 | 1, mid + 1, r);
    pushup(u);
  }
  void Add(long long u, long long l, long long r, long long L, long long R,
           long long ad) {
    if (r < L || R < l) return;
    if (L <= l && r <= R) {
      tg2[u] = (tg2[u] + ad) % mod;
      sum[u] = (sum[u] + (r - l + 1) * ad) % mod;
      return;
    }
    pushdown(u, l, r);
    long long mid = (l + r) >> 1;
    Add(u << 1, l, mid, L, R, ad);
    Add(u << 1 | 1, mid + 1, r, L, R, ad);
    pushup(u);
  }
  void Assign(long long u, long long l, long long r, long long L, long long R,
              long long as) {
    if (r < L || R < l) return;
    if (L <= l && r <= R) {
      tg1[u] = as, tg2[u] = 0;
      sum[u] = (r - l + 1) * as % mod;
      return;
    }
    pushdown(u, l, r);
    long long mid = (l + r) >> 1;
    Assign(u << 1, l, mid, L, R, as);
    Assign(u << 1 | 1, mid + 1, r, L, R, as);
    pushup(u);
  }
  long long Query(long long u, long long l, long long r, long long L,
                  long long R) {
    if (r < L || R < l) return 0;
    if (L <= l && r <= R) return sum[u];
    pushdown(u, l, r);
    long long mid = (l + r) >> 1, ans = 0;
    ans = Query(u << 1, l, mid, L, R);
    ans = (ans + Query(u << 1 | 1, mid + 1, r, L, R)) % mod;
    pushup(u);
    return ans;
  }
} S1, S2;
signed main() {
  long long n;
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++)
    scanf("%lld %lld", &a[i].a, &a[i].b), a[i].ind = i;
  sort(a + 1, a + n + 1);
  long long T;
  scanf("%lld", &T);
  while (T--) {
    long long x;
    scanf("%lld", &x);
    used[x] = true;
  }
  S1.Build(1, 1, n << 1), S2.Build(1, 1, n << 1);
  st.insert(2 * n);
  for (long long i = 1; i <= n; i++) {
    long long pos = *(st.lower_bound(a[i].a));
    long long s1 = S1.Query(1, 1, n << 1, pos, pos),
              s2 = s1 - S2.Query(1, 1, n << 1, pos, pos);
    S1.Assign(1, 1, n << 1, a[i].a, a[i].a, (s1 * 2 + 1) % mod);
    if (used[a[i].ind])
      S2.Assign(1, 1, n << 1, a[i].a, a[i].a, (s1 - s2 + mod) % mod);
    else
      S2.Assign(1, 1, n << 1, a[i].a, a[i].a, (s1 * 2 + 1 - s2 + mod) % mod);
    if (used[a[i].ind]) S2.Assign(1, 1, n << 1, 1, a[i].a - 1, mod - s2 - 1);
    S1.Add(1, 1, n << 1, 1, a[i].a - 1, (s1 + 1) % mod);
    S2.Add(1, 1, n << 1, 1, a[i].a - 1, (s1 + 1) % mod);
    st.insert(a[i].a);
  }
  printf("%lld\n",
         (S1.Query(1, 1, n << 1, 1, 1) - S2.Query(1, 1, n << 1, 1, 1) + mod) %
             mod);
  return 0;
}
