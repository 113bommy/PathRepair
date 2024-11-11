#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
long long f[100][100];
int dis[100][100];
int c[N];
long long ans;
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  srand((unsigned)time(NULL));
  cin >> n >> k;
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      cin >> dis[i][j];
    }
  }
  ans = 1e18;
  for (int len = 1; len <= 5000; len++) {
    for (i = 1; i <= n; i++) {
      c[i] = (rand() & 1);
    }
    for (i = 0; i <= k; i++) {
      for (j = 1; j <= n; j++) f[i][j] = 1e18;
    }
    f[0][1] = 0;
    for (i = 1; i <= k; i++) {
      for (j = 1; j <= n; j++) {
        for (int l = 1; l <= n; l++) {
          if (c[l] != c[j]) {
            f[i][j] = min(f[i][j], f[i - 1][l] + dis[l][j]);
          }
        }
      }
    }
    ans = min(ans, f[k][1]);
  }
  cout << ans << endl;
  return 0;
}
