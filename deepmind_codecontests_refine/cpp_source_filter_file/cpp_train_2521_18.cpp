#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const long long mod = 1000000007;
long long f[maxn][maxn];
int n, m, k;
void init() {
  memset(f, 0, sizeof(f));
  for (int i = 1; i < maxn; i++) f[i][0] = 1;
  for (int i = 1; i < maxn; i++) f[i][1] = i;
  for (int i = 2; i < maxn; i++)
    for (int j = 2; j <= i; j++)
      f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % mod;
}
int main() {
  init();
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    cout << (f[n - 1][2 * k] * f[m - 1][2 * k]) % mod << endl;
  }
  return 0;
}
