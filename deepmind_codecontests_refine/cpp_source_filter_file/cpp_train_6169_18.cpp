#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e6 + 7;
const long long maxm = 5e3 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
long long min(long long a, long long b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
bool cmp(long long a, long long b) { return a > b; }
struct node {
  long long x, y, z;
  node(long long x = 0, long long y = 0, long long z = 0) : x(x), y(y), z(z) {}
  friend bool operator<(const node &a, const node &b) { return a.x > b.x; }
};
const long long N = 2e5 + 5;
long long n, m, k;
long long a[N], b[N];
long long work() {
  long long _;
  for (scanf("%lld", &_); _; _--) {
    cin >> n;
    puts(n % 2 ? "NO" : "YES");
  }
  return 0;
}
signed main() { work(); }
