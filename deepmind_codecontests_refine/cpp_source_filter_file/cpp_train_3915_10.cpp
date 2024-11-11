#include <bits/stdc++.h>
using namespace std;
vector<int> mapp[200010];
bool vis[200010];
int len[2][200010];
int n;
void init() {
  for (int i = 0; i <= n; i++) {
    mapp[i].clear();
  }
  memset(len, 0x3f3f3f3f, sizeof(len));
}
void spfa(int ans, int cnt) {
  memset(vis, false, sizeof(vis));
  queue<int> q;
  q.push(ans);
  vis[ans] = true;
  len[cnt][ans] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < mapp[u].size(); i++) {
      int v = mapp[u][i];
      if (len[cnt][v] > len[cnt][u] + 1) {
        len[cnt][v] = len[cnt][u] + 1;
        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
    }
    vis[u] = false;
  }
}
int main() {
  int a, b;
  int x;
  int ans;
  cin.sync_with_stdio(false);
  while (cin >> n >> x) {
    init();
    for (int i = 1; i < n; i++) {
      cin >> a >> b;
      mapp[a].push_back(b);
      mapp[b].push_back(a);
    }
    spfa(1, 0);
    spfa(x, 1);
    ans = 0;
    for (int i = 1; i <= n; i++) {
      if (len[0][i] >= len[1][i]) {
        ans = max(ans, len[0][i]);
      }
    }
    cout << ans * 2 << endl;
  }
  return 0;
}
