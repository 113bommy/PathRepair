#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2 * (1e5 + 1);
vector<long long int> adj[maxn];
bool visit[maxn];
long long int bf[maxn], gf[maxn], ans[maxn];
void dfs(long long int i) {
  if (visit[i]) return;
  visit[i] = true;
  for (long long int j = 0; j < int(adj[i].size()); j++) {
    if (!visit[adj[i][j]]) {
      ans[adj[i][j]] = (ans[i] + 1) % 2;
      dfs(adj[i][j]);
    }
  }
}
int main() {
  long long int n, i;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &bf[i]);
    scanf("%lld", &gf[i]);
    adj[bf[i]].push_back(gf[i]);
    adj[gf[i]].push_back(bf[i]);
    adj[2 * i].push_back(2 * i - 1);
    adj[2 * i - 1].push_back(2 * i);
  }
  for (i = 1; i <= 2 * n; i += 2) {
    if (!visit[i]) {
      ans[i] = 0;
      dfs(i);
    }
  }
  for (i = 1; i <= n; i++) {
    printf("%lld ", ans[bf[i]] + 1);
    printf("%lld ", ans[gf[i]] + 1);
    printf("\n");
    ;
  }
  return 0;
}
