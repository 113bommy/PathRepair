#include <bits/stdc++.h>
using namespace std;
long long n, w, b, x;
const int N = 1e3 + 10;
long long c[N], cost[N];
long long d[N][10004];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> w >> b >> x;
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) cin >> cost[i];
  memset(d, -1, sizeof d);
  for (int i = 0; i < n; i++) {
    d[i][0] = w;
  }
  for (int i = 0; i < c[0] + 1; i++) {
    if (w >= (i * cost[0])) d[0][i] = w - (i * cost[0]);
  }
  for (int i = 1; i < n; i++) {
    for (long long j = 0; j <= 1e4 + 5; j++) {
      for (int jj = 0; jj <= min(c[i], j); jj++) {
        if (d[i - 1][j - jj] != -1 &&
            min(d[i - 1][j - jj] + x, w + (j - jj) * b) >= cost[i] * jj) {
          d[i][j] = max(d[i][j], min(d[i - 1][j - jj] + x, w + (j - jj) * b) -
                                     cost[i] * jj);
        }
      }
    }
  }
  for (int i = 1e4; i > -1; i--) {
    if (d[n - 1][i] != -1) {
      cout << i;
      return 0;
    }
  }
}
