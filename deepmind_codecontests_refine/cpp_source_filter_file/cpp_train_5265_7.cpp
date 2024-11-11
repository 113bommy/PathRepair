#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 50;
const int mod = 1e9 + 7;
const long long inf = (1ll << 62);
long long bit[maxn][maxn][20];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  memset(bit, 63, sizeof bit);
  for (int i = 0; i < 10; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++)
      if (1 & (j >> i)) cnt++;
    if (cnt > 0) {
      cout << cnt << endl;
      for (int j = 1; j <= n; j++)
        if (1 & (j >> i)) cout << j << " ";
      cout << endl;
      for (int j = 1; j <= n; j++) {
        int a;
        cin >> a;
        bit[i][j][1] = a;
      }
    }
    if (cnt < n) {
      cout << n - cnt << endl;
      for (int j = 1; j <= n; j++)
        if (1 ^ (j >> i)) cout << j << " ";
      cout << endl;
      for (int j = 1; j <= n; j++) {
        int a;
        cin >> a;
        bit[i][j][0] = a;
      }
    }
  }
  cout << -1 << endl;
  for (int i = 1; i <= n; i++) {
    long long x = inf;
    for (int j = 0; j < 10; j++) {
      if (1 & (i >> j))
        x = min(x, bit[j][i][0]);
      else
        x = min(x, bit[j][i][1]);
    }
    cout << x << " ";
  }
  cout << endl;
}
