#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 3;
int emp, lan, k, h, ans, zr;
vector<int> a[maxn], G[maxn];
int visited[maxn];
void dfs(int u) {
  visited[u] = 1;
  for (auto v : G[u])
    if (!visited[v]) dfs(v);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> emp >> lan;
  for (int i = 1; i <= emp; i++) {
    cin >> k;
    if (!k) zr++;
    for (int j = 0; j < k; j++) {
      cin >> h;
      a[h].push_back(i);
    }
  }
  for (int i = 1; i <= lan; i++) {
    for (int j = 0; j < a[i].size(); j++) {
      for (int z = j + 1; z < a[i].size(); z++) {
        G[a[i][j]].push_back(a[i][z]);
        G[a[i][z]].push_back(a[i][j]);
      }
    }
  }
  for (int i = 1; i <= emp; i++) {
    if (!visited[i]) dfs(i), ans++;
  }
  if (zr == emp) return cout << zr, 0;
  cout << ans - 1 + zr << "\n";
  return 0;
}
