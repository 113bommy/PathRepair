#include <bits/stdc++.h>
using namespace std;
struct edge {
  int a, b, le, ri;
};
int N, M;
edge E[(3 * 1000) + 5];
bool active[(3 * 1000) + 5];
bool vis[1000 + 5];
vector<int> G[1000 + 5];
void DFS(int node) {
  vis[node] = true;
  for (auto it : G[node]) {
    if (active[it]) {
      int nxt = E[it].a ^ E[it].b ^ node;
      if (!vis[nxt]) {
        DFS(nxt);
      }
    }
  }
}
bool check(int X) {
  for (int i = 1; i <= M; i++) {
    memset(active, false, sizeof(active));
    for (int j = 1; j <= M; j++) {
      if (E[j].le <= E[i].le && E[j].ri >= E[i].le + X - 1) {
        active[j] = true;
      }
    }
    memset(vis, false, sizeof(vis));
    DFS(1);
    if (vis[N]) {
      return true;
    }
  }
  return false;
}
int main() {
  cin >> N >> M;
  int mx = 0;
  for (int i = 1; i <= M; i++) {
    cin >> E[i].a >> E[i].b >> E[i].le >> E[i].ri;
    G[E[i].a].push_back(i);
    G[E[i].b].push_back(i);
    mx = max(mx, E[i].ri - E[i].le + 1);
  }
  int ans = 0;
  for (int le = 1, ri = 1e6; le <= ri;) {
    int mid = (le + ri) / 2;
    if (check(mid)) {
      ans = mid;
      le = mid + 1;
    } else {
      ri = mid - 1;
    }
  }
  if (ans == 0) {
    cout << "Nice work, Dima!\n";
  } else {
    cout << ans << "\n";
  }
  return 0;
}
