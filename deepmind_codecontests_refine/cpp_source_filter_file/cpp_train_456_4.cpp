#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int Time, head[maxn], vis[maxn], eid, ans, n, m;
bool success;
set<int> st;
struct Edge {
  int to, x, y, nxt;
} edge[6005];
void addedge(int u, int v, int l, int r) {
  edge[eid].to = v;
  edge[eid].x = l;
  edge[eid].y = r;
  edge[eid].nxt = head[u];
  head[u] = eid++;
}
void dfs(int u, int l, int r) {
  if (success) return;
  if (u == n) {
    success = true;
    return;
  }
  for (int i = head[u]; i != -1; i = edge[i].nxt) {
    int v = edge[i].to;
    if (vis[v] == Time || edge[i].x > l || edge[i].y < r) continue;
    vis[v] = Time;
    dfs(v, l, r);
  }
}
void solve() {
  ans = 0;
  for (set<int>::iterator i = st.begin(); i != st.end(); i++) {
    int now = *i;
    int left = now, right = 1e6 + 1000, mid;
    while (left < right) {
      Time++;
      success = false;
      vis[1] = Time;
      mid = (left + right) / 2;
      dfs(1, now, mid);
      if (success)
        left = mid + 1;
      else
        right = mid;
    }
    ans = max(ans, left - now);
  }
}
int main() {
  Time = 0;
  memset(vis, 0, sizeof(vis));
  while (cin >> n >> m) {
    eid = 0;
    memset(head, -1, sizeof(head));
    st.clear();
    while (m--) {
      int u, v, l, r;
      cin >> u >> v >> l >> r;
      addedge(u, v, l, r);
      addedge(v, u, l, r);
      st.insert(u);
      st.insert(v);
    }
    solve();
    if (ans == 0)
      printf("Nice work, Dima!\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
