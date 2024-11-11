#include <bits/stdc++.h>
using namespace std;
int costs[1000];
int main() {
  int n, m;
  cin >> n >> m;
  int** c = new int*[n];
  int l[101];
  int r[101];
  int* f = new int[n];
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    f[i] = t;
    l[0] = 0;
    r[0] = 0;
    for (int j = 0; j < t; j++) {
      cin >> costs[j];
      l[j + 1] = l[j] + costs[j];
    }
    for (int j = t - 1; j >= 0; j--) {
      r[t - j] = r[t - j - 1] + costs[j];
    }
    c[i] = new int[t + 1];
    c[i][0] = 0;
    for (int j = 1; j <= t; j++) {
      c[i][j] = 0;
      for (int k = 0; k <= j; k++) {
        c[i][j] = max(c[i][j], l[k] + r[j - k]);
      }
    }
  }
  int** d = new int*[n];
  for (int i = 0; i < n; i++) {
    d[i] = new int[10000];
    d[i][0] = 0;
    for (int j = 0; j <= m; j++) d[i][j] = 0;
  }
  for (int i = 0; i <= f[0]; i++) {
    d[0][i] = c[0][i];
  }
  int h = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= f[i]; j++) {
      for (int k = 0; k <= h; k++) {
        d[i][k + j] = max(d[i][k + j], d[i - 1][k] + c[i][j]);
      }
    }
    h += f[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, d[i][m]);
  }
  cout << ans;
  return 0;
}
