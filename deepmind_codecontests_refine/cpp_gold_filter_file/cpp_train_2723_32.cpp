#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)998244353;
const int MAXN = (int)53;
const int infint = (int)1e9 + 3;
const long long inf = (long long)1e18;
int n, m, a[MAXN], w[MAXN], dp[MAXN][MAXN][MAXN], pos = 0, neg = 0, tneg = 0,
                                                  tpos = 0;
int add(int a, int b) {
  a += b;
  if (a < 0) a += MOD;
  if (a >= MOD) a -= MOD;
  return a;
}
int mul(int a, int b) {
  int c = 1LL * a * b % MOD;
  return c;
}
int pwr(int a, int b) {
  if (b == 0) return 1;
  int c = pwr(a, b >> 1);
  c = mul(c, c);
  if (b & 1) c = mul(c, a);
  return c;
}
int inv(int p) { return pwr(p, MOD - 2); }
int f(int x, int i) {
  if (a[x] == 0)
    return -i;
  else
    return i;
}
int calc(int x, int i, int j, int k) {
  if (dp[i][j][k] != -1) return dp[i][j][k];
  if (neg < k || (a[x] == 0 && i > w[x]) || ((tpos - a[x]) == 0 && j) ||
      ((tneg - 1 + a[x]) == 0 && k))
    return dp[i][j][k] = 0;
  if (i + j + k == m) return dp[i][j][k] = w[x] + f(x, i);
  int dem = add(pos, neg);
  dem = add(dem, add(f(x, i) + j, -k));
  int num = mul(w[x] + f(x, i), calc(x, i + 1, j, k));
  num = add(num, mul(pos - a[x] * w[x] + j, calc(x, i, j + 1, k)));
  num = add(num, mul(neg + (a[x] - 1) * w[x] - k, calc(x, i, j, k + 1)));
  return dp[i][j][k] = mul(num, inv(dem));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    if (a[i])
      pos += w[i], tpos++;
    else
      neg += w[i], tneg++;
  }
  int firpos = 0, valf = 0, firneg = 0, valn = 0;
  for (int i = 1; i <= n; i++) {
    if (firpos == 0 && a[i] == 1) {
      memset(dp, -1, sizeof dp);
      firpos = i, valf = calc(i, 0, 0, 0);
    }
    if (firneg == 0 && a[i] == 0) {
      memset(dp, -1, sizeof dp);
      firneg = i, valn = calc(i, 0, 0, 0);
    }
  }
  for (int i = 1; i <= n; i++)
    if (a[i] == 1)
      cout << mul(valf, mul(w[i], inv(w[firpos]))) << " ";
    else
      cout << mul(valn, mul(w[i], inv(w[firneg]))) << " ";
}
