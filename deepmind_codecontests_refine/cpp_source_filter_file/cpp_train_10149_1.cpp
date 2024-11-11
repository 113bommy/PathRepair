#include <bits/stdc++.h>
using namespace std;
long long d[2][501][501];
int hib[501];
long long n, b, m;
long long mod;
int main() {
  cin >> n >> m >> b >> mod;
  for (int i = 1; i <= n; i++) cin >> hib[i];
  d[0][0][0] = 1 % mod;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 500; j++) {
      for (int k = 0; k <= 500; k++) {
        d[i % 2][j][k] = 0;
      }
    }
    d[i % 2][0][0] = 1;
    for (int j = 1; j <= 500; j++) {
      for (int k = 0; k <= 500; k++) {
        d[i % 2][j][k] = d[(i - 1) % 2][j][k];
        if (k >= hib[i]) d[i % 2][j][k] += d[i % 2][j - 1][k - hib[i]];
        d[i % 2][j][k] = d[i % 2][j][k] % mod;
      }
    }
  }
  long long valasz = 0;
  for (int i = 1; i <= b; i++) valasz = (valasz + d[n % 2][m][i]) % mod;
  cout << valasz;
}
