#include <bits/stdc++.h>
using namespace std;
int n;
int cont[100005] = {0};
int vis[100005] = {0};
vector<int> G[100005];
int ans = 0;
void BFS() {
  queue<pair<int, int> > cola;
  cola.push(make_pair(0, 1));
  vis[1] = 1;
  while (!cola.empty()) {
    int v = (cola.front()).second;
    int l = (cola.front()).first;
    cont[l]++;
    cola.pop();
    for (int i = 0; i < G[v].size(); i++) {
      int u = G[v][i];
      if (vis[u] == 0) {
        cola.push(make_pair(l + 1, u));
        vis[u] = 1;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int aux;
    cin >> aux;
    G[aux].push_back(i);
  }
  BFS();
  for (int i = 0; i <= 100001; i++) {
    ans += (cont[i] % 2);
  }
  cout << ans << "\n";
  return 0;
}
