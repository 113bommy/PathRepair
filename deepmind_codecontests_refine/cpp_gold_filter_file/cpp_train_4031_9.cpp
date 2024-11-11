#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long int vis[200005] = {0};
vector<long long int> v[200005];
vector<set<long long int>> myset(30);
vector<long long int> put;
long long int par[200007] = {0};
long long int parho[100007] = {0};
long long int dis[107] = {0};
long long int sz[205] = {0};
map<pair<long long int, long long int>, long long int> mp;
void dfs(long long int src, long long int pa) {
  vis[src] = 1;
  for (auto child : v[src]) {
    if (vis[child] == 0) {
      parho[src] = 1;
      par[child] = src;
      dfs(child, src);
    }
  }
}
int main() {
  int t = 1;
  while (t--) {
    long long int n, w, ans = 0, i, j, cnt = 0, root = 1, x, y;
    cin >> n;
    for (i = 0; i < n - 1; i++) {
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    for (i = 1; i <= n; i++) {
      if (v[i].size() > 2) {
        root = i;
        cnt++;
      }
    }
    if (cnt > 1) {
      cout << "No" << endl;
      return 0;
    } else {
      cout << "Yes" << endl;
      dfs(root, -1);
      for (i = 1; i <= n; i++) {
        if (parho[i] == 0) {
          ans++;
          put.push_back(i);
        }
      }
      cout << ans << endl;
      for (auto kk : put) cout << root << " " << kk << endl;
    }
  }
  return 0;
}
