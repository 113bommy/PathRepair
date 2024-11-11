#include <bits/stdc++.h>
bool isPrime(long long int x) {
  if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
  for (int i = 5; i * i <= x; i += 6)
    if (x % i == 0 || x % (i + 2) == 0) return 0;
  return 1;
}
using namespace std;
inline void boostIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
}
const unsigned long long INF = 9223372036854775807;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
long long optpow(long long a, long long b, long long k) {
  if (b == 0) return 1;
  long long tmp = optpow(a, b / 2, k);
  if (b % 2 == 1) {
    return ((tmp * tmp) % k * a) % k;
  } else {
    return (tmp * tmp) % k;
  }
}
long long qckpow(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = qckpow(a, b / 2);
  if (b % 2 == 1) {
    return ((tmp * tmp) * a);
  } else {
    return (tmp * tmp);
  }
}
const long long modulo = 1e9 + 7;
const long long MAXN = 1e5 + 5;
vector<pair<long long, long long>> gr[MAXN];
long long const maxn = 2e5 + 5;
long long par[maxn];
long long rnk[maxn];
vector<long long> del;
vector<long long> add;
long long maxS = 51;
vector<long long> cnt(maxn, 0);
vector<string> S;
long long getpar(long long x) {
  if (par[x] == x) return x;
  return par[x] = getpar(par[x]);
}
void uni(long long x, long long y) {
  x = getpar(x);
  y = getpar(y);
  if (x != y) {
    par[y] = x;
  }
}
int32_t main() {
  boostIO();
  long long T;
  cin >> T;
  while (T--) {
    long long n, d;
    cin >> n >> d;
    vector<long long> a(n);
    long long ans = 0;
    for (long long i = 0; i < (n); i++) {
      cin >> a[i];
    }
    for (long long i = 1; i < n; ++i) {
      for (long long j = 1; j <= a[i]; ++j) {
        if (d - i >= 0) {
          ++a[0];
          d -= i;
        }
      }
    }
    cout << a[0] << "\n";
  }
}
