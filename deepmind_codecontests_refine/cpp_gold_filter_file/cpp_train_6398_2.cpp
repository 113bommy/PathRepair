#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
char s[N][N];
int n, m;
bool vis[N][N];
int psum[N][N];
int rs, cs;
void dfs(int r, int c) {
  if (r < 0 || r == n || c < 0 || c == m) {
    return;
  }
  if (s[r][c] != 'X' || vis[r][c]) {
    return;
  }
  vis[r][c] = true;
  dfs(r - 1, c);
  dfs(r + 1, c);
  dfs(r, c - 1);
  dfs(r, c + 1);
}
void generate() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      psum[i][j] = s[i][j] == 'X';
      if (i > 0) psum[i][j] += psum[i - 1][j];
      if (j > 0) psum[i][j] += psum[i][j - 1];
      if (i > 0 && j > 0) psum[i][j] -= psum[i - 1][j - 1];
    }
}
int get_sum(int r1, int c1, int r2, int c2) {
  int ret = psum[r2][c2];
  if (r1 > 0) ret -= psum[r1 - 1][c2];
  if (c1 > 0) ret -= psum[r2][c1 - 1];
  if (r1 > 0 && c1 > 0) ret += psum[r1 - 1][c1 - 1];
  return ret;
}
void read() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
}
bool is_valid() {
  int comp = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == 'X' && !vis[i][j]) {
        dfs(i, j);
        comp++;
      }
  if (comp > 1) {
    return false;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == '.') {
        if (i + 1 < n && j + 1 < m && s[i + 1][j] == 'X' &&
            s[i][j + 1] == 'X') {
          return false;
        }
        if (i - 1 >= 0 && j - 1 >= 0 && s[i - 1][j] == 'X' &&
            s[i][j - 1] == 'X') {
          return false;
        }
      }
  return true;
}
int check(int row, int col) {
  if (get_sum(rs, cs, rs + row - 1, cs + col - 1) != row * col) {
    return 2;
  }
  int trs = rs;
  int tcs = cs;
  while (1) {
    if (tcs + col < m && s[trs][tcs + col] == 'X') {
      if (get_sum(trs, tcs + col, trs + row - 1, tcs + col) != row) {
        return -1;
      }
      if (s[trs + row][tcs] == 'X') {
        return -1;
      }
      tcs++;
    } else if (trs + row < n && s[trs + row][tcs] == 'X') {
      if (get_sum(trs + row, tcs, trs + row, tcs + col - 1) != col) {
        return -1;
      }
      if (s[trs][tcs + col] == 'X') {
        return -1;
      }
      trs++;
    } else {
      break;
    }
  }
  if (tcs + col < m && get_sum(trs, tcs + col, trs + row - 1, tcs + col) != 0) {
    return -1;
  }
  if (trs + row < n && get_sum(trs + row, tcs, trs + row, tcs + col - 1) != 0) {
    return -1;
  }
  return 1;
}
int solve() {
  if (!is_valid()) {
    return -1;
  }
  generate();
  rs = -1;
  cs = -1;
  for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--)
      if (s[i][j] == 'X') {
        rs = i;
        cs = j;
      }
  int ret = N * N;
  int it = cs;
  while (it < m && s[rs][it] == 'X') {
    it++;
  }
  for (int i = 1; rs + i - 1 < n; i++) {
    int val = check(i, it - cs);
    if (val == 2) {
      break;
    }
    if (val == 1) {
      ret = min(ret, i * (it - cs));
      break;
    }
  }
  it = rs;
  while (it < n && s[it][cs] == 'X') {
    it++;
  }
  for (int i = 1; cs + i - 1 < m; i++) {
    int val = check(it - rs, i);
    if (val == 2) {
      break;
    }
    if (val == 1) {
      ret = min(ret, i * (it - rs));
      break;
    }
  }
  if (ret == N * N) {
    return -1;
  }
  return ret;
}
int main() {
  read();
  cout << solve() << endl;
  return 0;
}
