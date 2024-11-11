#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;
const int M = 1e9 + 7;
const int maxn = 1e6 + 10;
vector<int> G[N];
int vis[N], no[N], a[N];
bool cmp(int i, int j) { return no[i] < no[j]; }
int solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    no[a[i]] = i;
  }
  bool f = 1;
  queue<int> q;
  q.push(1);
  vis[1] = 1;
  for (int i = 1; i <= n; i++) {
    int u = a[i];
    if (u != q.front()) {
      f = 0;
      break;
    }
    q.pop();
    sort(G[u].begin(), G[u].end(), cmp);
    for (int v : G[u])
      if (!vis[v]) {
        q.push(v);
        vis[v] = 1;
      }
  }
  printf("%s\n", f ? "Yes" : "No");
  return 0;
}
int main() {
  solve();
  return 0;
}
