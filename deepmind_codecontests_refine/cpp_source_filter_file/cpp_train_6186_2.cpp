#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX = 2e3 + 5;
const long long MAX2 = 11;
const long long MOD = 998244353;
const long long MOD2 = 1000005329;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
int n, m, le, ri, mid, ans, z[MAX][MAX], R[MAX][MAX], C[MAX][MAX], a, b, cnt,
    x[MAX][MAX];
char c;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      cin >> c;
      R[i][j] = R[i - 1][j];
      C[i][j] = C[i][j - 1];
      z[i][j] = z[i - 1][j] + z[i][j - 1] - z[i - 1][j - 1];
      if (c == 'w') ++z[i][j], ++cnt, ++R[i][j], ++C[i][j], x[i][j] = 1;
    }
  if (cnt == 1) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) cout << (x[i][j] ? 'w' : '.');
      cout << '\n';
    }
    return 0;
  }
  ans = MOD;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      le = 1, ri = min(i, j) - 1;
      mid = ri;
      while (le <= ri) {
        mid = le + ri >> 1;
        if (z[i][j] - z[i - mid - 1][j] - z[i][j - mid - 1] +
                z[i - mid - 1][j - mid - 1] ==
            cnt) {
          if (C[i][j] - C[i][j - mid - 1] + C[i - mid][j] -
                  C[i - mid][j - mid - 1] + R[i - 1][j] - R[i - mid][j] +
                  R[i - 1][j - mid - 1] - R[i - mid][j - mid - 1] ==
              cnt) {
            if (ans > mid) ans = mid, a = i, b = j;
          }
          ri = mid - 1;
        } else
          le = mid + 1;
      }
    }
  if (ans == MOD) return cout << "-1\n", 0;
  for (int i = a - ans; i <= a; ++i) {
    if (!x[i][b]) x[i][b] = 2;
    if (!x[i][b - ans]) x[i][b - ans] = 2;
  }
  for (int i = b - ans; i <= b; ++i) {
    if (!x[a][i]) x[a][i] = 2;
    if (!x[a - ans][i]) x[a - ans][i] = 2;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!x[i][j])
        cout << '.';
      else if (x[i][j] & 1)
        cout << 'w';
      else
        cout << '+';
    }
    cout << '\n';
  }
  return 0;
}
