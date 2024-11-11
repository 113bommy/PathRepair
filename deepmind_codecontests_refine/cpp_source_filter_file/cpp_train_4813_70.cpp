#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 9e18;
const int inf = 2147483647;
long long phi(long long n) {
  long long ans = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans = ans / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) ans = ans / n * (n - 1);
  return ans;
}
long long qpow(long long a, long long b, long long mod) {
  long long r = 1;
  for (; b; b >>= 1) {
    if (b & 1) r = (r * a) % mod;
    a = (a * a) % mod;
  }
  return r;
}
long long C(int n, int m) {
  if (m < n - m) m = n - m;
  long long ans = 1;
  for (int i = m + 1; i <= n; i++) ans *= i;
  for (int i = 1; i <= n - m; i++) ans /= i;
  return ans;
}
const int N = 2e5 + 5;
int look(int a, int x) {
  int q = sqrt(x + 0.5);
  int ans = inf;
  for (int i = 2; i <= q; i++) {
    if (x % i == 0) {
      int j = x / i;
      if (abs(i - a) < abs(j - a)) {
        if (abs(ans - a) > abs(i - a)) {
          ans = i;
        }
      } else {
        if (abs(ans - a) > abs(j - a)) {
          ans = j;
        }
      }
    }
  }
  if (ans >= inf) {
    if (abs(1 - a) < abs(x - a)) {
      ans = 1;
    } else {
      ans = x;
    }
  } else {
    if (abs(ans - a) > abs(1 - a)) {
      ans = 1;
    }
    if (abs(ans - a) > abs(x - a)) {
      ans = x;
    }
  }
  return ans;
}
void work() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int ta, tc;
    int ans = inf;
    int as[5];
    for (int i = 1; i <= (int)1e4; i++) {
      int tb = i;
      if (tb > a) {
        ta = look(a, tb);
      } else {
        ta = tb;
      }
      if (c > tb) {
        int t1 = c / tb;
        int xc = t1 * tb, dc = (t1 + 1) * tb;
        if (abs(c - xc) < abs(c - dc)) {
          tc = xc;
        } else {
          tc = dc;
        }
      } else {
        tc = tb;
      }
      int cnt1 = abs(a - ta), cnt2 = abs(b - tb), cnt3 = abs(c - tc);
      if (cnt1 + cnt2 + cnt3 < ans) {
        ans = cnt1 + cnt2 + cnt3;
        as[0] = ta, as[1] = tb, as[2] = tc;
      }
    }
    printf("%d\n", ans);
    for (int i = 0; i < 3; ++i) {
      printf("%d ", as[i]);
    }
    puts("");
  }
}
int main() {
  work();
  return 0;
}
