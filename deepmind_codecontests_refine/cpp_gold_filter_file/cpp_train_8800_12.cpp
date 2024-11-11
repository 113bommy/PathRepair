#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, mod = 1e9 + 7;
int n, k, fac[N], lb[N], rb[N];
vector<pair<int, int> > v;
void init() {
  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = (long long)fac[i - 1] * i % mod;
}
int fastPow(int base, int pow) {
  int ret = 1;
  while (pow) {
    if (pow & 1) ret = (long long)ret * base % mod;
    base = (long long)base * base % mod;
    pow >>= 1;
  }
  return ret;
}
int comb(int r, int k) {
  if (k > r || k < 0) return 0;
  return (long long)fac[r] *
         fastPow((long long)fac[k] * fac[r - k] % mod, mod - 2) % mod;
}
int main() {
  init();
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= (n); i++) {
    scanf("%d%d", &lb[i], &rb[i]);
    v.push_back(make_pair(lb[i], 1));
    v.push_back(make_pair(rb[i] + 1, -1));
  }
  sort(v.begin(), v.end());
  int cnt = 0, ans = 0;
  for (int i = 0; i < (v.size()); i++) {
    cnt += v[i].second;
    if (i < v.size() - 1 && v[i].first < v[i + 1].first) {
      int len = v[i + 1].first - v[i].first;
      ans = (ans + (long long)len * comb(cnt, k)) % mod;
    }
  }
  printf("%d\n", ans);
  return 0;
}
