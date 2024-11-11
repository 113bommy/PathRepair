#include <bits/stdc++.h>
using namespace std;
const int maxx = 60 + 20;
long long INF = 1e15 + 20;
long long a[maxx][maxx][maxx], b[maxx][maxx][maxx];
int main() {
  ios::sync_with_stdio(false);
  int n, m, r;
  int s, t, x;
  cin >> n >> m >> r;
  for (int t = 0; t < m; t++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[t][i][j];
      }
    }
  }
  for (int t = 0; t < 65; t++) {
    for (int i = 0; i < 65; i++) {
      for (int j = 0; j < 65; j++) {
        b[t][i][j] = INF;
      }
    }
  }
  for (int t = 0; t < m; t++) {
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          a[t][i][j] = min(a[t][i][j], a[t][i][k] + a[t][k][j]);
          b[0][i][j] = min(a[t][i][j], b[0][i][j]);
        }
      }
    }
  }
  for (int t = 1; t < n; t++) {
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          b[t][i][j] = min(b[t][i][j], b[t - 1][i][k] + b[0][k][j]);
        }
      }
    }
  }
  for (int i = 0; i < r; i++) {
    cin >> s >> t >> x;
    if (x >= n) x -= 1;
    cout << b[x][s - 1][t - 1] << "\n";
  }
}
