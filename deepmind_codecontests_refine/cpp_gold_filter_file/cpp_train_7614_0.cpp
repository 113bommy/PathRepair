#include <bits/stdc++.h>
using namespace std;
const long long logN = 20;
const long long M = 1000000007;
const long long INF = 1e12;
const long long N = 100005;
const long int maxi = 1000000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, h1, i, j;
  cin >> n >> m >> h1;
  long long a[m];
  for (i = 0; i < m; i++) {
    cin >> a[i];
  }
  long long b[n];
  for (i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long h[n][m], ans[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> h[i][j];
      ans[i][j] = 0;
    }
  }
  for (i = 0; i < m; i++) {
    if (a[i] > 0) {
      for (j = 0; j < n; j++) {
        if (h[j][i] == 1 && a[i] <= b[j]) {
          ans[j][i] = a[i];
          break;
        }
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (b[i] > 0) {
      for (j = 0; j < m; j++) {
        if (h[i][j] == 1 && ans[i][j] == 0 && b[i] <= a[j]) {
          ans[i][j] = b[i];
          break;
        }
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cout << max(ans[i][j], h[i][j]) << " ";
    }
    cout << endl;
  }
}
