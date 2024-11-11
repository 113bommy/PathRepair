#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <typename T>
using lim = numeric_limits<T>;
template <typename T>
istream& operator>>(istream& is, vector<T>& a) {
  for (T& x : a) {
    is >> x;
  }
  return is;
}
template <typename T>
struct grid : public vector<vector<T>> {
  int n, m;
  grid(int n, int m) : vector<vector<T>>(n, vector<T>(m)), n(n), m(m) {}
  grid(int n, int m, T zero)
      : vector<vector<T>>(n, vector<T>(m, zero)), n(n), m(m) {}
  grid(const grid& a) : vector<vector<T>>(a), n(a.n), m(a.m) {}
};
const int N = 100, K = 7, INF = 1000 * N * N;
int a[N + 1][N + 1], x[K], y[K], opt[1 << K][N + 1][N + 1],
    pred_mask[1 << K][N + 1][N + 1], pred_i[1 << K][N + 1][N + 1],
    pred_j[1 << K][N + 1][N + 1];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  grid<grid<int>> d(n + 1, m + 1, grid<int>(n + 1, m + 1));
  grid<grid<int>> through_i(n + 1, m + 1, grid<int>(n + 1, m + 1));
  grid<grid<int>> through_j(n + 1, m + 1, grid<int>(n + 1, m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int ii = 1; ii <= n; ii++) {
        for (int jj = 1; jj <= m; jj++) {
          d[i][j][ii][jj] = INF;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      d[i][j][i][j] = a[i][j];
      for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
          int ni = i + di, nj = j + dj;
          if (abs(di) + abs(dj) == 1 and 1 <= ni and ni <= n and 1 <= nj and
              nj <= m) {
            d[i][j][ni][nj] = a[i][j] + a[ni][nj];
          }
        }
      }
    }
  }
  for (int i = 0; i < k; i++) {
    cin >> x[i] >> y[i];
  }
  for (int kx = 1; kx <= n; kx++) {
    for (int ky = 1; ky <= m; ky++) {
      for (int ix = 1; ix <= n; ix++) {
        for (int iy = 1; iy <= m; iy++) {
          for (int jx = 1; jx <= n; jx++) {
            for (int jy = 1; jy <= m; jy++) {
              if (d[ix][iy][jx][jy] >
                  d[ix][iy][kx][ky] + d[kx][ky][jx][jy] - a[kx][ky]) {
                d[ix][iy][jx][jy] =
                    d[ix][iy][kx][ky] + d[kx][ky][jx][jy] - a[kx][ky];
                through_i[ix][iy][jx][jy] = kx;
                through_j[ix][iy][jx][jy] = ky;
              }
            }
          }
        }
      }
    }
  }
  for (int mask = 1; mask < 1 << k; mask++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (__builtin_popcount(mask) == 1) {
          opt[mask][i][j] =
              d[x[__builtin_ctz(mask)]][y[__builtin_ctz(mask)]][i][j];
        } else {
          opt[mask][i][j] = lim<int>::max();
          for (int x = (mask - 1) & mask; x > 0; x = (x - 1) & mask) {
            for (int ii = 1; ii <= n; ii++) {
              for (int jj = 1; jj <= m; jj++) {
                if (opt[mask][i][j] > opt[x][ii][jj] + opt[mask ^ x][ii][jj] +
                                          d[ii][jj][i][j] - 2 * a[ii][jj]) {
                  opt[mask][i][j] = opt[x][ii][jj] + opt[mask ^ x][ii][jj] +
                                    d[ii][jj][i][j] - 2 * a[ii][jj];
                  pred_mask[mask][i][j] = x, pred_i[mask][i][j] = i,
                  pred_j[mask][i][j] = j;
                }
              }
            }
          }
        }
      }
    }
  }
  int ans = lim<int>::max(), opt_i = 0, opt_j = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (ans > opt[(1 << k) - 1][i][j]) {
        ans = opt[(1 << k) - 1][i][j];
        opt_i = i, opt_j = j;
      }
    }
  }
  function<void(int, int, int, int)> mark_path = [&](int i, int j, int ii,
                                                     int jj) {
    if (abs(ii - i) + abs(jj - j) <= 1) {
      a[i][j] = a[ii][jj] = 0;
    } else {
      mark_path(i, j, through_i[i][j][ii][jj], through_j[i][j][ii][jj]);
      mark_path(through_i[i][j][ii][jj], through_j[i][j][ii][jj], ii, jj);
    }
  };
  function<void(int, int, int)> construct_path = [&](int mask, int i, int j) {
    if (__builtin_popcount(mask) == 1) {
      mark_path(x[__builtin_ctz(mask)], y[__builtin_ctz(mask)], i, j);
    } else {
      mark_path(i, j, pred_i[mask][i][j], pred_j[mask][i][j]);
      construct_path(pred_mask[mask][i][j], pred_i[mask][i][j],
                     pred_j[mask][i][j]);
      construct_path(mask ^ pred_mask[mask][i][j], pred_i[mask][i][j],
                     pred_j[mask][i][j]);
    }
  };
  construct_path((1 << k) - 1, opt_i, opt_j);
  cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << (a[i][j] ? '.' : 'X');
    }
    cout << endl;
  }
  return 0;
}
