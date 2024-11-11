#include <bits/stdc++.h>
using namespace std;
long long f[555][555], c[555][555], fact[555];
int main() {
  int n;
  cin >> n;
  int k1 = 0, k2 = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t == 1)
      k1++;
    else
      k2++;
  }
  for (int i = 0; i <= n; i++) c[i][0] = 1;
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 1000000007;
    }
  }
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % 1000000007;
  for (int i = 0; i <= k1; i++) {
    for (int j = 0; j <= k2; j++) {
      if (i == 0)
        f[i][j] = fact[j];
      else {
        f[i][j] = 0;
        for (int x = 0; x <= i - 1 && x <= 1; x++)
          for (int y = 0; y <= j; y++) {
            int ft = f[i - 1 - x][j - y] * c[j][y] % 1000000007;
            if (x == 1) ft = ft * (i - 1) % 1000000007;
            ft = ft * fact[x + y] % 1000000007;
            f[i][j] += ft;
            if (f[i][j] >= 1000000007) f[i][j] -= 1000000007;
          }
      }
    }
  }
  cout << f[k1][k2];
  return 0;
}
