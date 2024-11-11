#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:16000000")
#pragma warning(disable : 4996)
const int inf = 1 << 25;
const double eps = 1e-9;
const int MAXN = 300;
int a[MAXN][MAXN];
int f[MAXN];
const int mod = 1000000007;
const int HOR = 1, VERT = 2, BOTH = 0;
int n, m;
bool colCanBeVert(int col) {
  for (int i = (1); i < (n + 1); ++i)
    if (a[i][col] == HOR) return false;
  return n % 2 == 0;
}
long long memo[MAXN];
long long g(int row, int col) {
  if (row < 0) return 0;
  if (row == 0) return 1;
  long long& ret = memo[row];
  if (ret != -1) return ret;
  ret = 0;
  if (a[row][col] != VERT && a[row][col - 1] != VERT) ret += g(row - 1, col);
  if (a[row][col] != HOR && a[row][col - 1] != HOR && a[row - 1][col] != HOR &&
      a[row - 1][col - 1] != HOR)
    ret += g(row - 2, col);
  ret %= mod;
  return ret;
}
long long h(int row, int col) {
  memset((memo), (-1), sizeof(memo));
  long long ret = g(row, col) % mod;
  if (colCanBeVert(col) && colCanBeVert(col - 1)) --ret;
  ret = (ret + mod) % mod;
  return ret;
}
char dom[3][3];
int getPos() {
  int cnt = 0;
  for (int i = (0); i < (3); ++i)
    for (int j = (0); j < (3); ++j) cnt += dom[i][j] == 'O';
  switch (cnt) {
    case 2:
    case 3:
      return dom[0][2] == 'O' ? VERT : HOR;
    case 6:
      return dom[0][1] == 'O' ? HOR : VERT;
  }
  return BOTH;
}
int main() {
  cin >> n >> m;
  string s;
  cin >> s;
  memset((a), (-1), sizeof(a));
  for (int i = (0); i < (n); ++i) {
    vector<string> x(3);
    for (int j = (0); j < (3); ++j) cin >> x[j];
    for (int j = (0); j < (m); ++j) {
      int j0 = j * 4 + 1;
      for (int k = (0); k < (3); ++k)
        for (int r = (0); r < (3); ++r) dom[k][r] = x[k][j0 + r];
      a[i + 1][j + 1] = getPos();
    }
    cin >> s;
  }
  f[0] = 1;
  for (int j = (1); j < (m + 1); ++j) {
    f[j] = 0;
    if (colCanBeVert(j)) f[j] = f[j - 1];
    if (j <= 1) continue;
    long long X = h(n, j);
    f[j] += f[j - 2] * X % mod;
    f[j] %= mod;
  }
  cout << f[m] << endl;
  return 0;
}
