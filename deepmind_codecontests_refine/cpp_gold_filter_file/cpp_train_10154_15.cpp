#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return a > val ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
const int maxn = 500010;
int n;
long long a[maxn];
long long b[maxn];
void add(long long x, vector<long long>& v) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] & -v[i] & x) x ^= v[i];
  }
  if (!x) return;
  for (int i = 0; i < v.size(); i++) {
    if (x & -x & v[i]) v[i] ^= x;
  }
  v.push_back(x);
}
void solve() {
  scanf("%d", &n);
  long long xorsum = 0;
  vector<long long> v;
  for (int i = (0); i < (n); i++) {
    scanf("%I64d%I64d", a + i, b + i);
    a[i] ^= b[i];
    xorsum ^= b[i];
    add(a[i], v);
  }
  for (int i = (0); i < (int((v).size())); i++) {
    if (v[i] & -v[i] & xorsum) xorsum ^= v[i];
  }
  if (xorsum) {
    printf("1/1\n");
  } else {
    printf("%I64d/%I64d\n", (1LL << int((v).size())) - 1,
           1LL << int((v).size()));
  }
}
int main() {
  solve();
  return 0;
}
