#include <bits/stdc++.h>
using namespace std;
struct QuickRead {
  QuickRead() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
} quickread;
const long long MOD = 1000000007;
long long fact[10000];
long long inv_fact[10000];
void init_fact() {
  fact[0] = 1;
  for (int i = 1; i <= 5000; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  for (int i = 0; i <= 5000; ++i) {
    long long mult = fact[i];
    long long order = MOD - 2;
    inv_fact[i] = 1;
    while (order > 0) {
      if (order & 1) {
        inv_fact[i] *= mult;
        inv_fact[i] %= MOD;
      }
      mult *= mult;
      mult %= MOD;
      order >>= 1;
    }
  }
}
long long comb(long long n, long long k) {
  if (k < 0 || n < 0 || n < k) return 0;
  long long ret = (inv_fact[k] * inv_fact[n - k]) % MOD;
  ret *= fact[n];
  ret %= MOD;
  return ret;
}
int N, M, R;
long long X[2005], Y[2005], B[2005];
int num_contain[2005][2005];
int aggregate_snakes[1001][1001];
inline int distance(int i, int j) {
  return max(abs(X[i] - X[j]), abs(Y[i] - Y[j]));
}
long long solve() {
  for (int i = 0; i < N; ++i) {
    aggregate_snakes[X[i]][Y[i]] = 1;
  }
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 1; j <= 1000; ++j) {
      aggregate_snakes[i][j] +=
          (aggregate_snakes[i - 1][j] + aggregate_snakes[i][j - 1] -
           aggregate_snakes[i - 1][j - 1]);
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int left = max(max(X[i] - R, X[j] - R), 1LL);
      int right = min(min(X[i] + R, X[j] + R), 1000LL);
      int bottom = max(max(Y[i] - R, Y[j] - R), 1LL);
      int up = min(min(Y[i] + R, Y[j] + R), 1000LL);
      if (left > right || bottom > up) continue;
      num_contain[i][j] = aggregate_snakes[right][up] -
                          aggregate_snakes[left - 1][up] -
                          aggregate_snakes[right][bottom - 1] +
                          aggregate_snakes[left - 1][bottom - 1];
    }
  }
  long long square = 0;
  for (int i = 0; i < N; ++i) {
    long long cur_square =
        (comb(N, M) + MOD - comb(N - num_contain[i][i], M)) % MOD;
    square += cur_square * (B[i] * B[i] % MOD);
    square %= MOD;
  }
  long long cross = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      long long cur_cross = comb(N, M) % MOD;
      cur_cross += (MOD - comb(N - num_contain[i][i], M));
      cur_cross += (MOD - comb(N - num_contain[j][j], M));
      cur_cross += comb(
          N - num_contain[i][i] - num_contain[j][j] + num_contain[i][j], M);
      cur_cross %= MOD;
      cross += cur_cross * ((B[i] * B[j] * 2) % MOD);
      cross %= MOD;
    }
  }
  return (square + cross) % MOD;
}
int main() {
  init_fact();
  cin >> N >> M >> R;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i] >> B[i];
  }
  cout << solve() << "\n";
  return 0;
}
