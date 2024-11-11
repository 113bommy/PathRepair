#include <bits/stdc++.h>
using namespace std;
struct node {
  int u, l, r;
  node() {}
  node(int u, int l, int r) : u(u), l(l), r(r){};
};
vector<node> G[1005];
int L[30010], R[30010], vis[1005], n, m, ans = 0;
int dfs(int now, int left, int right) {
  if (left > right) return 0;
  if (now == n) return 1;
  for (int e = 0; e < G[now].size(); e++) {
    int u = G[now][e].u, l = G[now][e].l, r = G[now][e].r;
    if (!vis[u] && l <= left && right <= r) {
      vis[u] = 1;
      if (dfs(u, left, right)) return 1;
    }
  }
  return 0;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, l, r;
    scanf("%d %d %d %d", &u, &v, &l, &r);
    G[u].push_back(node(v, l, r));
    G[v].push_back(node(u, l, r));
    L[i] = l;
    R[i] = r;
  }
  sort(L + 1, L + 1 + m);
  sort(R + 1, R + 1 + m);
  for (int i = 1; i <= m; i++) {
    int left = 1, right = m;
    while (left <= right) {
      memset(vis, 0, sizeof(vis));
      int mid = (left + right) / 2;
      if (dfs(1, L[i], R[mid])) {
        ans = max(ans, (R[mid] - L[i] + 1));
        left = mid + 1;
      } else
        right = mid - 1;
    }
  }
  if (!ans)
    cout << "Nice work, Dima!" << endl;
  else
    cout << ans;
  return 0;
}
