#include <bits/stdc++.h>
using namespace std;
const int seed = 131;
const long long LLMAX = 2e18;
const int MOD = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 3e6 + 10;
const int hmod1 = 0x48E2DCE7;
const int hmod2 = 0x60000005;
inline long long sqr(long long x) { return x * x; }
inline int sqr(int x) { return x * x; }
inline double sqr(double x) { return x * x; }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long exgcd(long long a, long long b, long long &x, long long &y) {
  long long d;
  (b == 0 ? (x = 1, y = 0, d = a)
          : (d = exgcd(b, a % b, y, x), y -= a / b * x));
  return d;
}
long long qpow(long long a, long long n) {
  long long sum = 1;
  while (n) {
    if (n & 1) sum = sum * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return sum;
}
inline int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return (x > 0 ? 1 : -1);
}
long long sum = 0;
int h, g, a[MAXN];
vector<int> ans;
int dfs(int rt) {
  if (a[rt << 1] == 0 && a[rt << 1 | 1] == 0) {
    if ((1 << g) <= rt && rt < (1 << h)) {
      int p = a[rt];
      a[rt] = 0;
      return p;
    }
    return 0;
  }
  int p = (a[rt << 1] > a[rt << 1 | 1] ? dfs(rt << 1) : dfs(rt << 1 | 1));
  if (p) {
    swap(a[rt], p);
    return p;
  }
  return 0;
}
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    sum = 0;
    ans.clear();
    scanf("%d%d", &h, &g);
    for (int i = 1; i < (1 << h); i++)
      scanf("%d", &a[i]), a[2 * i] = a[2 * i + 1] = 0;
    for (int i = 1; i < (1 << h); i++)
      while (dfs(i)) ans.push_back(i);
    for (int i = 1; i < (1 << g); i++) sum += a[i];
    printf("%lld\n", sum);
    for (auto i : ans) printf("%d ", i);
    puts("");
  }
  return 0;
}
