#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9;
const long long INFL = (long long)9e18;
const int MAXINT = ((~0) ^ (1 << 31));
const long long MAXLL = ((~0) ^ ((long long)1 << 63));
template <class T>
inline T pow2(T a) {
  return a * a;
}
template <class T>
inline bool mineq(T& a, T b) {
  return (a > b) ? (a = b, true) : false;
}
template <class T>
inline bool maxeq(T& a, T b) {
  return (a < b) ? (a = b, true) : false;
}
const int maxn = 444;
int tmp[maxn][maxn];
int grid[maxn][maxn], n, m;
int x[maxn], y[maxn];
void solve(int p) {
  memcpy(grid, tmp, sizeof(grid));
  for (int i = 0; i < (int)(m); i++) {
    y[i] = (grid[0][i] == (i < p));
  }
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(m); j++) grid[i][j] ^= y[j];
  if (p != m) {
    for (int i = 1; i < (int)(n); i++)
      for (int j = 0; j < (int)(m - 1); j++)
        if (grid[i][j] != grid[i][j + 1]) return;
    for (int i = 1; i < (int)(n); i++) x[i] = (grid[i][0] ^ 1);
  } else {
    bool f = false;
    for (int i = 1; i < (int)(n); i++) {
      bool zero = 1, one = 1;
      for (int j = 0; j < (int)(m); j++) {
        zero &= grid[i][j] ^ 1;
        one &= grid[i][j];
      }
      if (!zero && !one) {
        if (f) return;
        f = true;
        int r = 0;
        for (int j = 0; j < (int)(m - 1); j++)
          if (grid[i][j] > grid[i][j + 1]) r++;
        if (r > 1) return;
        x[i] = (r == 1);
      }
      if (zero && f) x[i] = 1;
      if (one && !f) x[i] = 1;
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < (int)(n); i++) cout << x[i];
  cout << endl;
  for (int i = 0; i < (int)(m); i++) cout << y[i];
  cout << endl;
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(m); j++) {
      cin >> grid[i][j];
    }
  memcpy(tmp, grid, sizeof(grid));
  for (int i = 0; i < (int)(m + 1); i++) {
  }
  solve(3);
  cout << "NO" << endl;
}
