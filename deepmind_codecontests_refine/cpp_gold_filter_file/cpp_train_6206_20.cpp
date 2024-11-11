#include <bits/stdc++.h>
using namespace std;
const long long max1 = 11;
const long long max2 = 102;
const long long max3 = 1003;
const long long max4 = 10004;
const long long maxx = 100005;
const long long max6 = 1000006;
const long long max7 = 10000007;
const long long lg2 = 7;
const long long lg3 = 10;
const long long lg4 = 13;
const long long lg5 = 17;
const long long lg6 = 20;
const long long lg7 = 24;
const long long lg8 = 27;
const long long lg9 = 30;
const long long lg18 = 60;
const long long INF = 2LL * 1000000000;
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long is_prime(long long n) {
  if (n == 1) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  for (long long i = 3; i <= sqrt(n); i += 2)
    if (n % i == 0) return 0;
  return 1;
}
long long is_integer(double n) {
  if (floor(n) == ceil(n)) return 1;
  return 0;
}
long long sto_int(string s) {
  stringstream ss(s);
  long long n;
  ss >> n;
  return n;
}
string to_string(long long n) {
  stringstream ss;
  ss << n;
  string s = ss.str();
  return s;
}
long long n, k, arr[60][60];
long long N[60], res;
vector<long long> clique;
void BronKerbosch(long long n, long long R, long long P, long long X) {
  if (P == 0LL && X == 0LL) {
    long long t = 0;
    vector<long long> v;
    for (long long i = 0; i < n; i++)
      if ((1ll << i) & R) t++, v.push_back(i + 1);
    if (t > res) {
      res = t;
      clique = v;
    }
    res = max(res, t);
    return;
  }
  long long u = 0;
  while (!((1ll << u) & (P | X))) u++;
  for (long long v = 0; v < n; v++) {
    if (((1ll << v) & P) && !((1ll << v) & N[u])) {
      BronKerbosch(n, R | (1ll << v), P & N[v], X & N[v]);
      P -= (1ll << v);
      X |= (1ll << v);
    }
  }
}
long long maxClique() {
  res = -1;
  for (long long i = 1; i <= n; i++) {
    N[i] = 0;
    for (long long j = 1; j <= n; j++) {
      if (arr[i][j]) {
        N[i - 1] |= (1ll << (j - 1));
      }
    }
  }
  BronKerbosch(n, 0, (1ll << n) - 1, 0);
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  ;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      long long t;
      cin >> t;
      arr[i][j] = arr[j][i] = t;
    }
  }
  long long c = maxClique();
  double res = (1.0 * k * k * (c - 1) / c / 2.0);
  cout << fixed << setprecision(10) << res << endl;
  return 0;
}
