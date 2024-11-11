#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX(int &a, int b) { return a = max(a, b); }
const int MIN(int &a, int b) { return a = min(a, b); }
int n, parts[500005][2];
void read() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> parts[i][0] >> parts[i][1];
  }
}
vector<pair<int, int> > adj[1 << 20];
vector<int> vis((1 << 20));
void upd(int src) {
  vis[src] = 1;
  for (pair<int, int> x : adj[src]) {
    if (!vis[x.first]) upd(x.first);
  }
}
bool find_eulerian(int mask) {
  for (int i = 0; i < mask + 1; i++) {
    vis[i] = 0;
    adj[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int u = parts[i][0] & mask;
    int v = parts[i][1] & mask;
    adj[u].push_back(make_pair(v, 2 * i));
    adj[v].push_back(make_pair(u, 2 * i + 1));
  }
  int x = 0;
  for (int i = 0; i < mask; i++) {
    if (adj[i].size() % 2) {
      return 0;
    }
    if (!vis[i] && adj[i].size()) {
      ++x;
      upd(i);
    }
  }
  return x == 1;
}
vector<int> ret;
void search(int v, int p) {
  while (adj[v].size()) {
    pair<int, int> x = adj[v].back();
    adj[v].pop_back();
    if (vis[x.second / 2]) continue;
    vis[x.second / 2] = 1;
    search(x.first, x.second);
  }
  if (p != -1) {
    ret.push_back((p ^ 1) + 1);
    ret.push_back(p + 1);
  }
}
void trace(int mask) {
  for (int i = 0; i < n; i++) {
    vis[i] = 0;
  }
  for (int i = 0; i < mask + 1; i++) {
    if (adj[i].size()) {
      search(i, -1);
      break;
    }
  }
  for (int x : ret) {
    cout << x << ' ';
  }
  cout << '\n';
}
void solve() {
  for (int i = 21 - 1; i >= 0; i--) {
    if (find_eulerian((1 << i) - 1)) {
      cout << i << '\n';
      trace((1 << i) - 1);
      break;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    read();
    solve();
  }
}
