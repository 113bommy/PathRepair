#include <bits/stdc++.h>
using namespace std;
const long long MOD = 2e16;
const int maxn = 3e5 + 100;
const long long linf = 9223372036854775807;
const int inf = 0x3f;
const double eps = 1e-4;
const double DoubleInf = 1e20;
const double pi = acos(-1.0);
long long qpow(long long a, long long b) {
  return b ? ((b & 1) ? a * qpow(a * a % MOD, b >> 1) % MOD
                      : qpow(a * a % MOD, b >> 1)) %
                 MOD
           : 1ll;
}
long long quick_mod(long long a, long long b, long long MOD) {
  long long ans = 1;
  a %= MOD;
  while (b) {
    if (b & 1) {
      ans = ans * a % MOD;
      b--;
    }
    b >>= 1;
    a = a * a % MOD;
  }
  return ans;
}
inline int ird() {
  register int x = 0, f = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x * 2) + ch - '0', ch = getchar();
  return x * f;
}
inline long long lrd() {
  register long long x = 0, f = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x * 2) + ch - '0', ch = getchar();
  return x * f;
}
void puts1() { cout << "-1" << endl; }
void puts2() { cout << "YES" << endl; }
void puts3() { cout << "NO" << endl; }
int gcd(int a, int b) { return (b > 0) ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }
long long lgcd(long long a, long long b) {
  return (b > 0) ? lgcd(b, a % b) : a;
}
long long llcm(long long a, long long b) { return a * b / lgcd(a, b); }
int T, co, n;
int cun[maxn], a[maxn], mp[maxn], ans[maxn];
int main() {
  scanf("%d", &T);
  int out;
  while (T--) {
    scanf("%d", &n);
    co = 0;
    out = inf;
    for (int i = 1; i <= n; i++) {
      cun[i] = 0;
      mp[i] = 0;
      ans[i] = inf;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      cun[a[i]] = max(cun[a[i]], i - mp[a[i]]);
      mp[a[i]] = i;
    }
    for (int i = n; i >= 1; i--) {
      if (a[n] == a[i])
        cun[a[i]] = max(cun[a[i]], n - mp[a[i]]);
      else
        cun[a[i]] = max(cun[a[i]], n - mp[a[i]] + 1);
      ans[cun[a[i]]] = min(a[i], ans[cun[a[i]]]);
    }
    for (int i = 1; i <= n; i++) {
      out = min(out, ans[i]);
      if (out == inf) {
        printf("-1 ");
        continue;
      }
      printf("%d ", out);
    }
    printf("\n");
  }
  return 0;
}
