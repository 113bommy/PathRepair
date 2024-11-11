#include <bits/stdc++.h>
using namespace std;
unsigned long long int pas[101][101];
unsigned long long int pd[101][10001];
unsigned long long int expo[101][101];
int n, k;
unsigned long long int m;
unsigned long long int func(int i) {
  unsigned long long int ret = m / n;
  if (i < m % n) ret++;
  return ret;
}
unsigned long long int bigMod(unsigned long long int x,
                              unsigned long long int n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  unsigned long long int res = bigMod(x, n / 2);
  res = (res * res) % 1000000007;
  if (n % 2 == 1) res = (res * x) % 1000000007;
  return res;
}
unsigned long long int solve(int x, int k) {
  if (x == n) {
    if (k != 0)
      return 0;
    else
      return 1;
  }
  if (pd[x][k] != -1) return pd[x][k];
  unsigned long long int ret = 0;
  unsigned long long int res;
  for (int i = 0; i <= min(n, k); i++) {
    if (i != 0) {
      res = expo[x][i];
      res = (res * solve(x + 1, k - i)) % 1000000007;
    } else
      res = solve(x + 1, k - i) % 1000000007;
    ret = (res + ret) % 1000000007;
  }
  return pd[x][k] = ret;
}
int main(void) {
  cin >> n >> m >> k;
  pas[0][0] = 1;
  pas[1][0] = pas[1][1] = 1;
  for (int i = 2; i <= 100; i++) {
    pas[i][0] = pas[i][i] = 1;
    for (int j = 1; j < i; j++)
      pas[i][j] = (pas[i - 1][j] + pas[i][j - 1]) % 1000000007;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= 100; j++) expo[i][j] = bigMod(pas[n][j], func(i));
  memset(pd, -1, sizeof pd);
  unsigned long long int ans = solve(0, k);
  cout << ans << endl;
  return 0;
}
