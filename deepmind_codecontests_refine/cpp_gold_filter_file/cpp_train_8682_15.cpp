#include <bits/stdc++.h>
using namespace std;
int vis[50004], parent[50004];
vector<int> V[50004];
void dfs(int x) {
  vis[x] = 1;
  int n = V[x].size();
  for (int i = 0; i < n; i++) {
    int nodo = V[x][i];
    if (!vis[nodo]) {
      parent[nodo] = x;
      dfs(nodo);
    }
  }
  return;
}
int main() {
  int n, lo, hi, m;
  cin >> n >> lo >> hi;
  int t = 1;
  while (1 && t <= n) {
    cin >> m;
    if (lo == t) {
      V[m].push_back(t + 1);
      V[t + 1].push_back(m);
      t++;
      t++;
    } else {
      V[m].push_back(t);
      V[t].push_back(m);
      t++;
    }
  }
  dfs(hi);
  t = 1;
  for (int i = 1; i <= n; i++) {
    if (t == n + 1) break;
    if (t != hi) {
      cout << parent[i] << " ";
    }
    t++;
  }
  cout << endl;
  return 0;
}
