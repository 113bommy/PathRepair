#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL mod = 998244353;
const int maxn = 1e6 + 7;
LL qpow(LL a, LL x) {
  LL res = 1;
  while (x) {
    if (x & 1) res = res * a % mod;
    x >>= 1;
    a = a * a % mod;
  }
  return res;
}
vector<int> a[maxn];
vector<int> b[maxn];
LL inv[maxn];
LL po[maxn];
inline void init() {
  for (int i = 1; i <= 1000000; i++) {
    inv[i] = qpow(i, mod - 2);
  }
}
int main() {
  int n, _a, _k;
  init();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &_k);
    for (int j = 0; j < _k; j++) {
      scanf("%d", &_a);
      a[i].push_back(_a);
      b[_a].push_back(i);
    }
  }
  LL ans = 0;
  for (int i = 1; i <= 1000000; i++) {
    if (!b[i].empty()) {
      for (auto it : b[i]) {
        po[i] = (po[i] + inv[a[it].size()]) % mod;
      }
      po[i] = po[i] * inv[n] % mod;
    }
    po[i] = po[i] * b[i].size() % mod * inv[n] % mod;
    ans = (ans + po[i]) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
