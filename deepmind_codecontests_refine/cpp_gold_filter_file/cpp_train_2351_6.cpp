#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > VV(150002);
bool Vis[150002];
long long edge, vertics;
void Dfs(int node) {
  Vis[node] = true;
  vertics++;
  edge += VV[node].size();
  for (int i = 0; i < (int)VV[node].size(); i++) {
    int X = VV[node][i];
    if (!Vis[X]) Dfs(X);
  }
}
int main() {
  ios::sync_with_stdio(0);
  long long n, m, x, y;
  cin >> n >> m;
  for (int i = 0; i < (int)m; i++) {
    cin >> x >> y;
    VV[x].push_back(y);
    VV[y].push_back(x);
  }
  for (int i = 1; i < n + 1; i++) {
    if (!Vis[i]) {
      edge = vertics = 0;
      Dfs(i);
      if (vertics >= 3) {
        if (edge != (vertics * (vertics - 1))) {
          cout << "NO\n";
          return 0;
        }
      }
    }
  }
  cout << "YES\n";
  return 0;
}
