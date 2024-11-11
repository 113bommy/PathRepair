#include <bits/stdc++.h>
using namespace std;
const int MAX = 152;
const int MAX2 = 11300;
const int INF = 1e9 + 10;
int a[MAX];
int r[MAX][MAX2];
int t[MAX][MAX2];
int main() {
  int n, k, s;
  cin >> n >> k >> s;
  s = min(s, MAX2 - 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int p = 1; p <= s; p++) {
      r[i][p] = INF;
    }
  }
  for (int q = 1; q <= k; q++) {
    for (int i = 0; i <= n; i++) {
      for (int p = 0; p <= s; p++) {
        t[i][p] = INF;
      }
    }
    for (int i = q; i <= n; i++) {
      for (int p = 0; p <= s; p++) {
        if (p >= i - q)
          t[i][p] = min(r[i - 1][p - (i - q)] + a[i], t[i - 1][p]);
        else
          t[i][p] = t[i - 1][p];
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int p = 0; p <= s; p++) {
        r[i][p] = t[i][p];
      }
    }
  }
  int res = INF;
  for (int p = 0; p <= s; p++) {
    res = min(res, r[n][p]);
  }
  cout << res << "\n";
}
