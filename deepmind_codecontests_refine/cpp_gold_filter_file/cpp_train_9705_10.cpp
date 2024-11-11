#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int N = 502;
map<char, int> mp = {{'R', 0}, {'G', 1}, {'Y', 2}, {'B', 3}};
char bfr[N];
int a[N][N];
int n, m;
int dp[4][N][N];
int opt[N][N];
int lg[N];
int t[9][9][N][N];
int query(int x1, int y1, int x2, int y2) {
  if (x1 > x2 or y1 > y2) return 0;
  int kx = lg[x2 - x1 + 1], ky = lg[y2 - y1 + 1];
  return max({t[kx][ky][x1][y1], t[kx][ky][x1][y2 - (1 << ky) + 1],
              t[kx][ky][x2 - (1 << kx) + 1][y1],
              t[kx][ky][x2 - (1 << kx) + 1][y2 - (1 << ky) + 1]});
}
int main(int argc, char const *argv[]) {
  lg[1] = 0;
  for (int i = 2; i < N; i++) {
    lg[i] = lg[i >> 1] + 1;
  }
  int Q;
  scanf("%d %d %d", &n, &m, &Q);
  for (int i = 1; i <= n; i++) {
    scanf("%s", bfr + 1);
    for (int j = 1; j <= m; j++) {
      a[i][j] = mp[bfr[j]];
    }
  }
  {
    for (int i = 1; i <= n; i++) {
      if (a[i][1] == 0) {
        dp[0][i][1] = 1;
      } else {
        dp[0][i][1] = 0;
      }
    }
    for (int i = 1; i <= m; i++) {
      if (a[1][i] == 0) {
        dp[0][1][i] = 1;
      } else {
        dp[0][1][i] = 0;
      }
    }
    for (int i = 2; i <= n; i++) {
      for (int j = 2; j <= m; j++) {
        if (a[i][j] == 0) {
          dp[0][i][j] =
              min({dp[0][i - 1][j], dp[0][i][j - 1], dp[0][i - 1][j - 1]}) + 1;
        }
      }
    }
  }
  {
    for (int i = 1; i <= n; i++) {
      if (a[i][m] == 1) {
        dp[1][i][m] = 1;
      } else {
        dp[1][i][m] = 0;
      }
    }
    for (int i = 1; i <= m; i++) {
      if (a[1][i] == 1) {
        dp[1][1][i] = 1;
      } else {
        dp[1][1][i] = 0;
      }
    }
    for (int i = 2; i <= n; i++) {
      for (int j = m - 1; j >= 1; j--) {
        if (a[i][j] == 1) {
          dp[1][i][j] =
              min({dp[1][i - 1][j], dp[1][i][j + 1], dp[1][i - 1][j + 1]}) + 1;
        }
      }
    }
  }
  {
    for (int i = 1; i <= n; i++) {
      if (a[i][1] == 2) {
        dp[2][i][1] = 1;
      } else {
        dp[2][i][1] = 0;
      }
    }
    for (int i = 1; i <= m; i++) {
      if (a[n][i] == 2) {
        dp[2][n][i] = 1;
      } else {
        dp[2][n][i] = 0;
      }
    }
    for (int i = n - 1; i >= 1; i--) {
      for (int j = 2; j <= m; j++) {
        if (a[i][j] == 2) {
          dp[2][i][j] =
              min({dp[2][i + 1][j], dp[2][i][j - 1], dp[2][i + 1][j - 1]}) + 1;
        }
      }
    }
  }
  {
    for (int i = 1; i <= n; i++) {
      if (a[i][m] == 3) {
        dp[3][i][m] = 1;
      } else {
        dp[3][i][m] = 0;
      }
    }
    for (int i = 1; i <= m; i++) {
      if (a[n][i] == 3) {
        dp[3][n][i] = 1;
      } else {
        dp[3][n][i] = 0;
      }
    }
    for (int i = n - 1; i >= 1; i--) {
      for (int j = m - 1; j >= 1; j--) {
        if (a[i][j] == 3) {
          dp[3][i][j] =
              min({dp[3][i + 1][j], dp[3][i][j + 1], dp[3][i + 1][j + 1]}) + 1;
        }
      }
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      opt[i][j] = min(
          {dp[0][i][j], dp[1][i][j + 1], dp[2][i + 1][j], dp[3][i + 1][j + 1]});
    }
  }
  n--, m--;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      t[0][0][i][j] = opt[i][j];
    }
  }
  for (int p = 1; p < 9; p++) {
    for (int i = 1; i + (1 << p) - 1 <= n; i++) {
      for (int j = 1; j <= m; j++) {
        t[p][0][i][j] =
            max(t[p - 1][0][i][j], t[p - 1][0][i + (1 << (p - 1))][j]);
      }
    }
  }
  for (int q = 1; q < 9; q++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j + (1 << q) - 1 <= m; j++) {
        t[0][q][i][j] =
            max(t[0][q - 1][i][j], t[0][q - 1][i][j + (1 << (q - 1))]);
      }
    }
  }
  for (int p = 1; p < 9; p++) {
    for (int q = 1; q < 9; q++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          t[p][q][i][j] =
              max(t[p - 1][q][i][j], t[p - 1][q][i + (1 << (p - 1))][j]);
        }
      }
    }
  }
  n++, m++;
  while (Q--) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (!query(x1, y1, x2 - 1, y2 - 1)) {
      printf("0\n");
    } else {
      int lo = 1, hi = min((x2 - x1 + 1) / 2, (y2 - y1 + 1) / 2), opt = -1, mid;
      while (lo <= hi) {
        mid = lo + hi >> 1;
        if (query(x1 + mid - 1, y1 + mid - 1, x2 - mid, y2 - mid) >= mid) {
          opt = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      printf("%d\n", 4 * opt * opt);
    }
  }
  return 0;
}
