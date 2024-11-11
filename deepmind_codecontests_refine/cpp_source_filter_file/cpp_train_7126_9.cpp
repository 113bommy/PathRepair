#include <bits/stdc++.h>
using namespace std;
const int INF = 0xFFFFFFF;
int n, A, B;
int s[100005];
map<int, int> mp;
vector<int> G[100005];
vector<int> rG[100005];
vector<int> vec;
int vis[100005] = {0};
int sc[100005] = {0};
void dfs(int u) {
  vis[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    if (!vis[G[u][i]]) {
      dfs(G[u][i]);
    }
  }
  vec.push_back(u);
}
void rdfs(int u, int scn) {
  sc[u] = scn;
  vis[u] = 1;
  for (int i = 0; i < rG[u].size(); i++) {
    if (!vis[rG[u][i]]) {
      rdfs(rG[u][i], scn);
    }
  }
}
bool sat() {
  int scn = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < 2 * n; i++) {
    if (!vis[i]) dfs(i);
  }
  memset(vis, 0, sizeof(vis));
  for (int i = vec.size() - 1; i >= 0; i--) {
    if (!vis[vec[i]]) {
      rdfs(vec[i], scn++);
    }
  }
  for (int i = 0; i < n; i++) {
    if (sc[i] == sc[i * 2 + n]) return false;
  }
  return true;
}
void add_edge(int x, int y) {
  G[x].push_back(y);
  rG[y].push_back(x);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> A >> B;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    mp[s[i]] = i + 1;
  }
  int rev = n;
  int no = 0;
  for (int i = 0; i < n; i++) {
    if (!mp.count(A - s[i]) && !mp.count(B - s[i])) no = 1;
    if (mp.count(A - s[i])) {
      int w = mp[A - s[i]] - 1;
      add_edge(i, w);
      add_edge(w + n, i + n);
    } else {
      add_edge(i + n, i);
    }
    if (mp.count(B - s[i])) {
      int w = mp[B - s[i]] - 1;
      add_edge(w, i);
      add_edge(i + n, w + n);
    } else {
      add_edge(i, i + n);
    }
  }
  if (no) {
    cout << "NO" << endl;
    return 0;
  }
  if (sat()) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      if (sc[i] > sc[i + n])
        cout << "1 ";
      else
        cout << "0 ";
    }
    cout << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
