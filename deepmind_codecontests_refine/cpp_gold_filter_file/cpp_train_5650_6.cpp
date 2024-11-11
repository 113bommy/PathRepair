#include <bits/stdc++.h>
using namespace std;
void ac(long long x) {
  if (x)
    puts("YES");
  else
    puts("NO");
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long ppow(long long a, long long b, long long mod) {
  a %= mod;
  long long ans = 1 % mod;
  while (b) {
    if (b & 1) ans = (long long)ans * a % mod;
    a = (long long)a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long readdd() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return f * x;
}
void printtt(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) printtt(x / 10);
  putchar(x % 10 + '0');
}
bool addd(long long a, long long b) { return a > b; }
long long lowbit(long long x) { return x & -x; }
const long long dx[4] = {0, 0, 1, -1};
const long long dy[4] = {1, -1, 0, 0};
const long long BN = 2e6 + 5;
struct BIT {
  long long c[BN];
  void init() { memset(c, 0, sizeof c); }
  long long lowbit(long long i) { return i & -i; }
  void add(long long i, long long t) {
    while (i < BN) c[i] += t, i += lowbit(i);
  }
  long long ask(long long i) {
    long long ans = 0;
    while (i) ans += c[i], i -= lowbit(i);
    return ans;
  }
};
bool Isprime(long long x) {
  for (long long i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
bool isdigit(char c) { return c >= '0' && c <= '9'; }
void init() { ; }
const double Pi = acos(-1);
const double eps = 1e-7;
const long long mod = 1e9 + 7;
const long long modd = mod - 1;
const long long maxm = 1e5 + 5;
long long a[maxm];
long long b[maxm];
long long n;
void solve() {
  n = readdd();
  for (signed long long(i) = 1; (i) <= (n); (i)++) a[i] = readdd();
  if (n == 1) {
    cout << "T" << endl;
    return;
  } else if (n == 2) {
    if (a[1] != a[2]) {
      cout << "T" << endl;
      return;
    } else {
      cout << "HL" << endl;
      return;
    }
  } else {
    long long sum = 0;
    for (signed long long(i) = 1; (i) <= (n); (i)++) sum += a[i];
    long long ma = 0;
    for (signed long long(i) = 1; (i) <= (n); (i)++) ma = max(a[i], ma);
    if (sum - ma < ma) {
      cout << "T" << endl;
      return;
    }
    if (sum - ma == ma) {
      cout << "HL" << endl;
      return;
    }
    if (sum % 2 == 0) {
      cout << "HL" << endl;
      return;
    } else {
      cout << "T" << endl;
      return;
    }
  }
}
signed main() {
  init();
  signed QP;
  scanf("%d", &QP);
  while (QP--) solve();
  return 0;
}
