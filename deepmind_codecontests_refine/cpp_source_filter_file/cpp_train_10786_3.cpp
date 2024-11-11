#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long p2[100005], d[100005], ch[100005], ans;
vector<int> adj[100005];
long long dfs(int cur, int par) {
  d[cur] = 0;
  for (int &nxt : adj[cur])
    if (nxt != par) {
      d[cur] += dfs(nxt, cur);
      ch[cur]++;
    }
  return d[cur] += (ch[cur] != 0);
}
void dfs2(int cur, int par) {
  long long dc = d[cur], dp = d[par];
  if (cur != par) {
    d[par] -= d[cur];
    d[cur] += d[par];
    if (ch[par] == 1 && par == 1) d[cur]--;
    if (ch[cur] == 0) d[cur]++;
  }
  ans = (ans + p2[d[cur]]) % mod;
  for (int &nxt : adj[cur])
    if (nxt != par) dfs2(nxt, cur);
  d[cur] = dc;
  d[par] = dp;
}
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 1, u, v; i < N; i++) {
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 1);
  for (int i = p2[0] = 1; i <= N; i++) p2[i] = (p2[i - 1] << 1);
  dfs2(1, 1);
  printf("%lld\n", ans);
  return 0;
}
