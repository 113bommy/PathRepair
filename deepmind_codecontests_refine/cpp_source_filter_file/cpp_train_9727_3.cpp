#include <bits/stdc++.h>
using namespace std;
const int N = 1024;
int MOD;
int c[N][N];
int C(int n, int m) {
  if (n < 0 || n > m) return 0;
  if (n == 0 || n == m) return 1;
  if (c[n][m] != -1)
    return c[n][m];
  else
    return c[n][m] = (C(n, m - 1) + C(n - 1, m - 1)) % MOD;
}
int powR(int a, int b) {
  if (b == 0) return 1;
  if (b == 1) return a % MOD;
  long long r = powR(a, b / 2);
  r = r * r % MOD;
  if (b % 2 == 1) r = r * a % MOD;
  return r;
}
int n, m, K;
int x[N], y[N], v[N];
int mp[N][N];
int main() {
  memset(c, -1, sizeof(c));
  memset(mp, 0, sizeof(mp));
  scanf("%d %d %d", &n, &m, &K);
  for (int i = 0; i < K; i++) scanf("%d %d %d", &x[i], &y[i], &v[i]);
  scanf("%d", &MOD);
  if (n > m) {
    swap(n, m);
    for (int i = 0; i < K; i++) swap(x[i], y[i]);
  }
  if (n % 2 != m % 2) {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i < K; i++) mp[x[i]][y[i]] = v[i];
  int empty = -1;
  for (int i = 0; i < m; i++) {
    bool can = true;
    for (int j = 0; j < n; j++)
      if (mp[j][i] != 0) {
        can = false;
        break;
      }
    if (can) {
      empty = i;
      break;
    }
  }
  long long res = 1;
  for (int i = 0; i < m; i++)
    if (i != empty) {
      int cc = 0, val = 1;
      for (int j = 0; j < n; j++) {
        if (mp[j][i] != 0)
          val *= mp[j][i];
        else
          cc++;
      }
      long long tc = 0;
      for (int j = 0; j <= cc; j++) {
        if (val == 1 && j % 2 == 0) continue;
        if (val == -1 && j % 2 == 1) continue;
        tc = (tc + C(j, cc)) % MOD;
      }
      res = res * tc % MOD;
    }
  cout << res << endl;
  return 0;
}
