#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e6 + 100, INF = 1e18, INF2 = -1e18, D = 1e9 + 7;
long long ans[MX];
long long par[10][MX];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 1; i < 10; i++) ans[i] = i;
  for (long long i = 10; i < MX; i++) {
    long long k = i;
    while (k > 10) {
      long long l = 1;
      while (k) {
        l *= (k % 10) + (k % 10 == 0);
        k /= 10;
      }
      k = l;
      if (ans[k]) {
        ans[i] = ans[k];
        break;
      }
    }
  }
  for (long long i = 1; i < 10; i++) {
    for (long long j = 1; j < MX; j++) {
      par[i][j] = par[i][j - 1] + (ans[j] == i);
    }
  }
  long long q;
  cin >> q;
  while (q--) {
    long long l, r, k;
    cin >> l >> r >> k;
    cout << par[k][r] - par[k][l - 1] << endl;
  }
  return 0;
}
