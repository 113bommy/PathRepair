#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 9;
long long C[4010][4010];
long long n, x, y;
long long func(int a, int b) { return C[a - 1][b - 1]; }
int main() {
  cin >> n >> x >> y;
  for (int i = 0; i <= 4005; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == j) {
        C[i][j] = 1;
      } else if (j == 0) {
        C[i][j] = 1;
      } else {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
      }
    }
  }
  long long ans = 0ll;
  for (int i = 1; i < n; i++) {
    for (int j = 1; i + j < n; j++) {
      int k = n - i - j;
      ans = (ans + func(x, i + k) * func(y, j)) % MOD;
    }
  }
  for (int i = 1; i <= x; i++) {
    ans = ans * i % MOD;
  }
  for (int i = 1; i <= y; i++) {
    ans = ans * i % MOD;
  }
  cout << ans;
  return 0;
}
