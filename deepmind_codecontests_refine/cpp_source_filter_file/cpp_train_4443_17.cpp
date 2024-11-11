#include <bits/stdc++.h>
using namespace std;
inline int getidx(const vector<int>& ar, int x) {
  lower_bound(ar.begin(), ar.end(), x) - ar.begin();
}
inline long long GCD(long long a, long long b) {
  long long n;
  if (a < b) swap(a, b);
  while (b != 0) {
    n = a % b;
    a = b;
    b = n;
  }
  return a;
}
inline long long LCM(long long a, long long b) {
  if (a == 0 || b == 0) return GCD(a, b);
  return a / GCD(a, b) * b;
}
inline long long CEIL(long long n, long long d) { return n / d + n % d != 0; }
inline long long ROUND(long long n, long long d) {
  return n / d + (long long)((n % d) * 2 >= d);
}
inline long long POW(long long a, long long n) {
  if (n < 0) return 0;
  long long ret = 1;
  while (n) {
    if (n % 2) ret *= a;
    a = a * a;
    n /= 2;
  }
  return ret;
}
long long n, m;
void input() { cin >> n >> m; }
long long sum(long long s, long long e) {
  if (s > e) return 0;
  return (s + e) * (e - s + 1) / 2;
}
int solve() {
  long long lo = -1, hi = 2 * 1e9 + 10;
  while (lo + 1 < hi) {
    long long mi = (lo + hi) / 2;
    if (mi * mi + mi <= 2 * n)
      lo = mi;
    else
      hi = mi;
  }
  long long x = min(lo, m);
  n -= x * (x + 1) / 2;
  assert(n >= 0);
  long long ans = x;
  lo = x, hi = 2 * 1e9 + 10;
  while (lo + 1 < hi) {
    long long mi = (lo + hi) / 2;
    if (2 * sum(x + 1, mi - 1) + x + m <= n)
      lo = mi;
    else
      hi = mi;
  }
  if (lo != x) {
    ans += 2 + 2 * (lo - x - 1);
    n -= 2 * sum(x + 1, lo - 1) + x + lo;
    if (n) {
      long long d = min(lo, n);
      if (n % d) ++ans;
      ans += n / d;
      n = 0;
    }
  }
  if (n) {
    long long d = min(x, n);
    if (n % d) ++ans;
    ans += n / d;
  }
  cout << ans << '\n';
  return 0;
}
void execute() { input(), solve(); }
int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  execute();
  return 0;
}
