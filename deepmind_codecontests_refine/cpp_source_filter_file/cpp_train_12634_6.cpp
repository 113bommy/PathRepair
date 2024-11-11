#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
int main() {
  int n;
  cin >> n;
  cout << n - 1 << "\n";
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    adj[v].push_back(u), adj[u].push_back(v);
    cout << 2 << " " << v + 1 << " " << u + 1 << "\n";
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < adj[i].size() - 1; i++)
      cout << adj[i][j] + 1 << " " << adj[i][j + 1] + 1 << "\n";
  }
}
