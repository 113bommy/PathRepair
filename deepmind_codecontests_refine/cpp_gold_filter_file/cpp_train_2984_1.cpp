#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10;
vector<int> adj[MAX_N];
bool seen[MAX_N];
int DP[MAX_N];
bool check(int n) {
  while (n) {
    if (n % 10 != 4 && n % 10 != 7) return false;
    n /= 10;
  }
  return true;
}
int dfs(int u) {
  int cnt = 1;
  seen[u] = true;
  for (auto i : adj[u])
    if (!seen[i]) cnt += dfs(i);
  return cnt;
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> w;
  for (int i = 0; i < n; i++)
    if (!seen[i]) w.push_back(dfs(i));
  vector<int> x = {1};
  sort(w.begin(), w.end());
  for (int i = 1; i < ((int)(w).size()); i++) {
    if (w[i] != w[i - 1]) x.push_back(1);
    x.back() += (w[i] == w[i - 1]);
  }
  w.erase(unique(w.begin(), w.end()), w.end());
  int W = n;
  n = ((int)(w).size());
  memset(DP, 127, sizeof DP);
  DP[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; x[i]; j *= 2) {
      j = min(j, x[i]);
      for (int k = W; k >= j * w[i]; k--)
        DP[k] = min(DP[k], j + DP[k - j * w[i]]);
      x[i] -= j;
    }
  }
  int ans = MAX_N;
  for (int i = 1; i < MAX_N; i++)
    if (check(i)) ans = min(ans, DP[i]);
  cout << (ans > W ? -1 : ans - 1) << endl;
  return 0;
}
