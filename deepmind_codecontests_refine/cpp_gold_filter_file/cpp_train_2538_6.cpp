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
const int N = 12, MASK = 2048, P = 1e9 + 7;
int n, m, k;
int field[N][N];
int col[N][N], vis[N];
long long ans;
long long calc(int x, int y) {
  if (x == n) {
    return 1;
  }
  if (y == m) {
    return calc(x + 1, 0);
  }
  col[x][y] = (x ? col[x - 1][y] : 0) | (y ? col[x][y - 1] : 0);
  int& mask = col[x][y];
  int used = 0;
  for (int i = 1; i <= k; i++) {
    if (mask >> i & 1) used++;
  }
  if (((n - x) + (m - y) - 1) > (k - used)) return 0;
  if (field[x][y]) {
    if (mask >> field[x][y] & 1) return 0;
    mask ^= 1 << field[x][y];
    long long r = calc(x, y + 1);
    mask ^= 1 << field[x][y];
    return r;
  } else {
    long long lazy = -1;
    long long r = 0;
    for (int num = 1; num <= k; num++) {
      if (mask >> num & 1) continue;
      mask ^= 1 << num, vis[num]++;
      if (vis[num] == 1) {
        if (lazy == -1) {
          lazy = calc(x, y + 1);
        }
        r += lazy;
      } else {
        r += calc(x, y + 1);
      }
      mask ^= 1 << num, vis[num]--;
    }
    return r;
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
    for (int j = 0; j < m; j++) {
      cin >> field[i][j];
      if (field[i][j]) vis[field[i][j]]++;
    }
  }
  cout << calc(0, 0) % P << endl;
  return 0;
}
