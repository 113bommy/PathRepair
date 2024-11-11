#include <bits/stdc++.h>
using namespace std;
int cnt;
int tno;
int issafe(int i, int j, int m, int n) {
  if (i >= 0 && j >= 0 && i < m && j < n) return true;
  return false;
}
void dfs(char a[][1005], int vis[][1005], int i, int j, int m, int n) {
  if (vis[i][j]) return;
  vis[i][j] = tno;
  if (issafe(i - 1, j, m, n) && a[i - 1][j] == '.')
    dfs(a, vis, i - 1, j, m, n);
  else if (issafe(i - 1, j, m, n))
    cnt++;
  if (issafe(i + 1, j, m, n) && a[i + 1][j] == '.')
    dfs(a, vis, i + 1, j, m, n);
  else if (issafe(i + 1, j, m, n))
    cnt++;
  if (issafe(i, j - 1, m, n) && a[i][j - 1] == '.')
    dfs(a, vis, i, j - 1, m, n);
  else if (issafe(i, j - 1, m, n))
    cnt++;
  if (issafe(i, j + 1, m, n) && a[i][j + 1] == '.')
    dfs(a, vis, i, j + 1, m, n);
  else if (issafe(i, j + 1, m, n))
    cnt++;
}
int main() {
  int m, n, p, t, q;
  cin >> m >> n >> t;
  char a[1005][1005];
  int vis[1005][1005];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) vis[i][j] = 0;
  tno = 1;
  unordered_map<int, int> mc;
  while (t--) {
    cin >> p >> q;
    cnt = 0;
    if (vis[p - 1][q - 1]) {
      cout << mc[vis[p - 1][q - 1]] << endl;
    } else {
      dfs(a, vis, p - 1, q - 1, m, n);
      cout << cnt << endl;
      mc[tno] = cnt;
    }
    tno++;
  }
  return 0;
}
