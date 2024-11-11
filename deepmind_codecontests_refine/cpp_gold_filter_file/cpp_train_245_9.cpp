#include <bits/stdc++.h>
using namespace std;
int INP, AM, REACHEOF;
char BUF[(1 << 12) + 1], *inp = BUF;
const long double PI = acos((long double)-1.0);
const long long MOD = 1000000009LL;
int n, w, b;
long long gt[4011], revgt[4011];
long long power(long long x, long long k) {
  if (k == 0) return 1;
  if (k == 1) return x % MOD;
  long long mid = power(x, k >> 1);
  mid = (mid * mid) % MOD;
  if (k & 1)
    return (mid * x) % MOD;
  else
    return mid;
}
long long get(int n, int k) {
  return gt[n] * gt[n - 1] % MOD * revgt[k - 1] % MOD * revgt[n - k] % MOD;
}
int main() {
  gt[0] = 1;
  for (int i = (1), _b = (4000); i <= _b; i++) gt[i] = (gt[i - 1] * i) % MOD;
  for (int i = (0), _b = (4000); i <= _b; i++) revgt[i] = power(gt[i], MOD - 2);
  while (cin >> n >> w >> b) {
    long long res = 0;
    for (int y = (1), _b = (n - 2); y <= _b; y++)
      if (b >= y && n - y <= w) {
        int xz = n - y;
        long long now = (n - y) - 2 + 1;
        now = (now * get(w, xz)) % MOD * get(b, y) % MOD;
        res = (res + now) % MOD;
      }
    cout << res << endl;
  }
  return 0;
}
