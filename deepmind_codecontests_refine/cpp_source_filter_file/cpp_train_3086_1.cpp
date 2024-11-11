#include <bits/stdc++.h>
using namespace std;
int c[210][210], tree[210][210], sum[210][210];
int main() {
  int n, d, m;
  cin >> n >> d >> m;
  for (int i = 0; i <= n; i++)
    for (int j = c[i][0] = c[i][i] = 1; j < i; j++)
      c[i][j] = ((long long)c[i - 1][j - 1] + c[i - 1][j]) % m;
  tree[1][0] = 1;
  for (int i = 0; i <= d; i++) sum[1][i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++)
      for (int k = 0; k < d; k++) {
        tree[i][k + 1] =
            ((long long)c[i - 2][j - 1] * sum[j][d - 1] % m * tree[i - j][k] +
             tree[i][k + 1]) %
            m;
      }
    for (int j = 1; j <= d; j++)
      sum[i][j] = ((long long)sum[i][j - 1] + tree[i][j]) % m;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= d; j++)
      for (int k = 0; k <= d; k++)
        if (k != 1) {
          ans = ((long long)tree[i][j] * tree[n - i + 1][k] + ans) % m;
        }
  cout << (2LL * n * (n - 1) * ans % m) << endl;
  return 0;
}
