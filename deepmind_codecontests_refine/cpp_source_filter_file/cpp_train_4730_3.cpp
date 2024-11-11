#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int INF = 2e9;
const long long INF64 = 1e18;
const long double EPS = 1e-12;
const long double PI = 3.1415926535897932384626433832795028841;
const long long MD = 925262732;
const long long T = 634521;
const int N = 200100;
const int M = 301;
long long c[3000][3000], d[65][1001], ans[62][1001], p[1001];
int main() {
  p[0] = 1;
  for (long long i = 1; i <= 60; i++) p[i] = (p[i - 1] * i) % MOD;
  for (int i = 0; i <= 2000; i++)
    for (int j = 0; j <= i; j++)
      if (j == 0 || j == i)
        c[i][j] = 1;
      else
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
  d[0][0] = 1;
  for (int z = 0; z <= 1000; z++)
    for (int i = 60; i >= 0; i--)
      for (int j = 0; j <= 1000; j++)
        if (j + z <= 1000) d[i + 1][j + z] = (d[i + 1][j + z] + d[i][j]) % MOD;
  for (int i = 1; i <= 60; i++)
    for (int j = 0; j <= 1000; j++)
      for (int u = 0; u <= j; u++)
        if (j - u >= i - 1)
          ans[i][j] = (ans[i][j] + (d[i][u] * c[j - u][i - 1])) % MOD;
  for (int i = 1; i <= 60; i++)
    for (int j = 1; j <= 1000; j++)
      ans[i][j] = (ans[i][j] + ans[i][j - 1]) % MOD;
  int t;
  cin >> t;
  for (int i = 0; i < int(t); i++) {
    int n, k;
    cin >> n >> k;
    if (n > 60) {
      printf("0\n");
      continue;
    }
    n--;
    long long sum = (ans[k][n] * p[k]) % MOD;
    printf("%I64d\n", sum);
  }
  return 0;
}
