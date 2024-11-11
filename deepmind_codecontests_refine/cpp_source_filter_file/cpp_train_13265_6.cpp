#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n, snt, C[505][14505];
map<int, int> F;
void tinh(int n) {
  for (int i = 2; i <= n / i; ++i)
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
        F[i]++;
      }
    }
  if (n > 1) F[n]++;
}
void init() {
  C[0][0] = 1;
  for (int i = 1; i <= 29 * n; ++i) {
    if (i == 1012) {
      bool x = true;
    }
    C[0][i] = 1;
    for (int j = 1; j <= min(i / 2, 500); ++j)
      C[j][i] = (C[j - 1][i - 1] + C[j][i - 1]) % MOD;
    for (int j = i / 2 + 1; j <= min(i, 500); ++j) C[j][i] = C[i - j][i];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    tinh(x);
  }
  init();
  long long res = 1;
  for (map<int, int>::iterator it = F.begin(); it != F.end(); ++it) {
    int x = it->second;
    res = res * C[n - 1][n + it->second - 1] % MOD;
  }
  cout << res << endl;
  return 0;
}
