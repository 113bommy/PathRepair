#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long sumSub[200333], modSub[200333][11], modPath[11];
long long ans;
vector<long long> adj[200333];
long long dfs(long long here, long long p) {
  modSub[here][1] = sumSub[here] = 1;
  for (int i = 0; i < adj[here].size(); i++) {
    long long next = adj[here][i];
    if (next == p) continue;
    sumSub[here] += dfs(next, here);
    ans += sumSub[next] * (n - sumSub[next]);
    for (int j = 0; j < k; j++) {
      for (int l = 0; l < k; l++) {
        modPath[(j + l + 1) % k] += modSub[here][j] * modSub[next][l];
      }
    }
    for (int j = 0; j < k; j++)
      modSub[here][j] += modSub[next][(j - 1 + k) % k];
  }
  return sumSub[here];
}
int main() {
  scanf("%lld%lld", &n, &k);
  for (int i = 0; i < n - 1; i++) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, -1);
  for (int i = 1; i < k; i++) ans += (k - i) * modPath[i];
  printf("%lld\n", ans / k);
}
