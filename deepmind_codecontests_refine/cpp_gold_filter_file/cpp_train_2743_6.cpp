#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 2;
int ans = 1e9, cnt[N], c[N], n, u, rcnt[N];
vector<int> adj[N];
queue<int> q[4];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) scanf("%d", c + i);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", rcnt + i);
    for (int j = 1; j <= rcnt[i]; ++j) {
      scanf("%d", &u);
      adj[u].push_back(i);
    }
  }
  for (int i = 1; i <= 3; ++i) {
    int head = i, tmp = 0;
    for (int j = 1; j <= n; ++j) {
      cnt[j] = rcnt[j];
      if (!cnt[j]) q[c[j]].push(j);
    }
    while (q[1].size() || q[2].size() || q[3].size()) {
      ++tmp;
      while (q[head].size()) {
        u = q[head].front();
        q[head].pop();
        for (int j = 0; j < adj[u].size(); ++j) {
          cnt[adj[u][j]]--;
          if (!cnt[adj[u][j]]) q[c[adj[u][j]]].push(adj[u][j]);
        }
      }
      if (head == 1)
        head = 2;
      else if (head == 2)
        head = 3;
      else if (head == 3)
        head = 1;
    }
    ans = min(ans, tmp);
  }
  cout << ans + n - 1 << endl;
}
