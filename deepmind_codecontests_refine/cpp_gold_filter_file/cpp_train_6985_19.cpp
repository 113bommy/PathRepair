#include <bits/stdc++.h>
using namespace std;
struct hh {
  size_t operator()(int64_t i) const { return i ^ 'wqwq'; }
};
inline int64_t mul(int64_t x, int64_t y, int64_t n) {
  int64_t t;
  x %= n;
  for (t = 0; y; x = (x << 1) % n, y >>= 1)
    if (y & 1) t = (t + x) % n;
  return t;
}
unordered_map<int64_t, vector<pair<int, int>>, hh> px;
const int N = 500001;
int64_t ans, v[N], p2[N];
int cnt, vcnt, s, t, n, m, k, vis[N], T;
const int64_t MOD = 1e9 + 7;
void dfs(vector<pair<int, int>>& e, int i) {
  vis[i] = T;
  ++vcnt;
  for (auto it = lower_bound(e.begin(), e.end(), make_pair(i, 0));
       it != e.end() && it->first == i; ++it)
    if (vis[it->second] < T) dfs(e, it->second);
}
int main() {
  *p2 = 1;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", v + i), p2[i] = p2[i - 1] * 2 % MOD;
  while (m--) {
    scanf("%d%d", &s, &t);
    auto& e = px[v[s] ^ v[t]];
    e.emplace_back(s, t);
    e.emplace_back(t, s);
  }
  ans = mul(p2[n], (1ll << k) - px.size(), MOD);
  for (auto& x : px) {
    ++T;
    cnt = vcnt = 0;
    sort(x.second.begin(), x.second.end());
    for (auto& y : x.second) {
      tie(s, t) = y;
      if (vis[s] < T) ++cnt, dfs(x.second, s);
    }
    ans += p2[n - vcnt + cnt];
  }
  printf("%lld\n", ans % MOD);
}
