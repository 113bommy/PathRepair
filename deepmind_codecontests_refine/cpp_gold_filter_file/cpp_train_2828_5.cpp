#include <bits/stdc++.h>
using namespace std;
bool cycle = 0;
vector<int> cc;
int vis[10005];
char c[5001][5001];
vector<int> v[10005];
void dfs(int pos, int pre, int prepos) {
  vis[pos] = 1;
  for (int i = 0; i < v[pos].size(); i++) {
    if (v[pos][i] == prepos) {
      cout << prepos + 1 << " " << pre + 1 << " " << pos + 1 << endl;
      exit(0);
    }
    if (vis[v[pos][i]]) continue;
    dfs(v[pos][i], pos, pre);
  }
}
int main() {
  int n;
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c[i][j];
      if (c[i][j] == '1') {
        v[i].push_back(j);
      }
    }
  }
  for (int i = n; i >= 0; i--) {
    dfs(i, -1, -1);
  }
  cout << -1 << endl;
}
