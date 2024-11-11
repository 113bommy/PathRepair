#include <bits/stdc++.h>
using namespace std;
int mod = 1000000009, inf, DP[2][2][32][32][32], N, H;
int fix(int x) { return min(inf, x); }
int main() {
  cin >> N >> H;
  inf = H + 1;
  DP[0][0][1][1][1] = 1;
  for (int rem = 0; rem < N; rem++) {
    for (int d1 = 0; d1 <= 1; d1++)
      for (int d2 = 1; d2 <= inf; d2++)
        for (int d3 = 1; d3 <= inf; d3++)
          for (int d4 = 1; d4 <= inf; d4++) {
            DP[(rem + 1) & 1][d1][d2][d3][d4] = 0;
          }
    for (int d2 = 1; d2 <= inf; d2++)
      for (int d3 = 1; d3 <= inf; d3++)
        for (int d4 = 1; d4 <= inf; d4++) {
          DP[(rem + 1) & 1][0][fix(d2 + 1)][fix(d3 + 1)][fix(d4 + 1)] +=
              DP[rem & 1][0][d2][d3][d4];
          DP[(rem + 1) & 1][0][fix(d2 + 1)][fix(d3 + 1)][fix(d4 + 1)] %= mod;
          DP[(rem + 1) & 1][d2 == inf ? 1 : 0][2][fix(d3 + 1)][fix(d4 + 1)] +=
              DP[rem & 1][0][d2][d3][d4];
          DP[(rem + 1) & 1][d2 == inf ? 1 : 0][2][fix(d3 + 1)][fix(d4 + 1)] %=
              mod;
          DP[(rem + 1) & 1][d3 == inf ? 1 : 0][fix(d2 + 1)][2][fix(d4 + 1)] +=
              DP[rem & 1][0][d2][d3][d4];
          DP[(rem + 1) & 1][d3 == inf ? 1 : 0][fix(d2 + 1)][2][fix(d4 + 1)] %=
              mod;
          DP[(rem + 1) & 1][d4 == inf ? 1 : 0][fix(d2 + 1)][fix(d3 + 1)][2] +=
              DP[rem & 1][0][d2][d3][d4];
          DP[(rem + 1) & 1][d4 == inf ? 1 : 0][fix(d2 + 1)][fix(d3 + 1)][2] %=
              mod;
          DP[(rem + 1) & 1][1][fix(d2 + 1)][fix(d3 + 1)][fix(d4 + 1)] +=
              DP[rem & 1][1][d2][d3][d4];
          DP[(rem + 1) & 1][1][fix(d2 + 1)][fix(d3 + 1)][fix(d4 + 1)] %= mod;
          DP[(rem + 1) & 1][d2 == inf ? 1 : 0][inf][fix(d3 + 1)][fix(d4 + 1)] +=
              DP[rem & 1][1][d2][d3][d4];
          DP[(rem + 1) & 1][d2 == inf ? 1 : 0][inf][fix(d3 + 1)][fix(d4 + 1)] %=
              mod;
          DP[(rem + 1) & 1][d3 == inf ? 1 : 0][fix(d2 + 1)][inf][fix(d4 + 1)] +=
              DP[rem & 1][1][d2][d3][d4];
          DP[(rem + 1) & 1][d3 == inf ? 1 : 0][fix(d2 + 1)][inf][fix(d4 + 1)] %=
              mod;
          DP[(rem + 1) & 1][d4 == inf ? 1 : 0][fix(d2 + 1)][fix(d3 + 1)][inf] +=
              DP[rem & 1][1][d2][d3][d4];
          DP[(rem + 1) & 1][d4 == inf ? 1 : 0][fix(d2 + 1)][fix(d3 + 1)][inf] %=
              mod;
        }
  }
  int ret = 0;
  for (int d1 = 0; d1 <= 1; d1++)
    for (int d2 = 1; d2 <= inf; d2++)
      for (int d3 = 1; d3 <= inf; d3++)
        for (int d4 = 1; d4 <= inf; d4++) {
          ret = (ret + DP[N & 1][d1][d2][d3][d4]) % mod;
        }
  cout << (ret - DP[N & 1][1][inf][inf][inf] + mod) % mod << endl;
}
