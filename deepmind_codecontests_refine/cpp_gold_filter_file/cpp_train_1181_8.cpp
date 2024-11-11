#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
template <class T>
double sqrt(T x) {
  return sqrt((double)x);
}
template <class T>
T sqr(T x) {
  return x * x;
}
const double PI = acos(-1.0);
const int INF = 1000000000;
const int MOD = 1000000007;
const int M = INF;
int C[1100][1100];
int memo[10][105];
int main() {
  double TIME_START = clock();
  C[0][0] = 1;
  for (int i = 1; i < 1100; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
  }
  int n;
  cin >> n;
  int a[10];
  for (int i = 0; i < 10; i++) cin >> a[i];
  for (int i = a[9]; i <= n; i++) memo[9][i] = 1;
  for (int i = 8; i >= 0; i--) {
    for (int j = a[i]; j <= n; j++)
      for (int k = 0; j + k <= n; k++)
        memo[i][j + k] =
            (memo[i][j + k] +
             (1ll * memo[i + 1][k] * C[j + k - ((i) ? (0) : (1))][j]) % MOD) %
            MOD;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += memo[0][i];
    ans %= MOD;
  }
  cout << ans;
  fprintf(stderr, "\n\n%.15lf\n\n",
          (double)(clock() - TIME_START) / CLOCKS_PER_SEC);
  return 0;
}
