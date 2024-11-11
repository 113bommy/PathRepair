#include <bits/stdc++.h>
using namespace std;
const long long maxn = 60;
const long long mod = 1e9 + 7;
long long ans;
long long n, p;
long long cl[maxn];
long long pow2[maxn];
long long getzoj[maxn];
long long C[maxn][maxn];
long long getfard[maxn];
long long dp[maxn][maxn][maxn][maxn];
void in();
void pp();
void solve();
long long getdp(long long x, long long y, long long z, long long E);
void out();
int main() {
  in();
  solve();
  out();
}
void in() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> p;
  for (long long i = 0; i < n; i++) cin >> cl[i];
}
void solve() {
  pp();
  dp[0][0][0][0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long ob = 0; ob <= i; ob++) {
      for (long long eb = 0; eb + ob <= i; eb++) {
        for (long long ow = 0; ow + eb + ob <= i; ow++) {
          long long ew = i - ob - eb - ow;
          if (cl[i - 1] == 0 || cl[i - 1] == -1)
            dp[i][ob][eb][ow] +=
                pow2[eb + ob + ew - 1] *
                ((getdp(i - 1, ob, eb - 1, ow) * getfard[ow] % mod +
                  getdp(i - 1, ob - 1, eb, ow) * getzoj[ow] % mod) %
                 mod) %
                mod;
          if (cl[i - 1] == 1 || cl[i - 1] == -1)
            dp[i][ob][eb][ow] +=
                pow2[eb + ow + ew - 1] *
                ((getdp(i - 1, ob, eb, ow) * getfard[ob] % mod +
                  getdp(i - 1, ob, eb, ow - 1) * getzoj[ob] % mod) %
                 mod) %
                mod;
          if (i == n && (ob + ow) % 2 == p)
            ans = (ans + dp[i][ob][eb][ow]) % mod;
        }
      }
    }
  }
}
void out() { cout << ans; }
void pp() {
  pow2[0] = 1;
  for (long long i = 1; i <= maxn; i++) pow2[i] = 2 * pow2[i - 1] % mod;
  for (long long i = 0; i < maxn; i++) C[i][0] = 1;
  for (long long i = 1; i < maxn; i++)
    for (long long j = 1; j < maxn; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  for (long long i = 0; i < maxn; i++)
    for (long long j = 0; j < maxn / 2; j++)
      getzoj[i] = (getzoj[i] + C[i][2 * j]) % mod;
  for (long long i = 0; i < maxn; i++)
    for (long long j = 0; j < maxn / 2; j++)
      getfard[i] = (getfard[i] + C[i][2 * j + 1]) % mod;
}
long long getdp(long long x, long long y, long long z, long long e) {
  if (x < 0) return 0;
  if (y < 0) return 0;
  if (z < 0) return 0;
  if (e < 0) return 0;
  return dp[x][y][z][e];
}
