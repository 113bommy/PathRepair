#include <bits/stdc++.h>
using namespace std;
long long PT[103][103 + 1];
void build_pascal_triangle() {
  PT[0][0] = 1;
  for (int n = 1; n < 103; ++n) {
    PT[n][0] = 1;
    for (int k = 1; k < n; ++k) {
      PT[n][k] = (PT[n - 1][k - 1] + PT[n - 1][k]) % 1000000007;
    }
    PT[n][n] = 1;
  }
}
long long Choose(int n, int k) {
  if (n < 0 || k < 0 || k > n) return 0;
  return PT[n][k];
}
unsigned int powmod(unsigned long long x, unsigned long long n) {
  unsigned long long res = 1;
  x %= 1000000007;
  while (true) {
    if (n & 1) {
      res = (res * x) % 1000000007;
    }
    n >>= 1;
    if (n == 0) break;
    x = (x * x) % 1000000007;
  }
  return (unsigned int)res;
}
long long DP[104][104 * 104];
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build_pascal_triangle();
  int N, K;
  long long M;
  cin >> N >> M >> K;
  for (int k = (0), _b = (min(N, K)); k <= _b; ++k) {
    DP[N][k] = powmod(Choose(N, k), M / N);
  }
  for (int col = N - 1; col >= 1; --col) {
    for (int k = (0), _b = (min(N, K)); k <= _b; ++k) {
      long long col_ways = powmod(Choose(N, k), (M + N - col) / N);
      for (int sumk = (0), _b = (min((N - col) * N, K)); sumk <= _b; ++sumk) {
        if (sumk + k > K) break;
        if (DP[col + 1][sumk] > 0) {
          DP[col][sumk + k] += (col_ways * DP[col + 1][sumk]) % 1000000007;
          DP[col][sumk + k] %= 1000000007;
        }
      }
    }
  }
  cout << DP[1][K] << endl;
  return 0;
}
