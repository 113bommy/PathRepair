#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[100100];
bitset<100100> init, goal;
vector<int> ans;
int flips[100100][2] = {0};
queue<pair<int, int> > q;
void dfs(int s, int p, int l) {
  if (l == 1) return;
  if (l == 0)
    flips[s][0]++;
  else
    flips[s][1] += flips[p][0];
  for (auto x : adj[s]) {
    if (x == p) continue;
    dfs(x, s, l + 1);
  }
}
void bfs(int s) {
  q.push({s, 0});
  while (!q.empty()) {
    int p = q.front().second, u = q.front().first;
    q.pop();
    flips[u][0] += flips[p][1];
    flips[u][1] += flips[p][0];
    if (goal[u] != (flips[u][0] % 2) ^ init[u]) {
      ans.push_back(u);
      dfs(u, p, 0);
    }
    for (auto x : adj[u]) {
      if (x == p) continue;
      q.push({x, u});
    }
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  int t;
  scanf("%d", &t);
  int a, b;
  for (int i = 0; i < t - 1; i++) {
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int ent;
  for (int i = 1; i < t + 1; i++) {
    scanf("%d", &ent);
    init[i] = 0;
    if (ent == 1) init[i] = 1;
  }
  for (int i = 1; i < t + 1; i++) {
    scanf("%d", &ent);
    goal[i] = 0;
    if (ent == 1) goal[i] = 1;
  }
  bfs(1);
  printf("%d\n", ans.size());
  for (auto x : ans) printf("%d\n", x);
  return 0;
}
