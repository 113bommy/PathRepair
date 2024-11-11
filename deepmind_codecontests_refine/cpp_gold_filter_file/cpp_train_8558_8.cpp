#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios::sync_with_stdio(NULL);
  cout.tie(NULL);
  cin.tie(NULL);
}
const double pi = 2 * acos(0.0);
const long long oo = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int nn = 2e5 + 15;
int dx[8] = {-1, 0, 0, 1, 1, -1, 1, -1};
int dy[8] = {0, -1, 1, 0, 1, -1, -1, 1};
vector<int> gr[nn];
int n;
int node;
int mx = 0;
int vis[nn];
vector<int> treeNodes;
int ans;
map<int, int> parents;
map<int, int> can;
void DFS(int u, int dist) {
  if (dist > mx) {
    mx = dist;
    node = u;
  }
  vis[u]++;
  for (auto it : gr[u]) {
    if (!vis[it]) {
      parents[it] = u;
      DFS(it, dist + 1);
    }
  }
}
void BFS() {
  queue<pair<int, int> > qq;
  for (auto it : treeNodes) {
    can[it]++;
    qq.push(make_pair(it, 0));
  }
  while (!qq.empty()) {
    pair<int, int> cur = qq.front();
    qq.pop();
    for (auto it : gr[cur.first]) {
      if (vis[it] == -1) {
        vis[it] = cur.second + 1;
        qq.push(make_pair(it, cur.second + 1));
      }
    }
  }
  mx = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] > mx && !can[i]) {
      mx = max(vis[i], mx);
      node = i;
    }
  }
  ans += (mx);
}
int main() {
  fast();
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int l, r;
    cin >> l >> r;
    gr[l].push_back(r);
    gr[r].push_back(l);
  }
  int a, b, c;
  for (int i = 1; i <= n; i++) {
    if (((int)((gr[i]).size()))) {
      a = i;
      break;
    }
  }
  DFS(a, 0);
  b = node;
  mx = 0;
  memset(vis, 0, sizeof vis);
  parents.clear();
  DFS(b, 0);
  c = node;
  int x = c;
  while (parents[x] != b) {
    treeNodes.push_back(x);
    x = parents[x];
  }
  treeNodes.push_back(b);
  treeNodes.push_back(x);
  if (mx == n - 1) {
    cout << n - 1 << "\n";
    vector<int> res;
    res.push_back(b);
    res.push_back(c);
    for (int i = 1; i <= n; i++) {
      if (((int)((gr[i]).size())) && i != b && i != c) {
        res.push_back(i);
        break;
      }
    }
    for (auto it : res) cout << it << " ";
    cout << "\n";
  } else {
    ans += (mx);
    memset(vis, -1, sizeof(vis));
    BFS();
    cout << ans << "\n";
    cout << b << " " << c << " " << node << "\n";
  }
  return 0;
}
