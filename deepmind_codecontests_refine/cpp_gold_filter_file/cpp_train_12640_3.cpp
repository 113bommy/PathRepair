#include <bits/stdc++.h>
const int MAX_N = 1e2 + 2;
const int MAX_S = 1e3 + 3;
const long long MOD = 1e9 + 7;
int n;
long long F[MAX_S];
long long C[MAX_S][MAX_S];
bool seen[MAX_N][MAX_S];
long long dp[MAX_N][MAX_S];
std::vector<int> x;
std::vector<int> y;
inline long long mod(const long long& a) { return (a >= MOD) ? (a % MOD) : a; }
inline long long add(const long long& a, const long long& b) {
  return mod(a + b);
}
inline long long mul(const long long& a, const long long& b) {
  return mod(a * b);
}
inline long long fpow(long long b, long long e) {
  long long a;
  a = 1;
  while (e > 0) {
    if (e & 1) {
      a = mul(a, b);
    }
    b = mul(b, b);
    e >>= 1;
  }
  return a;
}
inline long long inv(const long long a) { return fpow(a, MOD - 2); }
inline void fill_F(void) {
  int n;
  F[0] = 1;
  for (n = 1; n < MAX_S; ++n) {
    F[n] = mul(n, F[n - 1]);
  }
}
inline void fill_C(void) {
  int n, k;
  for (n = 0; n < MAX_S; ++n) {
    C[n][n] = C[n][0] = 1;
  }
  for (n = 1; n < MAX_S; ++n) {
    for (k = 1; k < n; ++k) {
      C[n][k] = add(C[n - 1][k], C[n - 1][k - 1]);
    }
  }
}
long long solve(int i, int s) {
  int take;
  long long& answer = dp[i][s];
  if (seen[i][s]++) {
    return answer;
  }
  if (i == n) {
    return answer = (s == 0);
  }
  s += x[i];
  answer = 0;
  for (take = std::min(y[i], s); take >= 0; --take) {
    answer = add(answer, mul(C[s][take], solve(i + 1, s - take)));
  }
  return answer;
}
int main(void) {
  int m, s, i;
  fill_F();
  fill_C();
  std::cin >> n;
  s = 0;
  m = 1;
  x.resize(n);
  for (i = 0; i < n; ++i) {
    std::cin >> x[i];
    m = mul(m, inv(F[x[i]]));
    s += x[i];
  }
  y.resize(n);
  for (i = 0; i < n; ++i) {
    std::cin >> y[i];
  }
  m = mul(m, F[s]);
  std::cout << mul(m, solve(0, 0)) << std::endl;
  return 0;
}
