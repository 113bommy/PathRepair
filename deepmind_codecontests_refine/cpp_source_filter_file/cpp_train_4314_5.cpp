#include <bits/stdc++.h>
using namespace std;
int m, a[20], cnt[15];
long long n, fact[20], dp[262150][105];
int getbit(int a, int i) { return ((a >> (i - 1)) & 1); }
int batbit(int a, int i) { return ((1 << (i - 1)) | a); }
int main() {
  int i, j, k, x, len = 0;
  long long n1;
  cin >> n >> m;
  n1 = n;
  fact[0] = 1;
  while (n1 != 0) {
    x = (int)n1 % 10;
    len++;
    a[len] = x;
    cnt[x]++;
    n1 /= 10;
  }
  for (i = 1; i <= len; i++) fact[i] = fact[i - 1] * i;
  dp[0][0] = 1;
  for (i = 0; i < (1 << len); i++)
    for (j = 0; j < m; j++)
      for (k = 1; k <= len; k++)
        if (getbit(i, k) == 0)
          if (i != 0 || a[k] != 0)
            dp[batbit(i, k)][(j * 10 + a[k]) % m] += dp[i][j];
  long long res = dp[(1 << len) - 1][0];
  for (i = 0; i < 10; i++) res /= fact[cnt[i]];
  cout << res;
  return 0;
}
