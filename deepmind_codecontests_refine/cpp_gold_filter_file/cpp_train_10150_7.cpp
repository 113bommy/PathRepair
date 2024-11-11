#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1E9 + 5;
const long double EPS = (long double)1E-7;
const long long MOD = (long long)1E9 + 7;
int n, m;
char a[505][505];
long long f[5][505][505];
inline char get(int d, int r) {
  int c = d + 2 - r;
  return a[r][c];
}
inline char inverse_get(int d, int ir) {
  int r = n + 1 - ir;
  int c = m + 1 - (d + 2 - ir);
  return a[r][c];
}
inline bool check(int d, int r, int ir) {
  int r1 = r;
  int c1 = d + 2 - r;
  int r2 = n + 1 - ir;
  int c2 = m + 1 - (d + 2 - ir);
  return (r1 <= r2 && c1 <= c2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (m); j++) {
      cin >> a[i][j];
    }
  }
  memset((f), (0), sizeof(f));
  int d = (m + n - 2) / 2;
  int c = 0;
  int max_r = min(d + 1, n);
  for (int i = (1); i <= (max_r); i++) {
    for (int j = (1); j <= (n + 1 - i); j++) {
      f[c][i][j] = get(d, i) == inverse_get(d, j) && check(d, i, j) ? 1 : 0;
    }
  }
  while (d--) {
    c = 1 - c;
    int max_r = min(d + 1, n);
    memset((f[c]), (0), sizeof(f[c]));
    for (int i = (1); i <= (max_r); i++) {
      for (int j = (1); j <= (n + 1 - i); j++) {
        if (get(d, i) == inverse_get(d, j) && check(d, i, j)) {
          for (int di = (0); di <= (1); di++) {
            for (int dj = (0); dj <= (1); dj++) {
              f[c][i][j] += f[1 - c][i + di][j + dj];
              if (f[c][i][j] >= MOD) {
                f[c][i][j] -= MOD;
              }
            }
          }
        }
      }
    }
  }
  cout << f[c][1][1] << endl;
}
