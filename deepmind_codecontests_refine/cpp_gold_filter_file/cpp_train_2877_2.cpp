#include <bits/stdc++.h>
using namespace std;
long long n, c[10009], p[10009], used[10009], cnt;
vector<int> g[10009];
void dfs(long long v, long long p) {
  if (used[p] != c[v]) {
    used[v] = c[v];
    cnt++;
  } else {
    used[v] = used[p];
  }
  for (int i = 0; i < g[v].size(); i++) {
    long long to = g[v][i];
    if (!used[to]) dfs(to, v);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = 1; i < n; i++) {
    long long x;
    cin >> x;
    g[x].push_back(i + 1);
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  dfs(1, -1);
  cout << cnt;
  return 0;
}
