#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1000 + 10;
int cnt[maxn][maxn], n, m;
string g[maxn];
struct node {
  int i, j, len;
  node(int ii, int jj, int len1) { i = ii, j = jj, len = len1; }
};
vector<node> ans;
int check(int i, int j) {
  if (g[i][j] != '*') return 0;
  if (i == 0 || j == 0 || i == n - 1 || j == m - 1) return 0;
  if (g[i + 1][j] != '*' || g[i - 1][j] != '*' || g[i][j + 1] != '*' ||
      g[i][j - 1] != '*')
    return 0;
  return 1;
}
void solve(int i, int j) {
  int maxx = 1, k = 1, res = 0x3f3f3f3f;
  while (i + k < n && g[i + k][j] == '*') maxx = max(maxx, k), k++;
  res = min(res, maxx), k = 1, maxx = 1;
  while (i - k >= 0 && g[i - k][j] == '*') maxx = max(maxx, k), k++;
  res = min(res, maxx), k = 1, maxx = 1;
  while (j + k < m && g[i][j + k] == '*') maxx = max(maxx, k), k++;
  res = min(res, maxx), k = 1, maxx = 1;
  while (j - k >= 0 && g[i][j - k] == '*') maxx = max(maxx, k), k++;
  res = min(res, maxx), k = 1, maxx = 1;
  for (int l = 0; l <= res; l++) {
    cnt[i + l][j] = 1;
    cnt[i - l][j] = 1;
    cnt[i][j + l] = 1;
    cnt[i][j - l] = 1;
  }
  ans.push_back(node(i, j, res));
}
int main() {
  ios::sync_with_stdio(0);
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (check(i, j)) solve(i, j);
      }
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == '*' && cnt[i][j] == 0) {
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    if (flag)
      cout << "-1\n";
    else {
      cout << ans.size() << "\n";
      for (node a : ans)
        cout << a.i + 1 << " " << a.j + 1 << " " << a.len << "\n";
    }
  }
  return 0;
}
