#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
const int maxl = (1 << 18);
const int INF = 1e9;
int dp[maxn][maxl];
int par[maxn][maxl];
int n;
int a[maxn];
int val[70];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int ms[70];
int Solve(int pos, int mask) {
  int &ret = dp[pos][mask];
  if (ret != -1) return ret;
  if (pos == n + 1) return ret = 0;
  ret = INF;
  for (int i = 1; i <= 60; i++) {
    if ((ms[i] & mask) == 0) {
      if (ret > Solve(pos + 1, (mask | ms[i])) + abs(a[pos] - i)) {
        ret = min(ret, Solve(pos + 1, (mask | ms[i])) + abs(a[pos] - i));
        par[pos][mask] = i;
      }
    }
  }
  return ret;
}
int main() {
  cin >> n;
  val[2] = 0;
  val[3] = 1;
  val[5] = 2;
  val[7] = 3;
  val[11] = 4;
  val[13] = 5;
  val[17] = 6;
  val[19] = 7;
  val[23] = 8;
  val[29] = 9;
  val[31] = 10;
  val[37] = 11;
  val[41] = 12;
  val[43] = 13;
  val[47] = 14;
  val[53] = 15;
  val[59] = 16;
  for (int i = 1; i <= 60; i++) {
    for (int j = 0; j < 17; j++) {
      if (i % prime[j] == 0) {
        ms[i] += (1 << val[prime[j]]);
      }
    }
  }
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(dp, -1, sizeof(dp));
  memset(par, -1, sizeof(par));
  int pos = 1, mask = 0;
  Solve(1, 0);
  while (par[pos][mask] != -1) {
    cout << par[pos][mask] << " ";
    mask |= ms[par[pos][mask]];
    pos++;
  }
  cout << endl;
  return 0;
}
