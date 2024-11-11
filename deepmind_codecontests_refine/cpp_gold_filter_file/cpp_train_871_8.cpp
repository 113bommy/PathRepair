#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int n_ = 1e5 + 5;
unordered_map<int, int> dp;
int calc(int msk) {
  if (dp.count(msk)) return dp[msk];
  set<int> x;
  int nmsk;
  for (int i = 0; (1ll << i) <= msk; i++) {
    if (msk & (1 << i)) {
      nmsk = msk;
      for (int j = i; (1ll << j) <= msk; j += (i + 1)) {
        if (msk & (1 << j)) nmsk ^= (1 << j);
      }
      x.insert(calc(nmsk));
    }
  }
  int ret = 0;
  while (x.count(ret)) ++ret;
  return dp[msk] = ret;
}
int g[] = {0, 1, 2, 1, 4, 3, 2, 1, 5,  6, 2, 1, 8,  7,  5, 9,
           8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};
long long n, ans;
unordered_map<long long, int> f;
int main() {
  scanf("%lld", &n);
  long long tmp = n;
  for (long long i = 2; i * i <= n; i++) {
    if (f[i]) continue;
    int sz = 0;
    for (long long j = i; j <= n; j *= i) ++sz, f[j] = 1;
    ans ^= g[sz];
    tmp -= sz;
  }
  tmp &= 1;
  ans ^= tmp;
  puts(ans ? "Vasya" : "Petya");
  return 0;
}
