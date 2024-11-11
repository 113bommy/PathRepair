#include <bits/stdc++.h>
const int INF = 2000000005;
const long long BIG_INF = 2000000000000000005;
const int mod = 1000000007;
const int P = 31;
const long double PI = 3.141592653589793238462643;
const double eps = 1e-9;
using namespace std;
vector<pair<int, int> > dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool valid(int x, int y, int n, int m) {
  return x >= 0 && y >= 0 && x < n && y < m;
}
mt19937 rng(1999999973);
const int N = 2050;
string s[N];
int column[N][N], row[N][N], n, m;
vector<int> tc[N][2], tr[N][2];
void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      tc[i][j].resize(N, 0);
      tr[i][j].resize(N, 0);
    }
  }
}
inline void inc(int index, int delta, vector<int> &t) {
  for (; index < N; index |= (index + 1)) {
    t[index] += delta;
    if (t[index] >= mod) t[index] -= mod;
    if (t[index] < 0) t[index] += mod;
  }
}
inline int sum(int r, vector<int> &t) {
  int res = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) {
    res += t[r];
    if (res >= mod) res -= mod;
    if (res < 0) res += mod;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  init();
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  if (s[n - 1][m - 1] == 'R') {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = m - 1; j >= 0; j--) {
      row[i][j] = row[i][j + 1];
      if (s[i][j] == 'R') row[i][j]++;
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = n - 1; i >= 0; i--) {
      column[j][i] = column[j][i + 1];
      if (s[i][j] == 'R') column[j][i]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int dir = 0; dir < 2; dir++) {
        int val = sum(j, tr[i][dir]) + sum(i, tc[j][dir]);
        if (val >= mod) val -= mod;
        if (i == 0 && j == 0 && dir == 0) val++;
        if (i == n - 1 && j == m - 1) {
          ans = (ans + val) % mod;
          continue;
        }
        int colRight = row[i][j + 1], colDown = column[j][i + 1];
        if (s[i][j] == 'R' && dir == 0) colDown++;
        if (s[i][j] == 'R' && dir == 1) colRight++;
        if (colRight >= m - j) continue;
        if (colDown >= n - i) continue;
        if (i == n - 1) {
          if (colRight == 0) ans = (ans + val) % mod;
          continue;
        }
        if (j == m - 1) {
          if (colDown == 0) ans = (ans + val) % mod;
          continue;
        }
        inc(j + 1, val, tr[i + 1][0]);
        inc(m - colRight, -val, tr[i + 1][0]);
        inc(i + 1, val, tc[j + 1][1]);
        inc(n - colDown, -val, tc[j + 1][1]);
      }
    }
  }
  cout << ans;
  return 0;
}
