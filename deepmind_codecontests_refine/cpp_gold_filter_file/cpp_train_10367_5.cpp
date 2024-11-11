#include <bits/stdc++.h>
using namespace std;
const long long modulo = (long long)1e9 + 7;
const int MAXN = 100500;
long long fact[100500], facti[100500];
long long bin_pow(long long x, long long y, long long modulo) {
  if (y == 0) return 1;
  long long t = bin_pow(x, y / 2, modulo);
  t = t * t % modulo;
  if (y % 2 == 1) t = t * x % modulo;
  return t;
}
long long get_inv(long long x, long long modulo) {
  return bin_pow(x, modulo - 2, modulo);
}
void calc_fact() {
  fact[0] = facti[0] = 1;
  for (int i = 1; i < 100500; ++i) {
    fact[i] = fact[i - 1] * i % modulo;
    facti[i] = facti[i - 1] * get_inv(i, modulo) % modulo;
  }
}
long long c(long long n, long long k, long long modulo) {
  if (n < k || n < 0 || k < 0) return 0;
  long long ans = 1;
  ans = ans * fact[n] % modulo;
  ans = ans * facti[k] % modulo;
  ans = ans * facti[n - k] % modulo;
  return ans;
}
long long get_ans(long long all, long long kol, long long h) {
  long long last = all - kol * (h + 1);
  if (last < 0) return 0;
  return c(last + kol - 1, kol - 1, modulo);
}
int main() {
  calc_fact();
  ios::sync_with_stdio(0);
  long long f, w, h;
  cin >> f >> w >> h;
  if (f == 0) {
    if (w > h)
      cout << 1;
    else
      cout << 0;
    return 0;
  }
  if (w == 0) {
    cout << 1;
    return 0;
  }
  long long ans = 0;
  long long ans2 = 0;
  for (long long i = 0; i <= f; ++i) {
    for (long long j = max(0ll, i - 1); j <= min(w, i + 1); ++j) {
      long long tmp = get_ans(f, i, 0) * get_ans(w, j, h) % modulo;
      long long tmp2 = get_ans(f, i, 0) * get_ans(w, j, 0) % modulo;
      ans += (i == j ? tmp * 2 : tmp);
      ans %= modulo;
      ans2 += (i == j ? tmp2 * 2 : tmp2);
      ans2 %= modulo;
    }
  }
  cout << ans * get_inv(ans2, modulo) % modulo;
  return 0;
}
