#include <bits/stdc++.h>
using namespace std;
int d, n;
int a[2000];
vector<int> e[2001];
long long dfs(int r, int p, int m, int id) {
  int i, j;
  long long value = 1;
  for (i = 0; i < e[r].size(); i++) {
    if (e[r][i] != p && a[e[r][i]] - m <= d &&
        (a[e[r][i]] > m || (a[e[r][i]] == m && e[r][i] < id))) {
      value = (value * dfs(e[r][i], r, m, id) + 1) % 1000000007;
    }
  }
  return value;
}
int main() {
  cin >> d >> n;
  int i, j, k;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int u, v;
  for (i = 0; i < n - 1; i++) {
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  long long value = 0;
  for (i = 1; i <= n; i++) {
    value = (value + dfs(i, -1, a[i], i)) % 1000000007;
  }
  cout << value << endl;
  return 0;
}
