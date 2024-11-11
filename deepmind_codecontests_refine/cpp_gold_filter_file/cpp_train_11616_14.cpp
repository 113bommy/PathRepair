#include <bits/stdc++.h>
using namespace std;
const long long INF = 9e18;
int N;
long long ans = -INF;
long long C[200005];
bool visited[200005];
vector<int> adj[200005], Ch[200005];
multiset<long long> SA;
void dfs(int x) {
  visited[x] = true;
  for (int i = 0; i < adj[x].size(); i++) {
    if (!visited[adj[x][i]]) {
      Ch[x].push_back(adj[x][i]);
      dfs(adj[x][i]);
      C[x] += C[adj[x][i]];
    }
  }
  SA.insert(C[x]);
}
void dfs2(int x) {
  visited[x] = true;
  SA.erase(SA.find(C[x]));
  for (int i = 0; i < Ch[x].size(); i++) {
    if (!visited[Ch[x][i]]) {
      dfs2(Ch[x][i]);
    }
  }
  if (SA.size() != 0) {
    ans = max(*SA.rbegin() + C[x], ans);
  }
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%I64d", &C[i]);
  }
  for (int i = 1; i < N; i++) {
    int U, V;
    scanf("%d %d", &U, &V);
    adj[U].push_back(V);
    adj[V].push_back(U);
  }
  memset(visited, false, sizeof(visited));
  dfs(1);
  memset(visited, false, sizeof(visited));
  dfs2(1);
  if (ans == -INF)
    printf("Impossible\n");
  else {
    printf("%I64d", ans);
  }
  return 0;
}
