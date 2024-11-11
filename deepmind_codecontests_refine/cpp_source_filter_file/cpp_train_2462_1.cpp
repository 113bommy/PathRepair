#include <bits/stdc++.h>
using namespace std;
long long n, p, kedalaman[100010], hasil = 0;
vector<long long> adj[100010];
vector<bool> visited(100010, false);
void dfs(long long u, long long h) {
  if (visited[u]) return;
  visited[u] = true;
  kedalaman[h]++;
  for (long long i = 0; i < adj[u].size(); i++) {
    long long v = adj[u][i];
    dfs(v, h + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cin >> n;
  for (long long i = 1; i <= n - 1; i++) {
    cin >> p;
    adj[i + 1].push_back(p);
    adj[p].push_back(i + 1);
  }
  dfs(1, 1);
  for (long long i = 1; i <= n - 1; i++) {
    if (kedalaman[i] == 0) break;
    hasil += kedalaman[i] % 2;
  }
  cout << hasil << endl;
}
