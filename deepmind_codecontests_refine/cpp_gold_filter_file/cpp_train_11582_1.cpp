#include <bits/stdc++.h>
using namespace std;
string vow = "aeiou";
int month[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const long double pie = 3.1415926535897932384626;
const long long mod = 1e9 + 7;
void bad() {
  cout << -1;
  cout << "\n";
  ;
  exit(0);
}
vector<vector<char> > v;
int n, m;
void read() {
  cin >> n >> m;
  v = vector<vector<char> >(n + 2, vector<char>(m + 2, 'w'));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      if (c == '#') v[i][j] = 'b';
    }
  }
}
int cnt_all_white_row = 0;
int cnt_all_white_col = 0;
void cnt() {
  for (int i = 1; i <= n; i++) {
    int j = 1;
    for (; j <= m && v[i][j] == 'w'; j++)
      ;
    if (j > m) cnt_all_white_row++;
  }
  for (int j = 1; j <= m; j++) {
    int i = 1;
    for (; i <= n && v[i][j] == 'w'; i++)
      ;
    if (i > n) cnt_all_white_col++;
  }
  if (cnt_all_white_col == 0 && cnt_all_white_row != 0) bad();
  if (cnt_all_white_col != 0 && cnt_all_white_row == 0) bad();
}
void wbw() {
  for (int i = 1; i <= n; i++) {
    int j = 1;
    for (; j <= m && v[i][j] == 'w'; j++)
      ;
    for (; j <= m && v[i][j] == 'b'; j++)
      ;
    for (; j <= m && v[i][j] == 'w'; j++)
      ;
    if (j <= m) bad();
  }
  for (int j = 1; j <= m; j++) {
    int i = 1;
    for (; i <= n && v[i][j] == 'w'; i++)
      ;
    for (; i <= n && v[i][j] == 'b'; i++)
      ;
    for (; i <= n && v[i][j] == 'w'; i++)
      ;
    if (i <= n) bad();
  }
}
void dfs(int x, int y) {
  v[x][y] = 'w';
  for (int k = 0; k < 4; k++) {
    int xx = x + dx[k];
    int yy = y + dy[k];
    if (v[xx][yy] == 'b') dfs(xx, yy);
  }
}
void solve(int test_case) {
  read();
  cnt();
  wbw();
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (v[i][j] == 'b') {
        ans++;
        dfs(i, j);
      }
    }
  }
  cout << ans;
  cout << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
