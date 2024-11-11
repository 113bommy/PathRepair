#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, inf = 1e18, mod = 1e9 + 7;
const double PI = 3.1415926536;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool is_prime(long long n) {
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
inline long long getPow(long long a, long long b) {
  long long res = 1ll, tp = a;
  while (b) {
    if (b & 1ll) {
      res *= tp;
    }
    tp *= tp;
    b >>= 1ll;
  }
  return res;
}
long long vec_mult(const pair<long long, long long> &t1,
                   const pair<long long, long long> &t2,
                   const pair<long long, long long> &t3) {
  const long long &x1 = t1.first, y1 = t1.second;
  const long long &x2 = t2.first, y2 = t2.second;
  const long long &x3 = t3.first, y3 = t3.second;
  return ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
}
void ok() {
  cout << "YES" << endl;
  exit(0);
}
void no() {
  cout << "NO" << endl;
  exit(0);
}
inline long long nxt() {
  long long x;
  cin >> x;
  return x;
}
long long otr(long long num) {
  long long cur = 0;
  long long ct = 1;
  while (num) {
    cur += ct * (9 - num % 10);
    num /= 10;
    ct *= 10;
  }
  return cur;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long l = nxt(), r = nxt();
  long long t = 1ll;
  long long ans = -1;
  while (t <= r) {
    long long left = max(l, t);
    long long right = min(r, 10ll * t - 1);
    while (right - left >= 2) {
      long long len = (right - left + 1) / 3;
      long long t1 = left + len;
      long long t2 = right - len;
      if (t1 * otr(t1) > t2 * otr(t2)) {
        right = t2;
      } else {
        left = t1;
      }
    }
    while (left <= right) {
      ans = max(ans, left * otr(left));
      left++;
    }
    t *= 10ll;
  }
  cout << ans;
  return 0;
}
