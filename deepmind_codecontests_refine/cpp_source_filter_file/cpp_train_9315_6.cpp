#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10, Mod = 998244353;
int n, m;
pair<int, int> st, en;
char a[N][N];
bool vis[N][N] = {};
int nei(int r, int c) {
  int res = 0;
  for (int dx = -1; dx <= 1; dx++) {
    if (dx == 0) continue;
    int r1 = r + dx, c1 = c + dx;
    if (r1 >= 1 && r1 <= n) {
      if (a[r1][c] == '.') res++;
    }
    if (c1 >= 1 && c1 <= m) {
      if (a[r][c1] == '.') res++;
    }
  }
  return res;
}
bool nebo(pair<int, int> a, pair<int, int> b) {
  int r = a.first, c = a.second;
  for (int dx = -1; dx <= 1; dx++) {
    if (dx == 0) continue;
    int r1 = r + dx, c1 = c + dx;
    if (r1 >= 1 && r1 <= n) {
      if (make_pair(r1, c) == b) return 1;
    }
    if (c1 >= 1 && c1 <= m) {
      if (make_pair(r, c1) == b) return 1;
    }
  }
  return 0;
}
void dfs(int r, int c) {
  vis[r][c] = 1;
  for (int dx = -1; dx <= 1; dx++) {
    if (dx == 0) continue;
    int r1 = r + dx, c1 = c + dx;
    if (r1 >= 1 && r1 <= n) {
      if (!vis[r1][c]) dfs(r1, c);
    }
    if (c1 >= 1 && c1 <= m) {
      if (!vis[r][c1]) dfs(r, c1);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j], vis[i][j] = (a[i][j] == 'X');
  cin >> st.first >> st.second >> en.first >> en.second;
  vis[st.first][st.second] = vis[en.first][en.second] = 0;
  int ne1 = nei(st.first, st.second), ne2 = nei(en.first, en.second);
  if (st == en)
    if (ne1)
      return cout << "YES", 0;
    else
      return cout << "NO", 0;
  if (nebo(st, en)) {
    if (a[en.first][en.second] == 'X')
      return cout << "YES", 0;
    else if (ne1)
      return cout << "YES", 0;
    else
      return cout << "NO", 0;
  }
  dfs(st.first, st.second);
  if (!vis[en.first][en.second]) return cout << "NO", 0;
  if (a[en.first][en.second] == 'X') return cout << "YES", 0;
  if (ne2 >= 2) return cout << "YES", 0;
  cout << "NO";
}
