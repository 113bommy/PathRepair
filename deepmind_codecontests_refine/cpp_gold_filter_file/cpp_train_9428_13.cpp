#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200001;
int A[MAXN];
int B[MAXN];
int vis[MAXN];
vector<int> lista[MAXN];
void dfs(int u, int c) {
  vis[u] = c + 1;
  for (int i = 0; i < lista[u].size(); i++) {
    int v = lista[u][i];
    if (!vis[v]) dfs(v, 1 - c);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i] >> B[i];
    lista[A[i]].push_back(B[i]);
    lista[B[i]].push_back(A[i]);
    lista[2 * i].push_back(i * 2 + 1);
    lista[i * 2 + 1].push_back(2 * i);
  }
  for (int i = 1; i <= n + n; i++)
    if (!vis[i]) dfs(i, 0);
  for (int i = 1; i <= n; i++) cout << vis[A[i]] << " " << vis[B[i]] << '\n';
  return 0;
}
