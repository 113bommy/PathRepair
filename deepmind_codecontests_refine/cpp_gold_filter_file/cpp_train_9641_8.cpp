#include <bits/stdc++.h>
using namespace std;
char mp[505];
const int mod = 1e9 + 7;
int n, m;
void work() {
  if (n <= m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mp[n * j + i];
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mp[m * i + j];
      }
    }
    swap(n, m);
  }
}
long long f[260][(1 << 15) + 5][2][2];
void dp() {
  int t = 1 << n;
  f[0][0][0][0] = 1;
  int now = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < t; k++) {
        for (int p = 0; p <= 1; p++) {
          for (int o = 0; o <= 1; o++) {
            if (!f[now][k][p][o]) continue;
            if (mp[now] == 'x') {
              int to;
              if ((1 << (j)) & k)
                to = k ^ (1 << (j));
              else
                to = k;
              f[now + 1][to][0][o] =
                  (f[now + 1][to][0][o] + f[now][k][p][o]) % mod;
            } else {
              int temp1;
              if (j == n - 1) {
                temp1 = 0;
              } else {
                temp1 = p;
              }
              if (k & (1 << (j)) || p)
                f[now + 1][k][temp1][o] =
                    (f[now + 1][k][temp1][o] + f[now][k][p][o]) % mod;
              else if (!o) {
                f[now + 1][k][temp1][1] =
                    (f[now + 1][k][temp1][1] + f[now][k][p][o]) % mod;
              }
              if (j == n - 1)
                temp1 = 0;
              else
                temp1 = 1;
              f[now + 1][k | (1 << (j))][temp1][o] =
                  (f[now + 1][k | (1 << (j))][temp1][o] + f[now][k][p][o]) %
                  mod;
            }
          }
        }
      }
      now++;
    }
  }
  int ans = 0;
  for (int i = 0; i < t; i++) {
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= 1; k++) {
        if (f[now][i][j][k]) ans = (ans + f[now][i][j][k]) % mod;
      }
    }
  }
  printf("%d\n", ans);
}
int main() {
  cin >> n >> m;
  work();
  dp();
}
