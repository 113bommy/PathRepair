#include <bits/stdc++.h>
using namespace std;
inline bool checkBit(long long n, long long i) {
  return n & ((long long)1 << i);
}
inline long long setBit(long long n, long long i) {
  return n | ((long long)1 << i);
  ;
}
inline long long resetBit(long long n, long long i) {
  return n & (~((long long)1 << i));
}
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long &a) { a = (a + 100000000019) % 100000000019; }
inline long long modMul(long long a, long long b) {
  a %= 100000000019, b %= 100000000019;
  normal(a), normal(b);
  return (a * b) % 100000000019;
}
inline long long modAdd(long long a, long long b) {
  a %= 100000000019, b %= 100000000019;
  normal(a), normal(b);
  return (a + b) % 100000000019;
}
inline long long modSub(long long a, long long b) {
  a %= 100000000019, b %= 100000000019;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInv(long long a) { return modPow(a, 100000000019 - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInv(b));
}
const long long N = 1e6 + 1;
long long n, m, cnt = 0, ans = 0, hash1[N], hash2[N];
long long g1[N], g2[N], g3[N], g4[N];
long long visited[N];
void initialize() {
  long long multi1 = 1000003, multi2 = 1000159;
  for (long long i = 1; i < N; i++) {
    hash1[i] = (hash1[i - 1] + multi1 * i) % 100000000019;
    hash2[i] = (hash2[i - 1] + multi2 * i) % 100000030111;
    multi1 = multi1 * 1000003 % 100000000019;
    multi2 = multi2 * 1000159 % 100000030111;
  }
}
void solve() {
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    g1[x] += hash1[y];
    g1[y] += hash1[x];
    g2[x] += hash2[y];
    g2[y] += hash2[x];
  }
  for (long long i = 1; i <= n; i++) {
    g3[i] = g1[i] + hash1[i];
    g4[i] = g2[i] + hash2[i];
  }
  map<pair<long long, long long>, long long> m1, m2;
  for (long long i = 1; i <= n; i++) {
    m1[{g1[i], g2[i]}]++;
    m2[{g3[i], g4[i]}]++;
  }
  for (map<pair<long long, long long>, long long>::iterator it = (m1).begin();
       it != (m1).end(); it++) {
    ans += m1[it->first] * (m1[it->first] - 1) / 2;
  }
  for (map<pair<long long, long long>, long long>::iterator it = (m2).begin();
       it != (m2).end(); it++) {
    ans += m2[it->first] * (m2[it->first] - 1) / 2;
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  initialize();
  long long t = 1;
  while (t--) {
    solve();
  }
}
