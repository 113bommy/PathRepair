#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int B = 203;
double dp[210][410];
double P[210];
int A[210];
int main() {
  int n, L, K;
  cin >> n >> L >> K;
  for (int i = 0; i < (n); ++i) {
    cin >> P[i];
    P[i] /= 100;
  }
  for (int i = 0; i < (n); ++i) {
    cin >> A[i];
  }
  dp[0][B + K] = 1;
  for (int i = 0; i < (n); ++i) {
    for (int l = i; l >= 0; --l) {
      for (int s = 0; s < (B * 2 + 1); ++s) {
        dp[l + 1][max(0, min(B * 2, s + A[i]))] += dp[l][s] * P[i];
        dp[l][s] *= 1 - P[i];
      }
    }
  }
  double res = 0;
  for (int l = L; l <= n; ++l) {
    for (int s = B; s <= 2 * B; ++s) {
      res += dp[l][s];
    }
  }
  printf("%.15lf", res);
  return 0;
}
