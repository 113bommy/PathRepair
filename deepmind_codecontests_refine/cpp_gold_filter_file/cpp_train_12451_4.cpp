#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void mul(vector<vector<long long> >& a, vector<vector<long long> > b) {
  vector<vector<long long> > c = a;
  for (int(i) = (0); (i) < (17); (i)++)
    for (int(j) = (0); (j) < (17); (j)++) {
      a[i][j] = 0;
      for (int(k) = (0); (k) < (17); (k)++)
        a[i][j] = (a[i][j] + c[i][k] * b[k][j]) % mod;
    }
}
vector<vector<long long> > eleva(vector<vector<long long> > b, long long e) {
  vector<vector<long long> > ret(17, vector<long long>(17, 0));
  for (int(i) = (0); (i) < (17); (i)++) ret[i][i] = 1;
  while (e) {
    if (e & 1) mul(ret, b);
    e >>= 1;
    mul(b, b);
  }
  return ret;
}
int n;
long long k;
void get(vector<vector<long long> >& cur) {
  cur = vector<vector<long long> >(17, vector<long long>(17, 0));
  long long a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);
  b = min(b, k);
  for (int(i) = (0); (i) < (17); (i)++)
    if (i <= c)
      for (int(j) = (-1); (j) < (2); (j)++)
        if (i + j <= c && 0 <= i + j) cur[i][i + j] = 1;
  cur = eleva(cur, b - a);
}
vector<vector<long long> > tot[111];
long long dp[111][17];
long long solve(int i, int c) {
  if (i == n && c == 0) return 1LL;
  if (i == n) return 0;
  long long& ret = dp[i][c];
  if (ret != -1) return ret;
  ret = 0;
  for (int(j) = (0); (j) < (17); (j)++)
    if (tot[i][c][j]) ret = (ret + tot[i][c][j] * solve(i + 1, j)) % mod;
  return ret;
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%lld", &n, &k);
  for (int(i) = (0); (i) < (n); (i)++) get(tot[i]);
  printf("%lld\n", solve(0, 0));
}
