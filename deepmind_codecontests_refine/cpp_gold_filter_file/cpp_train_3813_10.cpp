#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[101][101], sum[101][101];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k, scor = 0, change = 0;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      sum[j][i] += sum[j][i - 1] + a[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    int rep = 0, anss = 0, mi = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j][i] == 1) {
        if (sum[i][min(j + k - 1, n)] - sum[i][j - 1] > anss) {
          anss = sum[i][min(j + k - 1, n)] - sum[i][j - 1];
          mi = rep;
        }
        rep++;
      }
    }
    scor += anss;
    change += mi;
  }
  cout << scor << " " << change;
  return 0;
}
