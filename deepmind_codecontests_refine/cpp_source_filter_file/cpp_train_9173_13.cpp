#include <bits/stdc++.h>
using namespace std;
template <class T>
bool cmin(T &a_, T b_) {
  return a_ > b_ ? (a_ = b_, true) : false;
}
template <class T>
bool cmax(T &a_, T b_) {
  return a_ < b_ ? (a_ = b_, true) : false;
}
template <class T>
void OUT(T s_) {
  cout << s_ << '\n';
  exit(0);
}
const int maxn = 1.0001e6;
const long long mod = 998244353;
long long n;
long long gt[maxn];
long long power(long long a, long long b) {
  if (!b) return 1LL;
  long long c = power(a, b >> 1);
  c *= c;
  c %= mod;
  if (b & 1) {
    c *= a;
    c %= mod;
  }
  return c;
}
long long f(long long a, long long b) {
  if (a == b) return 1;
  return (gt[a] * power((gt[b] * gt[a - b]) % mod, mod - 2)) % mod;
}
void Fan_chipu() {
  cin >> n;
  gt[0] = 1;
  for (int i = (int)(1); i <= (int)(maxn - 1); ++i)
    gt[i] = gt[i - 1] * i, gt[i] %= mod;
  long long ans = 0LL;
  for (int i = (int)(0); i <= (int)(n); ++i) {
    ans += (f(n, i) * ((gt[i] - i) * gt[n - i]) % mod) % mod;
    ans %= mod;
  }
  cout << ans % mod << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  Fan_chipu();
}
