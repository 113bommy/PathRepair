#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
const int output_precision = 15;
const bool debug = true;
const long long MOD = 1e9 + 7;
int N, A, B, K, f[5001][5001];
int mod(int a) {
  a %= MOD;
  a += MOD;
  a %= MOD;
  return a;
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(output_precision);
  cout << fixed;
  cout.tie(0);
  cin >> N >> A >> B >> K;
  for (int i = A; i <= N; i++) f[0][i] = 1;
  for (int i = 0; i <= K; i++) {
    for (int(j) = 1, j1234 = N; (j) <= j1234; (j)++)
      if (j != B) {
        int dist = abs(j - B);
        int x = f[i][j] - f[i][j - 1];
        f[i + 1][max(1, j - dist + 1)] =
            mod(f[i + 1][max(1, j - dist + 1)] + x);
        f[i + 1][j] = mod(f[i + 1][j] - x);
        f[i + 1][j + 1] = mod(f[i + 1][j + 1] + x);
        f[i + 1][min(N + 1, j + dist)] =
            mod(f[i + 1][min(N + 1, j + dist)] - x);
      }
    for (int(j) = 1, j1234 = N + 1; (j) <= j1234; (j)++)
      f[i + 1][j] = mod(f[i + 1][j] + f[i + 1][j - 1]);
    for (int(j) = 1, j1234 = N + 1; (j) <= j1234; (j)++)
      f[i + 1][j] = mod(f[i + 1][j] + f[i + 1][j - 1]);
  }
  cout << f[K][N] << '\n';
}
