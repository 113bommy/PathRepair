#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 123;
long long dp[N], bit[N], cnt[N];
vector<int> ed[N];
int x[N], l[N], t[N];
void load() {}
void update(int x, int sl, int val) {
  while (x <= 1000000) {
    bit[x] += 1LL * sl * val;
    cnt[x] += sl;
    x += (x & -x);
  }
}
pair<long long, long long> get(int x) {
  long long val = 0, sl = 0;
  while (x > 0) {
    val += bit[x], sl += cnt[x];
    x -= (x & -x);
  }
  return make_pair(val, sl);
}
void dfs(int u, long long remain) {
  if (remain <= 0) return;
  update(t[u], x[u], t[u]);
  int d = 0, c = 1e6;
  while (d < c) {
    int m = (d + c + 1) >> 1;
    if (get(m).first <= remain)
      d = m;
    else
      c = m - 1;
  }
  pair<long long, long long> tmp = get(d);
  long long cnt = tmp.second;
  if (d < 1000000) cnt += (remain - tmp.first) / (d + 1);
  dp[u] = cnt;
  for (int v : ed[u]) dfs(v, remain - l[v]);
  update(u, -x[u], t[u]);
  return;
}
long long calc(int u) {
  long long res = dp[u];
  long long mx1 = 0, mx2 = 0;
  for (int v : ed[u]) {
    long long tmp = calc(v);
    if (mx1 < tmp)
      mx2 = mx1, mx1 = tmp;
    else if (tmp > mx2)
      mx2 = tmp;
  }
  return max(res, mx2);
}
void trungtt() {
  int n;
  long long T;
  scanf("%d%lld", &n, &T);
  for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &t[i]);
  for (int i = 2; i <= n; ++i) {
    int p;
    scanf("%d%d", &p, &l[i]);
    ed[p].push_back(i);
    l[i] *= 2;
  }
  dfs(1, T);
  long long ans = dp[1];
  for (int v : ed[1]) ans = max(ans, calc(v));
  printf("%lld", ans);
}
int main() {
  load();
  trungtt();
  return 0;
}
