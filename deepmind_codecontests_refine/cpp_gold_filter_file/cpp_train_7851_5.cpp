#include <bits/stdc++.h>
using namespace std;
long long const mod = 1000000007;
long long c[100101][102], a[100000], p[100001][102], pr[100001];
long long n, m;
void prepareC() {
  for (int i = 0; i <= 100100; i++)
    for (int j = 0; j <= min(i, 100); j++)
      if (i == 0 || j % i == 0) {
        c[i][j] = 1;
      } else {
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
      }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  prepareC();
  for (int i = 0; i < m; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    l--;
    r--;
    p[l][k + 1] += 1;
    for (int j = 1; j <= k + 1; j++) {
      p[r + 1][j] = (p[r + 1][j] - c[k + 1 - j + r - l][k + 1 - j] + mod) % mod;
    }
  }
  for (int i = 101; i >= 1; i--) {
    for (int j = 0; j < n; j++) {
      if (j - 1 < 0) {
        pr[j] = (pr[j] + p[j][i]) % mod;
      } else {
        pr[j] = (pr[j - 1] + p[j][i] + pr[j]) % mod;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << (pr[i] + a[i]) % mod << ' ';
  }
  return 0;
}
