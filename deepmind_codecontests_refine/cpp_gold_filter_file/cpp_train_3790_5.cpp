#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, d, candid[maxn];
vector<int> g[maxn];
pair<int, int> dis, dis1;
bool visited[maxn], imp[maxn];
void dfs(int a, int H) {
  visited[a] = 1;
  if (imp[a] && H >= dis.second) {
    dis.first = a;
    dis.second = H;
  }
  for (int i : g[a]) {
    if (!visited[i]) {
      dfs(i, H + 1);
    }
  }
}
void dfs1(int a, int H) {
  visited[a] = 1;
  if (H <= d) {
    candid[a]++;
  }
  if (imp[a] && H >= dis1.second) {
    dis1.first = a;
    dis1.second = H;
  }
  for (int i : g[a]) {
    if (!visited[i]) {
      dfs1(i, H + 1);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> d;
  int in;
  for (int i = 0; i < m; i++) {
    cin >> in;
    imp[in] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(in, 0);
  for (int i = 1; i <= n; i++) {
    visited[i] = 0;
  }
  dfs1(dis.first, 0);
  for (int i = 1; i <= n; i++) {
    visited[i] = 0;
  }
  dfs1(dis1.first, 0);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (candid[i] == 2) {
      cnt++;
    }
  }
  cout << cnt;
}
