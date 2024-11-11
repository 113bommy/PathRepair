#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> edges[300000 + 1];
vector<int> val[300000 + 1];
bool visited[300000 + 1];
int ans[300000 + 1];
int maxi = -1;
int ma = 1;
void dfs(int x) {
  visited[x] = 1;
  map<int, int> h;
  for (auto it = val[x].begin(); it != val[x].end(); it++) {
    if (ans[(*it)] != 0) {
      h[ans[(*it)]]++;
    }
  }
  int j = 1;
  for (auto it = val[x].begin(); it != val[x].end(); it++) {
    while (h[j] == 1) {
      j++;
    }
    if (ans[(*it)] == 0) {
      ans[(*it)] = j;
      h[j] = 1;
    }
  }
  while (h[j] == 1) {
    j++;
  }
  maxi = max(maxi, j - 1);
  for (auto it = edges[x].begin(); it != edges[x].end(); it++) {
    if (!visited[(*it)]) {
      dfs((*it));
    }
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  int x, y, sz;
  for (int i = 1; i < n + 1; i++) {
    cin >> sz;
    for (int j = 0; j < sz; j++) {
      cin >> x;
      val[i].push_back(x);
    }
    if (sz > maxi) {
      ma = i;
      maxi = sz;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  dfs(ma);
  cout << maxi << '\n';
  for (int i = 1; i < m + 1; i++) {
    if (ans[i] == 0) {
      ans[i] = 1;
    }
    cout << ans[i] << " ";
  }
  cout << '\n';
}
