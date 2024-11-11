#include <bits/stdc++.h>
using namespace std;
int n, w, b;
const int MOD = 1000000009;
long long c[4005][4005];
int main() {
  for (int i = 0; i < 4005; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        c[i][j] = 1;
      else {
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        if (c[i][j] > MOD) c[i][j] -= MOD;
      }
    }
  }
  scanf("%d%d%d", &n, &w, &b);
  long long ans = 0;
  for (int i = 1; i < n; i++)
    for (int j = 1; i + j < n; j++) {
      int k = n - i - j;
      ans = (ans + c[w - 1][n - j - 1] * c[b - 1][j - 1]) % MOD;
    }
  for (int i = 1; i <= w; i++) ans = ans * i % MOD;
  for (int i = 1; i <= b; i++) ans = ans * i % MOD;
  cout << ans << endl;
  return 0;
}
