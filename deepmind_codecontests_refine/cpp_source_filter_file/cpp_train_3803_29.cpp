#include <bits/stdc++.h>
using namespace std;
const int N = 123;
const int N2 = 1e5 + 123;
const int inf = 1e9 + 7;
const long long INF = 1e18 + 7;
int n, m, q;
int a[N][N], r[N2], c[N2], x[N2], t[N2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> q;
  for (int i = 0; i < q; i++) {
    cin >> t[i];
    if (t[i] == 1) {
      cin >> r[i];
      c[i] = -1;
    } else if (t[i] == 2) {
      cin >> c[i];
      r[i] = -1;
    } else {
      cin >> r[i] >> c[i] >> x[i];
    }
  }
  for (int i = q - 1; i >= 0; i--) {
    if (t[i] == 1) {
      int temp = a[r[i]][m];
      for (int j = m; j >= 1; j--) {
        a[r[i]][j] = a[r[i]][j - 1];
      }
      a[r[i]][1] = temp;
    } else if (t[i] == 2) {
      int temp = a[1][c[i]];
      for (int j = 1; j < n; j++) {
        a[j][c[i]] = a[j + 1][c[i]];
      }
      a[n][c[i]] = temp;
    } else {
      a[r[i]][c[i]] = x[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}
