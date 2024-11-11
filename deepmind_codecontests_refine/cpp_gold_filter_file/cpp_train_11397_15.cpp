#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
int kx8[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky8[] = {2, -2, 1, -1, 2, -2, 1, -1};
long long bigmod(long long a, long long b, long long c) {
  if (b == 0) return 1 % c;
  long long x = bigmod(a, b / 2, c);
  x = (x * x) % c;
  if (b % 2 == 1) x = (x * a) % c;
  return x;
}
long long mod_inverse(long long a, long long mod) {
  return bigmod(a, mod - 2, mod);
}
int n, k, m;
long long pwr[10005];
long long dp[1005][102][2][2][2];
long long dpcall(int id, int md, int ok, int lst, int bg) {
  if (id == n) {
    if (lst) return 0LL;
    if (ok) return 1LL;
    return 0LL;
  }
  long long &ret = dp[id][md][ok][lst][bg];
  if (~ret) return ret;
  ret = 0;
  for (long long i = 0; i <= 9; i++) {
    long long now = (i * pwr[id] + md) % k;
    int nbg = bg;
    if (i > 0) nbg = 1;
    if (ok) {
      ret += dpcall(id + 1, now, ok, (i == 0), 1);
    } else {
      if (now == 0 && !nbg) {
        ret += dpcall(id + 1, now, ok, (i == 0), nbg);
      } else {
        ret += dpcall(id + 1, now, now == 0, (i == 0), nbg);
      }
    }
    ret %= m;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset((dp), -1, sizeof(dp));
  cin >> n >> k >> m;
  pwr[0] = 1;
  for (long long i = 1; i <= 1000; i++) pwr[i] = (pwr[i - 1] * 10LL) % k;
  cout << dpcall(0, 0, 0, 0, 0) << endl;
  return 0;
}
