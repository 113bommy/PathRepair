#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
unsigned long long seed[maxn];
unsigned long long Rand() {
  return ((unsigned long long)rand() << 48) |
         ((unsigned long long)rand() << 32) | (rand() << 16) | rand();
}
vector<int> G[maxn];
unsigned long long h[maxn];
map<unsigned long long, int> mp, cnt;
int tot, sum, ans;
void dfs_init(int x, int par) {
  h[x] = seed[0];
  for (auto v : G[x]) {
    if (v == par) continue;
    dfs_init(v, x);
    h[x] += seed[mp[h[v]]];
  }
  if (mp.count(h[x]) == 0) mp[h[x]] = ++tot;
  cnt[h[x]]++;
}
int idx = 1;
void dfs(int x, int par, unsigned long long H) {
  if (x > 1) {
    cnt[h[x]]--;
    if (cnt[h[x]] == 0) --sum;
    h[x] += seed[mp[H]];
    if (mp.count(h[x]) == 0) mp[h[x]] = ++tot;
    cnt[h[x]]++;
    if (cnt[h[x]] == 1) ++sum;
  }
  if (sum > ans) idx = x, ans = sum;
  cnt[h[x]]--;
  if (cnt[h[x]] == 0) --sum;
  for (auto v : G[x]) {
    if (v == par) continue;
    unsigned long long t = h[x] - seed[mp[h[v]]];
    cnt[t]++;
    if (cnt[t] == 1) sum++;
    if (!mp.count(t)) mp[t] = +tot;
    dfs(v, x, h[x] - seed[mp[h[v]]]);
    cnt[t]--;
    if (cnt[t] == 0) --sum;
  }
  cnt[h[x]]++;
  if (cnt[h[x]] == 1) ++sum;
  if (x > 1) {
    cnt[h[x]]--;
    if (cnt[h[x]] == 0) --sum;
    h[x] -= seed[mp[H]];
    cnt[h[x]]++;
    if (cnt[h[x]] == 1) ++sum;
  }
}
int main() {
  srand(time(0));
  for (int i = 0; i < maxn; ++i) seed[i] = Rand();
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs_init(1, 1);
  ans = sum = tot;
  dfs(1, 1, 0);
  cout << idx << endl;
  return 0;
}
