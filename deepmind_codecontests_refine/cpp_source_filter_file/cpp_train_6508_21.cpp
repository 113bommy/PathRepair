#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MAXN = 5e4 + 10;
const long long LOG = 30 + 3;
const long long MAXX = 100 + 3;
struct Mat {
  long long v[MAXX][MAXX];
  Mat(long long z = 0) {
    for (long long i = 0; i < MAXX; i++)
      for (long long j = 0; j < MAXX; j++)
        if (i == j)
          v[i][j] = z;
        else
          v[i][j] = 0;
  }
};
Mat mul(Mat a, Mat b) {
  Mat ret;
  for (long long i = 0; i < MAXX; i++)
    for (long long j = 0; j < MAXX; j++)
      for (long long w = 0; w < MAXX; w++)
        ret.v[i][j] = (ret.v[i][j] + a.v[i][w] * b.v[w][j]) % MOD;
  return ret;
}
Mat pw(Mat a, long long b) {
  Mat ret(1);
  while (b) {
    if (b & 1) ret = mul(ret, a);
    b >>= 1;
    a = mul(a, a);
  }
  return ret;
}
long long n, b, k, x;
long long cnt[20], c[200];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> b >> k >> x;
  while (n--) {
    long long y;
    cin >> y;
    cnt[y]++;
    c[y % x]++;
  }
  Mat ans;
  for (long long i = 0; i < x; i++) ans.v[i][0] = c[i];
  Mat tt;
  for (long long i = 0; i < x; i++)
    for (long long j = 0; j < x; j++)
      for (long long w = 1; w < 10; w++)
        if ((w * 10 + j) % x == i) tt.v[i][j] += cnt[w];
  tt = pw(tt, b - 1);
  ans = mul(tt, ans);
  cout << ans.v[k][0] % MOD << "\n";
  return 0;
}
