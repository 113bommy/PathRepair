#include <bits/stdc++.h>
using namespace std;
const long long Maxn = 2e5 + 5;
long long n, m, ans, each = 320, cube, isa[Maxn], bel[Maxn], Lps[Maxn],
                     Rps[Maxn];
vector<long long> vec[Maxn];
void Modify(long long l, long long r) {
  if (bel[l] == bel[r])
    swap(isa[l], isa[r]);
  else {
    vec[bel[l]].erase(
        lower_bound(vec[bel[l]].begin(), vec[bel[l]].end(), isa[l]));
    vec[bel[r]].erase(
        lower_bound(vec[bel[r]].begin(), vec[bel[r]].end(), isa[r]));
    vec[bel[l]].insert(
        upper_bound(vec[bel[l]].begin(), vec[bel[l]].end(), isa[r]), isa[r]);
    vec[bel[r]].insert(
        upper_bound(vec[bel[r]].begin(), vec[bel[r]].end(), isa[l]), isa[l]);
    swap(isa[l], isa[r]);
  }
}
long long Query(long long l, long long r, long long x) {
  if (l > r) return 0;
  const long long bl = bel[l], br = bel[r];
  long long ret = 0;
  for (long long i = l; i <= min(Rps[bl], r); ++i) ret += (isa[i] < x);
  if (bl != br) {
    for (long long i = Lps[br]; i <= r; ++i) ret += (isa[i] < x);
    for (long long i = bl + 1; i <= br - 1; ++i)
      ret += lower_bound(vec[i].begin(), vec[i].end(), x) - vec[i].begin();
  }
  return ret;
}
signed main() {
  scanf("%lld %lld", &n, &m);
  cube = (n - 1) / each + 1;
  for (long long i = 1; i <= n; ++i) isa[i] = i;
  for (long long i = 1; i <= cube; ++i) {
    Lps[i] = Rps[i - 1] + 1;
    Rps[i] = Rps[i - 1] + each;
    if (i == cube) Rps[i] = n;
    for (long long j = Lps[i]; j <= Rps[i]; ++j) {
      bel[j] = i;
      vec[i].push_back(isa[j]);
    }
  }
  for (long long i = 1, l, r; i <= m; ++i) {
    scanf("%lld %lld", &l, &r);
    if (l > r) swap(l, r);
    if (l == r) {
      printf("%lld\n", ans);
      continue;
    }
    if (isa[l] < isa[r])
      ++ans;
    else
      --ans;
    ans += (Query(l + 1, r - 1, isa[r]) - Query(l + 1, r - 1, isa[l])) << 1;
    Modify(l, r);
    printf("%lld\n", ans);
  }
  return 0;
}
