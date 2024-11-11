#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tpl = tuple<int, int, int>;
using pcc = pair<char, char>;
const int inf = 2e9;
const int mod = 1e9 + 7;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int kr[] = {-1, 1, -2, -2, -1, 1, 2, 2};
int kc[] = {-2, -2, -1, 1, 2, 2, -1, 1};
int dgr[] = {-1, -1, 1, 1};
int dgc[] = {1, -1, -1, 1};
vector<int> adj[100100];
queue<int> ans;
vector<int> node;
vector<int> init(100100), good(100100);
bool vis[100100];
vector<int> final;
void dfs(int u, int odd, int even, int cnt) {
  if (vis[u]) return;
  vis[u] = true;
  int cur;
  if (cnt % 2 == 0)
    cur = (even + init[u]) % 2;
  else
    cur = (odd + init[u]) % 2;
  if (cur != good[u]) {
    final.push_back(u);
    if (cnt % 2 == 0)
      even++;
    else
      odd++;
  }
  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs(v, odd, even, cnt + 1);
    }
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++) cin >> init[i + 1];
  for (int i = 0; i < n; i++) {
    cin >> good[i + 1];
    if (init[i + 1] != good[i + 1]) {
      node.push_back(i + 1);
    }
  }
  dfs(1, 0, 0, 0);
  cout << final.size() << endl;
  for (int x : final) cout << x << endl;
  return 0;
}
