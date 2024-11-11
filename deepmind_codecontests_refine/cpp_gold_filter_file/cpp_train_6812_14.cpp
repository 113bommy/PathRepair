#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[105][105];
int b[105][105][13];
int s[105][105][13];
string f[105];
void comp(int x, int y, int z) {
  if (x != 1) {
    if (s[x][y][z] == -1) {
      cout << 'L';
      comp(x - 1, y - 1, (z + 10 * k - a[x][y]) % k);
    } else {
      cout << 'R';
      comp(x - 1, y + 1, (z + 10 * k - a[x][y]) % k);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  k++;
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
    for (int o = 0; o < m; o++) {
      a[i][o + 1] = f[i][o] - 48;
    }
  }
  for (int i = 1; i <= m; i++) {
    b[1][i][a[1][i] % k] = a[1][i];
    for (int o = 0; o < k; o++) {
      if (o == a[1][i] % k) {
        continue;
      }
      b[1][i][o] = -1;
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int o = 1; o <= m; o++) {
      for (int p = 0; p < k; p++) {
        b[i - 1][0][p] = -1;
        b[i - 1][m + 1][p] = -1;
        if (b[i - 1][o - 1][p] > b[i - 1][o + 1][p]) {
          b[i][o][(p + a[i][o]) % k] = b[i - 1][o - 1][p] + a[i][o];
          s[i][o][(p + a[i][o]) % k] = -1;
        } else {
          b[i][o][(p + a[i][o]) % k] = b[i - 1][o + 1][p] + a[i][o];
          s[i][o][(p + a[i][o]) % k] = +1;
        }
        if (b[i - 1][o - 1][p] == b[i - 1][o + 1][p] &&
            b[i - 1][o - 1][p] == -1) {
          b[i][o][(p + a[i][o]) % k] = -1;
          s[i][o][(p + a[i][o]) % k] = 0;
        }
      }
    }
  }
  int ma = -1;
  for (int i = 1; i <= m; i++) {
    ma = max(ma, b[n][i][0]);
  }
  if (ma == -1) {
    cout << -1;
    return 0;
  }
  cout << ma << endl;
  for (int i = 1; i <= m; i++) {
    if (b[n][i][0] == ma) {
      cout << i << endl;
      comp(n, i, 0);
      return 0;
    }
  }
}
