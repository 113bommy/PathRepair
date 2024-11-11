#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  long long a[52] = {}, z = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 49; i >= 0; i--) {
    bool b[52][52] = {}, d[52][52] = {{1}};
    for (int j = 1; j <= n; j++) {
      long long c = 0;
      for (int h = j; h <= n; h++) {
        c += a[h];
        if ((c | (z + (1ll << i))) == c) b[j][h] = 1;
      }
    }
    for (int j = 1; j <= n; j++) {
      for (int h = 1; h <= k; h++) {
        for (int l = 1; l <= j; l++) {
          if (b[l][j]) d[j][h] |= d[l - 1][h - 1];
        }
      }
    }
    if (d[n][k]) z += (1ll << i);
  }
  cout << z;
}
