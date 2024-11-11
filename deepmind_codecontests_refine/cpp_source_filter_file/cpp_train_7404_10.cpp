#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
bool compare(T x, U y) {
  return (abs(x - y) <= 1e-9);
}
const int MOD = 1e9 + 7;
const int N = 1e3 + 3;
vector<int> adj[N];
vector<int> vis(N);
vector<int> vis1(N);
vector<int> par(N);
vector<int> dist(N);
vector<int> dist1(N);
int diam1 = 0;
void dfs(int s) {
  vector<int> v;
  for (auto x : adj[s]) {
    if (!vis[x]) {
      vis[x] = 1;
      dfs(x);
      dist[s] = max(dist[s], dist[x] + 1);
      v.push_back(dist[x]);
    }
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  if ((int)v.size() > 1)
    diam1 = max(diam1, v[0] + v[1] + 2);
  else if ((int)v.size() == 1)
    diam1 = max(diam1, v[0] + 1);
  else
    diam1 = max(diam1, 1);
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> centre;
  int conn = 1;
  int mx_diam_tree = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      vis[i] = 1;
      queue<int> q;
      q.push(i);
      int end_pnt = i;
      int mx = -1;
      while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (auto x : adj[s]) {
          if (!vis[x]) {
            vis[x] = 1;
            q.push(x);
            dist[x] = dist[s] + 1;
            if (dist[x] > mx) {
              mx = dist[x];
              end_pnt = x;
            }
          }
        }
      }
      vis1[end_pnt] = 1;
      q.push(end_pnt);
      mx = -1;
      int st_pnt = end_pnt;
      while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (auto x : adj[s]) {
          if (!vis1[x]) {
            vis1[x] = 1;
            q.push(x);
            par[x] = s;
            dist1[x] = dist1[s] + 1;
            mx_diam_tree = max(mx_diam_tree, dist1[x]);
            if (dist1[x] > mx) {
              mx = dist1[x];
              st_pnt = x;
            }
          }
        }
      }
      vector<int> diam;
      while (par[st_pnt]) {
        diam.push_back(st_pnt);
        st_pnt = par[st_pnt];
      }
      diam.push_back(st_pnt);
      centre.push_back(diam[(int)diam.size() / 2]);
      if (mx_diam_tree == mx) {
        conn = diam[(int)diam.size() / 2];
      }
    }
  }
  for (auto x : centre) {
    if (x != conn) {
      adj[conn].push_back(x);
      adj[x].push_back(conn);
    }
  }
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
    dist[i] = 0;
  }
  vis[1] = 1;
  dfs(1);
  cout << diam1 << "\n";
  for (auto x : centre)
    if (x != conn) cout << x << " " << conn << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
}
