#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rread(T& num) {
  num = 0;
  T f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') num = num * 10 + ch - '0', ch = getchar();
  num *= f;
}
const long long inf = 1e17;
const int maxn = 2e5 + 100, mod = 1e9 + 7;
const long double PI = acos(-1.0);
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
void exgcd(long long a, long long b, long long& d, long long& x, long long& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long power(long long a, long long n, long long mod) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
int n;
long long r;
long long l[maxn], t[maxn];
vector<long long> me;
int main() {
  while (~scanf("%d%lld", &n, &r)) {
    me.clear();
    for (int i = 1; i <= n; i++) scanf("%lld", &l[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &t[i]);
    int f = 1;
    for (int i = 1; i <= n; i++)
      if (t[i] < l[i]) f = 0;
    if (f == 0) {
      printf("-1\n");
      continue;
    }
    long long s = 0, cun = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
      if (l[i] <= s) {
        s -= l[i], sum += l[i];
        continue;
      }
      long long ss = s;
      l[i] -= s;
      t[i] -= s;
      sum += s;
      long long x = t[i] - l[i];
      long long y = l[i] - x;
      s = 0;
      if (x >= l[i]) {
        sum += 2 * l[i];
        l[i] += ss;
        t[i] += ss;
        continue;
      }
      long long k = y / r;
      cun += k;
      s = y - k * r;
      if (s != 0) s = r - s, cun++;
      long long gg = x;
      sum += x * 2 + y;
      l[i] += ss;
      t[i] += ss;
    }
    if (cun <= 100000) {
      s = 0, cun = 0;
      sum = 0;
      for (int i = 1; i <= n; i++) {
        if (l[i] <= s) {
          s -= l[i], sum += l[i];
          continue;
        }
        long long ss = s;
        l[i] -= s;
        t[i] -= s;
        sum += s;
        long long x = t[i] - l[i];
        long long y = l[i] - x;
        s = 0;
        if (x >= l[i]) {
          sum += 2 * l[i];
          continue;
        }
        long long k = y / r;
        cun += k;
        s = y - k * r;
        if (s != 0) s = r - s, cun++;
        long long gg = x;
        sum += x * 2;
        me.push_back(sum);
        while (gg + r < l[i]) {
          gg += r;
          sum += r, me.push_back(sum);
        }
        sum += r - s;
      }
    }
    printf("%lld\n", cun);
    if (cun <= 100000)
      for (int i = 0; i < me.size(); i++) printf("%lld ", me[i]);
    printf("\n");
  }
  return 0;
}
