#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long inf = 1000000000000000000;
const long long KOK = 100000;
const long long LOG = 30;
const long long li = 500005;
const long long mod = 998244353;
long long n, m, b[li], a[li], k, flag, t, fac[li];
long long cev;
string s;
pair<long long, long long> p[li];
multiset<long long> st;
vector<long long> v;
inline long long add(long long x, long long y) {
  if (x + y >= mod) return x + y - mod;
  return x + y;
}
inline long long mul(long long x, long long y) {
  return (x % mod) * (y % mod) % mod;
}
inline long long fp(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long q = fp(x, y / 2);
  q = mul(q, q);
  if (y % 2) q = mul(q, x);
  return q;
}
int32_t main(void) {
  scanf("%lld %lld", &n, &k);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld %lld", &p[i].first, &p[i].second);
  }
  fac[0] = 1;
  for (long long i = 1; i <= n + 100; i++) {
    fac[i] = fac[i - 1] * i;
  }
  sort(p + 1, p + n + 1);
  long long say = 0;
  for (long long i = 1; i <= n; i++) {
    while (say) {
      if (*st.begin() >= p[i].first) break;
      if (say >= k)
        cev =
            add(cev, mul(fac[say - 1],
                         fp(mul(fac[k - 1], fac[say - 1 - (k - 1)]), mod - 2)));
      st.erase(st.begin());
      say--;
    }
    st.insert(p[i].second);
    say++;
  }
  long long i = n + 1;
  p[i].first = inf;
  while (say) {
    if (*st.begin() >= p[i].first) break;
    if (say >= k)
      cev = add(cev, mul(fac[say - 1],
                         fp(mul(fac[k - 1], fac[say - 1 - (k - 1)]), mod - 2)));
    st.erase(st.begin());
    say--;
  }
  printf("%lld\n", cev);
  return 0;
}
