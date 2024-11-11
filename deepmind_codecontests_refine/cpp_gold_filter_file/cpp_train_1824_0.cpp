#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 2;
const long long mod = 1e9 + 7;
long long x[N], y[N], sum_x = 0, sum_y = 0, sum_cross = 0, sum_sum_cross = 0,
                      now = 1, s = 0;
void cac1(long long &a, long long b) {
  if (b < 0) {
    b += mod;
  }
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}
void cac(long long &a, long long b) {
  if (b < 0) {
    b += mod;
  }
  a -= b;
  if (a < 0) {
    a += mod;
  }
}
long long cross(long long a, long long b) { return -x[a] * y[b] + x[b] * y[a]; }
void undo(long long a) {
  cac(sum_cross, cross(a, a + 1) % mod);
  cac(sum_sum_cross, (cross(a, a + 1) % mod * (now - a)) % mod);
  cac(sum_x, x[a + 1]);
  cac(sum_y, y[a + 1]);
  s -= cross(a, a + 1);
}
void add(long long a) {
  cac1(sum_cross, cross(a, a + 1) % mod);
  cac1(sum_sum_cross, sum_cross);
  cac1(sum_x, x[a + 1]);
  cac1(sum_y, y[a + 1]);
  s += cross(a, a + 1);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, i, j, k, l, ans = 0, area = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    x[i + n] = x[i];
    y[i + n] = y[i];
  }
  for (i = 1; i <= n; i++) {
    area += cross(i, i + 1);
  }
  for (i = 1; i <= n; i++) {
    if (i > 1) {
      undo(i - 1);
    }
    while (true) {
      if ((s + cross(now + 1, i) + cross(now, now + 1)) < (area + 1) / 2) {
        add(now);
        now++;
      } else {
        if ((s + cross(now + 1, i) + cross(now, now + 1)) == area / 2 &&
            now < n && !(area & 1)) {
          add(now);
          now++;
        } else {
          break;
        }
      }
    }
    cac1(ans, (sum_sum_cross +
               (x[i] * (sum_y % mod) - (sum_x % mod) * y[i]) % mod + mod) %
                  mod);
  }
  cout << (((n * (n - 3)) / 2) % mod * (area % mod) - 2 * ans + mod) % mod;
}
