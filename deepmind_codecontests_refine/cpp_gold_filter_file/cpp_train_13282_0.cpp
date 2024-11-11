#include <bits/stdc++.h>
using namespace std;
const int maxN = 3e5 + 11;
queue<int> q;
vector<int> adj[maxN];
int vis[maxN];
int aa[maxN], bb[maxN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k, d;
  cin >> n >> k >> d;
  memset(vis, -1, sizeof(vis));
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    if (vis[x] == -1) q.push(x), vis[x] = x;
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    aa[i] = a;
    bb[i] = b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int y : adj[x]) {
      if (vis[y] == -1) {
        vis[y] = vis[x];
        q.push(y);
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i < n - 1; i++) {
    if (vis[aa[i]] != vis[bb[i]]) ans.push_back(i + 1);
  }
  cout << ans.size() << "\n";
  for (int y : ans) cout << y << " ";
  cout << "\n";
  return 0;
}
