#include <bits/stdc++.h>
using namespace std;
const int M_ = 200500;
const long long MOD = (long long)1e9 + 7;
int M;
map<int, int> D;
long long power(long long a, long long b) {
  long long ret = 1;
  while (b > 0) {
    if (b & 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}
int main() {
  scanf("%d", &M);
  while (M--) {
    int p;
    scanf("%d", &p);
    ++D[p];
  }
  long long ans = 1, num = 1;
  for (auto x : D) {
    int p = x.first, q = x.second;
    long long s = 1, t = 1;
    for (int i = 0; i <= q; i++) {
      s = (s * t) % MOD;
      t = (t * p) % MOD;
    }
    ans = (power(ans, q + 1) * power(s, num)) % MOD;
    num = (num * (q + 1)) % (MOD - 1);
  }
  printf("%lld\n", ans);
  return 0;
}
