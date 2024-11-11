#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int mod = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  if (a >= mod) a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    if (res >= mod) res %= mod;
    a = a * a;
    if (a >= mod) a %= mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }
const int maxn = 100010;
const int inf = INT_MAX;
long long powmo(int x, int y) {
  long long ret = 1;
  while (y--) {
    ret = ret * x;
    if (ret > mod) return mod;
  }
  return ret;
}
int main() {
  long long n, l, r;
  cin >> n >> l >> r;
  if (n == 1) {
    cout << r - l + 1;
  } else if (n == 2) {
    cout << (r - l + 1) * 1LL * (r - l);
  } else if (n >= 25)
    cout << 0;
  else {
    long long ans = 0;
    for (int x = 1; x <= (pow(r, 1.0 / (n - 1))); x++)
      for (int y = 1; y < x; y++) {
        if (gcd(x, y) != 1) continue;
        ans += max(0LL, (r / powmo(x, n - 1)) - ((l - 1) / powmo(y, n - 1)));
      }
    cout << 2 * ans << '\n';
  }
  return 0;
}
