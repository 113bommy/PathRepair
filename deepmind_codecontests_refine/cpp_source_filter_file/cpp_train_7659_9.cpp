#include <bits/stdc++.h>
using namespace std;
vector<int> m[100005];
long long dp[100005] = {0};
int data[100005];
int cmp(int a, int b) { return a > b; }
void dfs(int now, int pre) {
  dp[now] = 1;
  vector<int> v;
  for (int i = 0; i < m[now].size(); i++) {
    int to = m[now][i];
    if (to == pre) continue;
    data[to]--;
    dfs(to, now);
    v.push_back(dp[to]);
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size() && data[now]; i++) {
    dp[now] += v[i] + 1;
    data[now]--;
  }
  for (int i = 0; data[now] && i < m[now].size(); i++) {
    int v = m[now][i];
    if (v == pre || data[v] == 0) continue;
    dp[now] += 2LL * min(data[now], data[v]);
    data[now] -= min(data[now], data[v]);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &data[i]);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    m[a].push_back(b);
    m[b].push_back(a);
  }
  int s;
  scanf("%d", &s);
  dfs(s, s);
  printf("%I64d", dp[s] - 1);
  return 0;
}
