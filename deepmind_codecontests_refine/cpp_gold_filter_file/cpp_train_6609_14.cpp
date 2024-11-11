#include <bits/stdc++.h>
using namespace std;
long long f(long long first) {
  if (!first) return 0;
  long long res = 0, i;
  for (i = 1; i <= first && i <= 1000000000000000000LL; res += i, i *= 10)
    if (first == i) return res + 1;
  if (first < 10) return 1;
  if (first - i / 10 >= i / 10) return f(i) - 1;
  return (first - i / 10) + f(i / 10);
}
int main(int argc, char **argv) {
  int N;
  cin >> N;
  vector<pair<long long, long long> > A(N);
  for (int i = (0); i < (N); ++i) cin >> A[i].first >> A[i].second;
  long long V[N];
  for (int i = (0); i < (N); ++i) V[i] = f(A[i].second) - f(A[i].first - 1);
  double DP[N][N + 1];
  memset(DP, 0, sizeof(DP));
  DP[0][1] = 1. * V[0] / (A[0].second - A[0].first + 1);
  DP[0][0] = 1. - DP[0][1];
  for (int i = (1); i < (N); ++i)
    for (int j = (0); j < (N + 1); ++j)
      DP[i][j] +=
          DP[i - 1][j] * (1. - 1. * V[i] / (A[i].second - A[i].first + 1)),
          DP[i][j + 1] +=
          DP[i - 1][j] * (1. * V[i] / (A[i].second - A[i].first + 1));
  int K;
  cin >> K;
  int P = K * N / 100 + ((K * N) % 100 != 0);
  double res = 0;
  for (int i = (P); i < (N + 1); ++i) res += DP[N - 1][i];
  printf("%.15f\n", res);
  return 0;
}
