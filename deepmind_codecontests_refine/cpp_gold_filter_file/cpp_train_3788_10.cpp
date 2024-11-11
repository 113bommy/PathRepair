#include <bits/stdc++.h>
using namespace std;
vector<int> g[111];
int n;
int a[111], x;
int s, f[111];
void dfs(int i) {
  f[i] = s;
  for (int j = 0; j < g[i].size(); j++)
    if (!f[g[i][j]]) dfs(g[i][j]);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (i + x < n) g[i].push_back(i + x), g[i + x].push_back(i);
    if (i - x >= 0) g[i].push_back(i - x), g[i - x].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (f[i] == 0) {
      s++;
      dfs(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (f[a[i]] != f[a[a[i]] - 1]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
