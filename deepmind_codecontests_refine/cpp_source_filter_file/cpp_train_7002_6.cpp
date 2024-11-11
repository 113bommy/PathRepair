#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 11;
const int mod = 998244353;
long long n, s, sum;
struct zj {
  long long to, wei, cost;
};
vector<zj> edge[maxn];
int fat[maxn];
long long co1[maxn], co2[maxn], cc1, cc2, cnt[maxn];
struct fan {
  long long x, y;
  bool operator<(const fan b) const {
    return (y + 1) / 2 * x < (b.y + 1) / 2 * b.x;
  }
};
priority_queue<fan> q1, q2;
void pre_dfs(int now, int fa) {
  fat[now] = fa;
  int son = 0;
  for (auto to : edge[now])
    if (to.to != fa) son++;
  if (son == 0)
    cnt[now] = 1;
  else
    cnt[now] = 0;
  for (auto to : edge[now]) {
    if (to.to == fa) continue;
    pre_dfs(to.to, now);
    cnt[now] += cnt[to.to];
    sum += cnt[to.to] * to.wei;
    if (to.cost == 1)
      q1.push((fan){cnt[to.to], to.wei});
    else
      q2.push((fan){cnt[to.to], to.wei});
  }
}
void solve() {
  scanf("%lld%lld", &n, &s);
  sum = 0;
  cc1 = cc2 = 0;
  while (!q1.empty()) q1.pop();
  while (!q2.empty()) q2.pop();
  co1[0] = co2[0] = 0;
  for (int i = 0; i <= n + 11; ++i) edge[i].clear();
  for (int i = 1; i < n; ++i) {
    long long fr, to, we, co;
    scanf("%lld%lld", &fr, &to);
    scanf("%lld%lld", &we, &co);
    edge[fr].push_back((zj){to, we, co});
    edge[to].push_back((zj){fr, we, co});
  }
  pre_dfs(1, 0);
  if (sum <= s) {
    printf("0\n");
    return;
  }
  while (!q1.empty()) {
    auto now = q1.top();
    q1.pop();
    co1[++cc1] = (now.y + 1) / 2 * now.x;
    co1[cc1] += co1[cc1 - 1];
    if (sum - co1[cc1] <= s) break;
    now.y /= 2;
    if (now.y) q1.push(now);
  }
  while (!q2.empty()) {
    auto now = q2.top();
    q2.pop();
    co2[++cc2] = (now.y + 1) / 2 * now.x;
    co2[cc2] += co2[cc2 - 1];
    if (sum - co2[cc2] <= s) break;
    now.y /= 2;
    if (now.y) q2.push(now);
  }
  long long mi = 1e18 + 7;
  for (int i = 0; i <= cc1; ++i) {
    int ss = sum - co1[i];
    int l = 0, r = cc2;
    long long pos = 1e18;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (ss - co2[mid] <= s)
        pos = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    mi = min(mi, i + pos * 2);
  }
  printf("%d\n", mi);
}
int main() {
  int _;
  scanf("%d", &_);
  while (_--) solve();
  return 0;
}
