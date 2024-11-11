#include <bits/stdc++.h>
using namespace std;
double startTime;
double gct() { return ((double)clock() - startTime) / CLOCKS_PER_SEC; }
void suraj();
int main() {
  startTime = (double)clock();
  { suraj(); }
  return 0;
}
const long long MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
void suraj() {
  long long n, m, q;
  cin >> n >> m >> q;
  vector<vector<long long>> free(n + 1, vector<long long>(m + 1, true));
  long long stairs = 0;
  for (long long i = 1; i < n; i++) {
    for (long long j = 1; j < m; j++) {
      if (i == 1) {
        for (long long k = 1;; k++) {
          long long nx = i + k / 2;
          long long ny = j + (k + 1) / 2;
          if (nx > n || ny > m) {
            stairs += ((k - 1) * ((k - 1) + 1)) / 2;
            break;
          }
        }
      }
      if (j == 1) {
        for (long long k = 1;; k++) {
          long long nx = i + (k + 1) / 2;
          long long ny = j + k / 2;
          if (nx > n || ny > m) {
            stairs += ((k - 1) * ((k - 1) + 1)) / 2;
            break;
          }
        }
      }
    }
  }
  stairs += n * m;
  long long currStairs = stairs;
  for (long long i = 0; i < q; i++) {
    long long x, y;
    cin >> x >> y;
    free[x][y] = !free[x][y];
    long long rd = 0;
    for (rd = 1;; rd++) {
      long long nx = x + (rd) / 2;
      long long ny = y + (rd + 1) / 2;
      if (nx > n || ny > m || !free[nx][ny]) break;
    }
    long long tl = 0;
    for (tl = 1;; tl++) {
      long long nx = x - (tl + 1) / 2;
      long long ny = y - tl / 2;
      if (nx < 1 || ny < 1 || !free[nx][ny]) break;
    }
    long long dr = 0;
    for (dr = 1;; dr++) {
      long long nx = x + (dr + 1) / 2;
      long long ny = y + dr / 2;
      if (nx > n || ny > m || !free[nx][ny]) break;
    }
    long long lt = 0;
    for (lt = 1;; lt++) {
      long long nx = x - (lt) / 2;
      long long ny = y - (lt + 1) / 2;
      if (nx < 1 || ny < 1 || !free[nx][ny]) break;
    }
    rd--;
    tl--;
    dr--;
    lt--;
    if (!free[x][y]) {
      currStairs -= ((rd + tl + rd * tl) + (dr + lt + dr * lt) + 1);
    } else {
      currStairs += ((rd + tl + rd * tl) + (dr + lt + dr * lt) + 1);
    }
    cout << currStairs << "\n";
  }
}
