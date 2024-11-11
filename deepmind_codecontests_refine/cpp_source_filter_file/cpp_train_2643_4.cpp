#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long C[55][55];
int N, K;
int kg_50, kg_100;
long long dp[105][55][55];
long long mod_pow(int a, int b) {
  if (b == 1) return a;
  if (b % 2) {
    long long r = mod_pow(a, b - 1);
    return a * r % MOD;
  } else {
    long long r = mod_pow(a, b / 2);
    return r * r % MOD;
  }
}
long long mod_inv(int a) { return mod_pow(a, MOD - 2); }
int main() {
  C[0][0] = 1;
  for (int i = 1; i <= 50; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = C[i][j - 1] * (i - j + 1) % MOD * mod_inv(j) % MOD;
    }
  }
  istream& in = cin;
  in >> N >> K;
  kg_50 = kg_100 = 0;
  for (int i = 0; i < N; i++) {
    int kg;
    in >> kg;
    if (kg == 50) kg_50++;
    if (kg == 100) kg_100++;
  }
  memset(dp, 0, sizeof(dp));
  dp[0][kg_50][kg_100] = 1;
  for (int c = 0; c <= 100; c++) {
    for (int a50 = 0; a50 <= kg_50; a50++) {
      for (int a100 = 0; a100 <= kg_100; a100++) {
        if (dp[c][a50][a100] == 0) continue;
        long long base = dp[c][a50][a100];
        for (int b50 = 0; b50 <= a50; b50++) {
          for (int b100 = 0; b100 <= a100; b100++) {
            if (b50 == 0 && b100 == 0) continue;
            if (b50 * 50 + b100 * 100 > K) continue;
            long long comb = C[a50][b50] * C[a100][b100] % MOD;
            int n50 = kg_50 - a50 + b50;
            int n100 = kg_100 - a100 + b100;
            dp[c + 1][n50][n100] += base * comb;
            dp[c + 1][n50][n100] %= MOD;
          }
        }
      }
    }
  }
  long long count = -1, comb = 0;
  for (int c = 1; c <= 100; c += 2) {
    if (dp[c][kg_50][kg_100] != 0) {
      count = c;
      comb = dp[c][kg_50][kg_100];
      break;
    }
  }
  cout << count << endl;
  cout << comb << endl;
  return 0;
}
