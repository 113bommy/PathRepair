#include <bits/stdc++.h>
using namespace std;
int const maxn = 4009;
int const mod = 1000 * 1000 * 1000 + 9;
int memo[maxn][maxn][2], n, sum;
int main() {
  cin >> n;
  memo[1][1][0] = 1;
  memo[1][0][1] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int w = 0; w < 2; ++w) {
        if (w) {
          memo[i + 1][j][w] += (long long)memo[i][j][w] * (j + 1) % mod;
          if (memo[i + 1][j][w] > mod) {
            memo[i + 1][j][w] -= mod;
          }
          memo[i + 1][j + 1][w] += (long long)memo[i][j][w];
          if (memo[i + 1][j + 1][w] > mod) {
            memo[i + 1][j + 1][w] -= mod;
          }
        } else {
          memo[i + 1][j][1] += memo[i][j][w];
          if (memo[i + 1][j][1] > mod) {
            memo[i + 1][j][1] -= mod;
          }
          memo[i + 1][j][w] += (long long)memo[i][j][w] * (j) % mod;
          if (memo[i + 1][j][w] > mod) {
            memo[i + 1][j][w] -= mod;
          }
          memo[i + 1][j + 1][w] += (long long)memo[i][j][w];
          if (memo[i + 1][j + 1][w] > mod) {
            memo[i + 1][j + 1][w] -= mod;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    sum += memo[n][i][1];
    if (sum > mod) {
      sum -= mod;
    }
  }
  cout << sum;
  return 0;
}
