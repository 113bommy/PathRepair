#include <bits/stdc++.h>
using namespace std;
long long int n, m;
vector<string> a;
long long int vis[55][55];
void dfs(long long int i, long long int j, char prev, long long int pi,
         long long int pj) {
  if (i >= n || i < 0 || j >= m || j < 0 || a[i][j] != prev) return;
  if (vis[i][j] == 2) return;
  if (vis[i][j] == 1) {
    cout << "Yes";
    exit(0);
  }
  vis[i][j] = 1;
  if (pi != i + 1 || pj != j) dfs(i + 1, j, prev, i, j);
  if (pi != i || pj != j + 1) dfs(i, j + 1, prev, i, j);
  if (pi != i - 1 || pj != j) dfs(i - 1, j, prev, i, j);
  if (pi != i || pj != j - 1) dfs(i, j - 1, prev, i, j);
  vis[i][j] = 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int i, j;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    string s;
    cin >> s;
    a.push_back(s);
  }
  memset(vis, 0, sizeof vis);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (!vis[i][j]) dfs(i, j, a[i][j], -1, -1);
    }
  }
  cout << "No";
  return 0;
}
