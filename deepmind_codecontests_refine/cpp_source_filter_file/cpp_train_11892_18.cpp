#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, MOD = 1e9 + 7;
long long C[N][N];
void process() {
  for (int i = 1; i < N - 5; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      C[i][j] %= MOD;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  process();
  cout << (C[n - 1][2 * k] * C[m - 1][2 * k]) % MOD << '\n';
  return 0;
}
