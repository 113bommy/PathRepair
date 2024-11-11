#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, k;
unsigned long long ans, a[20][20], goal, Hash[N], mod = 998244353;
vector<pair<int, int> > vec[N];
void dfs(int dep, unsigned long long sum) {
  if (dep == k + 1) {
    if (sum == goal) ans++;
    return;
  }
  for (int i = 1; i <= dep; i++) dfs(dep + 1, sum + a[dep][i]);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  Hash[0] = 1;
  for (int i = 1; i <= n; i++) {
    Hash[i] = Hash[i - 1] * mod;
    goal += Hash[i];
  }
  for (int i = 0; i < m; i++) {
    int v, u, w;
    scanf("%d%d%d", &u, &v, &w);
    vec[u].push_back(pair<int, int>(w, v));
  }
  for (int i = 1; i <= n; i++) {
    sort(vec[i].begin(), vec[i].end());
    long long tot = vec[i].size();
    for (int j = 0; j < tot; j++) {
      a[tot][j + 1] += Hash[vec[i][j].second];
    }
  }
  dfs(1, 0);
  printf("%lld\n", ans);
}
