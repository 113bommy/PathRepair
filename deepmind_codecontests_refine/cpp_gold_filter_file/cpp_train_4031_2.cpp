#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
struct Node {
  int id, w;
};
vector<int> g[maxn];
vector<Node> gg;
bool vis[maxn];
int dfs(int u) {
  vis[u] = 1;
  for (int i : g[u]) {
    if (!vis[i]) {
      return dfs(i);
    }
  }
  return u;
}
int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(false);
  int n, a, b;
  Node tmp;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int t = 0;
  for (int i = 1; i <= n; ++i) {
    int tt = g[i].size();
    tmp.id = i;
    tmp.w = tt;
    gg.push_back(tmp);
    if (tt > 2) {
      ++t;
    }
    if (t >= 2) {
      break;
    }
  }
  if (t >= 2) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    sort(gg.begin(), gg.end(), [&](Node a, Node b) { return a.w > b.w; });
    tmp = gg[0];
    vis[tmp.id] = 1;
    cout << tmp.w << endl;
    for (int i : g[tmp.id]) {
      cout << tmp.id << " " << dfs(i) << endl;
    }
  }
  return 0;
}
