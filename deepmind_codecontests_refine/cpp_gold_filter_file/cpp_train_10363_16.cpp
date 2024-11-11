#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 7;
int n, k;
string s[N];
bool mark[N][N];
int cnt;
int minr, minc, maxr, maxc;
pair<int, int> p[N * N];
int t[N][N];
int col[N][N];
int sz[N * N];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
inline bool valid(int r, int c) {
  return r >= 0 && c >= 0 && r < n && c < n && s[r][c] == '.';
}
void dfs(int r, int c) {
  minr = min(minr, r);
  minc = min(minc, c);
  maxr = max(maxr, r);
  maxc = max(maxc, c);
  mark[r][c] = 1;
  p[cnt++] = {r, c};
  for (int i = 0; i < 4; i++) {
    int R = r + dr[i];
    int C = c + dc[i];
    if (valid(R, C) && !mark[R][C]) dfs(R, C);
  }
}
void handle(int r, int c, int R, int C, int val) {
  if (r >= R) return;
  if (c >= C) return;
  t[r][c] += val;
  t[r][C] -= val;
  t[R][c] -= val;
  t[R][C] += val;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> s[i];
  int com = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (valid(i, j) && !mark[i][j]) {
        minr = maxr = i;
        minc = maxc = j;
        cnt = 0;
        dfs(i, j);
        handle(max(0, maxr - k + 1), max(0, maxc - k + 1), minr + 1, minc + 1,
               -cnt);
        for (int x = 0; x < cnt; x++) {
          int r = p[x].first;
          int c = p[x].second;
          col[r][c] = com;
          handle(max(0, r - k + 1), max(0, c - k + 1), r + 1, c + 1, 1);
        }
        sz[com++] = cnt;
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) t[i][j + 1] += t[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) t[j + 1][i] += t[j][i];
  int ans = 0;
  for (int i = 0; i + k <= n; i++) {
    for (int j = 0; j + k <= n; j++) {
      int out = k * k - t[i][j];
      vector<int> v;
      for (int x = 0; x < k; x++) {
        if (valid(i - 1, j + x)) v.push_back(col[i - 1][j + x]);
        if (valid(i + k, j + x)) v.push_back(col[i + k][j + x]);
        if (valid(i + x, j - 1)) v.push_back(col[i + x][j - 1]);
        if (valid(i + x, j + k)) v.push_back(col[i + x][j + k]);
      }
      sort(v.begin(), v.end());
      v.resize(unique(v.begin(), v.end()) - v.begin());
      for (auto x : v) out += sz[x];
      ans = max(ans, out);
    }
  }
  cout << ans << "\n";
  return 0;
}
