#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7 + 500000;
const long long LL_INF = 1ll * INF * INF;
const int MAX_N = 2000 + 7;
template <typename T>
inline void addmod(T& a, const long long& b, const int& MOD = INF) {
  a = (a + b) % MOD;
  if (a < 0) a += MOD;
}
long long n, k;
long long l, r;
long long last_len;
long long res;
bool cover(long long f_u, long long u, long long f_v, long long v) {
  return f_u >= u && f_v >= v && u >= 0 && v >= 0;
}
long long calc(long long f_n, long long r) {
  if (f_n < 0 || r < 0) return -1;
  if (!r) {
    if (last_len % n != 0) return -1;
    if (f_n >= n && f_n <= 2 * n) return f_n - n;
    return -1;
  }
  if (f_n >= n && f_n <= 2 * n && r >= last_len && r <= 2 * last_len) {
    long long T = f_n - n;
    long long tmp = r - last_len;
    if (cover(last_len, tmp, n - last_len, T - tmp)) {
      return T;
    }
    if (cover(last_len, tmp + 1, n - last_len, T - tmp - 1)) {
      return T;
    }
  }
  return -1;
}
void solve() {
  cin >> n >> l >> r >> k;
  last_len = r - l + 1;
  if (last_len <= 0) last_len += n;
  res = -1;
  if (last_len == n) {
    for (long long q = 1; q * q <= k; ++q) {
      res = max(res, calc(k / q, k % q));
      res = max(res, calc(q, k % q));
    }
  }
  for (long long q = 1; q * q <= k; ++q) {
    long long f_n = k / q;
    long long mn_f_n = max(k / (q + 1) + 1, 1ll);
    long long r_min = k - q * f_n, r_max = k - q * mn_f_n;
    if (f_n < n || mn_f_n > 2 * n) continue;
    if (f_n > 2 * n) {
      f_n = 2 * n;
      r_min = k - q * f_n;
    }
    if (mn_f_n < n) {
      mn_f_n = n;
      r_max = k - q * mn_f_n;
    }
    if (r_min > 2 * last_len || r_max < last_len) continue;
    if (r_min < last_len) {
      long long diff = (last_len - r_min + q - 1) / q;
      f_n -= diff;
      r_min += q * diff;
    }
    if (r_max > 2 * last_len) {
      long long diff = (r_max - 2 * last_len + q - 1) / q;
      mn_f_n += diff;
      r_max -= q * diff;
    }
    long long lo = mn_f_n, hi = f_n, cur = -1;
    while (lo <= hi) {
      long long mid = (lo + hi) >> 1;
      if (calc(mid, k % mid) > 0) {
        cur = max(cur, calc(mid, k % mid));
        lo = mid + 1;
      } else
        hi = mid - 1;
    }
    res = max(res, cur);
  }
  for (long long f_n = 1; f_n * f_n <= k; ++f_n) {
    long long q = k / f_n;
    long long r = k - q * f_n;
    res = max(res, calc(f_n, r));
  }
  if (k >= last_len && k <= 2 * last_len) {
    if (k == 2 * last_len)
      res = max(res, last_len + n - last_len);
    else
      res = max(res, k - last_len + 1 + n - last_len);
  }
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test) cin >> test;
  for (int i = 0; i < test; ++i) {
    solve();
  }
}
