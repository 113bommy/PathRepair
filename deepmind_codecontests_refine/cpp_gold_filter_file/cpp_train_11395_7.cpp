#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int v[n][m];
  int u = n * m;
  if ((n * m) % 2 == 0) {
    u--;
  }
  if (n > m) {
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        v[i][j] = u;
        u -= 2;
        if (u <= 0) {
          u = n * m;
          if ((n * m) % 2) {
            u--;
          }
        }
      }
    }
  } else {
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) {
        v[j][i] = u;
        u -= 2;
        if (u <= 0) {
          u = n * m;
          if ((n * m) % 2) {
            u--;
          }
        }
      }
    }
  }
  vector<int> v1{-1, +1, 0, 0};
  vector<int> v2{0, 0, -1, +1};
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      for (long long xx = 0; xx < 4; xx++) {
        if ((i + v1[xx]) < n && (i + v1[xx]) >= 0 && (j + v2[xx]) < m &&
            (j + v2[xx] >= 0)) {
          int com = (v[i + v1[xx]][j + v2[xx]] - v[i][j]);
          if (com <= 1 && com >= -1) {
            cout << -1 << endl;
            return 0;
          }
        }
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}
