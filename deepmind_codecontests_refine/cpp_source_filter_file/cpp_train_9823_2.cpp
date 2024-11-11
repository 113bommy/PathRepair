#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 60;
long long cnt(long long mx, long long c, long long l) {
  long long now = 0;
  for (long long i = 0; i < c; ++i) {
    now <<= l;
    ++now;
  }
  mx = (mx + now - 1) / now;
  return max(min(mx, (long long)1 << l) - (1 << (l - 1)), 1LL * 0);
}
vector<long long> prime[MAXN], d[MAXN];
long long find(long long mx) {
  long long res = 0;
  for (long long l = 1; l <= MAXN; ++l)
    for (auto i : d[l])
      if (i != l) {
        long long s = prime[i].size(), t = 1 << s;
        for (long long mask = 0; mask < t; ++mask) {
          long long now = i;
          for (long long j = 0; j < s; ++j)
            if (mask & (1 << j)) now /= prime[i][j];
          res +=
              (__builtin_popcount(mask) & 1 ? -1 : 1) * cnt(mx, l / now, now);
        }
      }
  return res;
}
int32_t main() {
  for (long long i = 1; i <= MAXN; ++i) {
    if (prime[i].empty() && i > 1)
      for (long long j = i; j <= MAXN; j += i) prime[j].push_back(i);
    for (long long j = i; j < MAXN; j += i) d[j].push_back(i);
  }
  long long l, r;
  cin >> l >> r;
  cout << find(r + 1) - find(l);
  return 0;
}
