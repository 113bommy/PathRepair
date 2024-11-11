#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 1000000007) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
int p, c[105], pw[105];
int dp[55][55][55][55];
void fmain(int ID) {
  scanf("%d%d", &n, &p);
  for (int(i) = 1; (i) <= (int)(n); (i)++) scanf("%d", c + i);
  pw[0] = 1;
  for (int(i) = 1; (i) <= (int)(n); (i)++) pw[i] = pw[i - 1] * 2 % 1000000007;
  dp[0][0][0][0] = 1;
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    for (int(ew) = 0; (ew) < (int)(i); (ew)++)
      for (int(ow) = 0; (ow) < (int)(i); (ow)++)
        for (int(eb) = 0; (eb) < (int)(i); (eb)++) {
          int ob = i - 1 - ew - ow - eb;
          if (ob < 0) {
            continue;
          }
          if (c[i] != 0) {
            if (ob) {
              addmod(dp[i][ew][ow + 1][eb], (long long)dp[i - 1][ew][ow][eb] *
                                                pw[ew + ow + eb + ob - 1] %
                                                1000000007);
              addmod(dp[i][ew + 1][ow][eb], (long long)dp[i - 1][ew][ow][eb] *
                                                pw[ew + ow + eb + ob - 1] %
                                                1000000007);
            } else {
              addmod(dp[i][ew][ow + 1][eb], (long long)dp[i - 1][ew][ow][eb] *
                                                pw[ew + ow + eb] % 1000000007);
            }
          }
          if (c[i] != 1) {
            if (ow) {
              addmod(dp[i][ew][ow][eb], (long long)dp[i - 1][ew][ow][eb] *
                                            pw[ew + ow + eb + ob - 1] %
                                            1000000007);
              addmod(dp[i][ew][ow][eb + 1], (long long)dp[i - 1][ew][ow][eb] *
                                                pw[ew + ow + eb + ob - 1] %
                                                1000000007);
            } else {
              addmod(dp[i][ew][ow][eb], (long long)dp[i - 1][ew][ow][eb] *
                                            pw[ob + eb + ow] % 1000000007);
            }
          }
        }
  }
  int ans = 0;
  for (int(ew) = 0; (ew) < (int)(n + 1); (ew)++)
    for (int(ow) = 0; (ow) < (int)(n + 1); (ow)++)
      for (int(eb) = 0; (eb) < (int)(n + 1); (eb)++) {
        int ob = n - ew - ow - eb;
        if (ob < 0) {
          continue;
        }
        if ((ob + ow) % 2 == p) addmod(ans, dp[n][ew][ow][eb]);
      }
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
