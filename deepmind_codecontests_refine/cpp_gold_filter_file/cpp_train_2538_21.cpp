#include <bits/stdc++.h>
using namespace std;
inline void EnableFileIO(const string& fileName) {
  if (fileName.empty()) return;
  freopen((fileName + ".in").c_str(), "r", stdin);
  freopen((fileName + ".out").c_str(), "w", stdout);
  return;
}
const int INF = (1 << 30) - 1;
const long long LINF = (1LL << 61) - 1;
const double EPS = 1e-10;
const int N = 20, P = 1e9 + 7;
int n, m, k;
int field[N][N], vis[N][N][N];
int fix[N], rev[N];
long long ans = 0;
inline long long C(int n, int m) {
  long long res = 1;
  for (int i = n; i > n - m; i--) {
    res *= i, res %= P;
  }
  return res;
}
void dfs(int x, int y, int mxc) {
  if (x == n) {
    for (int i = 1; i <= mxc; i++) {
      for (int j = i + 1; j <= mxc; j++) {
        if (fix[i] && fix[j] && fix[i] == fix[j]) return;
      }
    }
    int fixn = 0;
    for (int i = 1; i <= mxc; i++) {
      if (fix[i]) fixn++;
    }
    ans += C(k - fixn, mxc - fixn);
    return;
  }
  if (y == m) {
    dfs(x + 1, 0, mxc);
    return;
  }
  for (int col = 1; col <= min(mxc + 1, k); col++) {
    if (vis[x][y][col]) continue;
    for (int i = x; i < n; i++) {
      for (int j = y; j < m; j++) vis[i][j][col]++;
    }
    bool can = true;
    if (field[x][y]) {
      if (fix[col] && fix[col] != field[x][y]) {
        can = false;
      }
    }
    if (can) {
      bool first = false;
      if (!fix[col]) {
        fix[col] = field[x][y];
        first = true;
      }
      dfs(x, y + 1, max(mxc, col));
      if (first) {
        fix[col] = 0;
      }
    }
    for (int i = x; i < n; i++) {
      for (int j = y; j < m; j++) vis[i][j][col]--;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  EnableFileIO("");
  cin >> n >> m >> k;
  if (n + m - 1 > k) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> field[i][j];
  }
  dfs(0, 0, 0);
  cout << ans % P << endl;
  return 0;
}
