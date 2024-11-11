#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
queue<int> q;
multiset<int> adj[100010];
multiset<int>::iterator it;
void find_path(int u) {
  while (!adj[u].empty()) {
    it = adj[u].begin();
    int v = (*it);
    adj[u].erase(it);
    it = adj[v].find(u);
    adj[v].erase(it);
    find_path(v);
  }
  q.push(u);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].insert(v);
    adj[v].insert(u);
  }
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() % 2 == 1) q.push(i);
  }
  int ans = m;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int v = q.front();
    q.pop();
    adj[u].insert(v);
    adj[v].insert(u);
    ans++;
  }
  if (ans % 2 == 1) {
    ans++;
    adj[1].insert(1);
    adj[1].insert(1);
  }
  for (int i = 1; i <= n; i++) {
    if (adj[i].size()) find_path(i);
  }
  printf("%d\n", ans);
  for (int i = 1; i <= m; i++) {
    int ff = q.front();
    q.pop();
    int gg = q.front();
    if (i % 2 == 0)
      printf("%d %d\n", ff, gg);
    else
      printf("%d %d\n", gg, ff);
  }
  return 0;
}
