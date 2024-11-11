#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, w[N], rt, sz[N];
vector<pair<int, int>> v[N];
int ans1;
double sum, d[N], sd, ans2 = DBL_MAX;
bool vis[N];
void dfs(int pos, int fa, int s) {
  sz[pos] = 1;
  int cur = 0;
  for (auto &i : v[pos])
    if (!vis[i.first] && i.first != fa)
      dfs(i.first, pos, s), sz[pos] += sz[i.first], cur = max(cur, sz[i.first]);
  cur = max(cur, n - sz[pos]);
  if (cur <= s / 2) rt = pos;
}
void calc(int pos, int fa, int t, int ss) {
  sum += pow(ss, 1.5) * w[pos];
  d[t] += pow(ss, 0.5) * 1.5 * w[pos];
  for (auto &i : v[pos])
    if (i.first != fa) calc(i.first, pos, t, ss + i.second);
}
void dfs(int pos, int s) {
  dfs(pos, 0, s);
  pos = rt;
  dfs(pos, 0, s);
  if (vis[pos]) return;
  vis[pos] = 1;
  sum = sd = 0;
  for (auto &i : v[pos])
    d[i.first] = 0, calc(i.first, pos, i.first, i.second), sd += d[i.first];
  if (sum < ans2) ans1 = pos, ans2 = sum;
  for (auto &i : v[pos])
    if (sd - 2 * d[i.first] < 0) {
      dfs(i.first, sz[i.first]);
      break;
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> w[i];
  int t1, t2, t3;
  for (int i = 1; i < n; i++)
    cin >> t1 >> t2 >> t3, v[t1].push_back({t2, t3}), v[t2].push_back({t1, t3});
  dfs(1, n);
  printf("%d %.10lf\n", ans1, ans2);
  return 0;
}
