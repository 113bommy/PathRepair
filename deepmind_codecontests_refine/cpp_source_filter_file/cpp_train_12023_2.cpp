#include <bits/stdc++.h>
using namespace std;
vector<int> a[200005];
int n, sl;
int DFS(int u, int kt) {
  if (a[u].empty()) return 1;
  int p = 0, q = 1000000000;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (kt)
      p += DFS(v, 1 - kt);
    else
      q = min(u, DFS(v, 1 - kt));
  }
  if (kt) return p;
  return q;
}
int main() {
  cin >> n;
  int u, v;
  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    a[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) sl += a[i].empty();
  cout << sl + 1 - DFS(1, 0) << " ";
  cout << DFS(1, 1) << endl;
}
