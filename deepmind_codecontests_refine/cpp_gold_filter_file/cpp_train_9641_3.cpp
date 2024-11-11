#include <bits/stdc++.h>
using namespace std;
const int N = 255;
const int mod = 1e9 + 7;
vector<vector<int>> dp[1 << 16][2][2];
int n, m;
bool a[N][N];
bool b[N][N];
int bit(int x) { return (1 << x); }
int getbit(int x, int i) { return (x >> i) & 1; }
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int solve(int mask, bool col, bool emp, int i, int j) {
  if (i == n) return solve(mask, 0, emp, 0, j + 1);
  if (j == m) return 1;
  int &res = dp[mask][col][emp][i][j];
  if (res != -1) return res;
  res = 0;
  if (!a[i][j]) {
    int newmask = mask & ((mask | bit(i)) ^ bit(i));
    return res = solve(newmask, 0, emp, i + 1, j);
  }
  for (int val = 0; val < 2; val++) {
    int cur = val | getbit(mask, i) | col;
    if (cur || (!cur && !emp)) {
      int newmask = mask | (val * bit(i));
      add(res, solve(newmask, col | val, emp | !cur, i + 1, j));
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      a[i][j] = (c == '.');
    }
  if (n > m) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < (m >> 1); j++) swap(a[i][j], a[i][m - j - 1]);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) b[m - j - 1][i] = a[i][j];
    swap(n, m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) a[i][j] = b[i][j];
  }
  for (int i = 0; i < (1 << n); i++)
    for (int col = 0; col < 2; col++)
      for (int emp = 0; emp < 2; emp++)
        dp[i][col][emp].assign(n, vector<int>(m, -1));
  cout << solve(0, 0, 0, 0, 0);
  return 0;
}
