#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
std::uniform_int_distribution<std::mt19937::result_type> udist(0, 1);
std::mt19937 rng;
using namespace std;
FILE *in, *out;
int ri() {
  int a;
  fscanf(in, "%d", &a);
  return a;
}
double rf() {
  double a;
  fscanf(in, "%lf", &a);
  return a;
}
char sbuf[100005];
string rstr() {
  char c;
  char *b = sbuf;
  while (c = fgetc(in)) {
    if (c == '\n' || c == 255) break;
    *b++ = c;
  }
  *b = 0;
  return sbuf;
}
long long nod(long long a, long long b) {
  if (a == 1 || b == 1) return 1;
  if (a == 0) return b;
  if (b == 0) return a;
  return nod(b % a, a);
}
vector<int> primes;
void calculatePrimes() {
  primes.push_back(2);
  for (int i = 3; i < 1000000; i += 2) {
    bool bFound = false;
    int m = (int)sqrt((float)i);
    for (int j = 1; j < primes.size() && !bFound && primes[j] <= m; j++)
      bFound = ((i % primes[j]) == 0);
    if (!bFound) primes.push_back(i);
  }
}
bool isPrime(long long p) {
  for (int i : primes)
    if (p != i && (p % i) == 0) return false;
  return true;
}
void egcd(long long a, long long b, long long &g, long long &x, long long &y) {
  if (a == 0) {
    g = b;
    x = 0;
    y = 1;
    return;
  }
  egcd(b % a, a, g, y, x);
  x = x - (b / a) * y;
}
long long modinv(long long a, long long m) {
  long long g = 0, x = 0, y = 0;
  egcd(a, m, g, x, y);
  return (x + m) % m;
}
long long modpow(int a, long long n, int p) {
  long long res = 1;
  long long curp = (a % p);
  while (n) {
    if (n & 1) {
      res = (res * curp) % p;
    }
    curp = (curp * curp) % p;
    n /= 2;
  }
  return res;
}
long long nf(int n) {
  if (n <= 1) return 1;
  return (n * nf(n - 1)) % 1000000007;
}
long long intpowmod(long long base, long long exp) {
  if (exp == 0) return 1;
  if (exp == 1) return base;
  if ((exp & 1) != 0)
    return (base * intpowmod((base * base) % 1000000007, exp / 2)) % 1000000007;
  return intpowmod((base * base) % 1000000007, exp / 2);
}
int trav(long long kv, long long tm, vector<vector<long long>> &gr,
         vector<long long> &kp, vector<long long> &tp, vector<long long> &vr,
         map<long long, long long> &pp, long long tt, long long kpn) {
  if (tm == 0) return 0;
  if (tm < 0) return -1e9;
  tt += tp[kv] * kp[kv];
  pp[tp[kv]] += kp[kv];
  kpn += kp[kv];
  vector<pair<long long, long long>> rem;
  while (tt > tm) {
    long long soc = pp.rbegin()->first * pp.rbegin()->second;
    if (tt - soc >= tm - pp.rbegin()->first + 1) {
      rem.push_back(make_pair(pp.rbegin()->first, pp.rbegin()->second));
      kpn -= pp.rbegin()->second;
      pp.erase(pp.rbegin()->first);
      tt -= soc;
    } else {
      soc = (tt - tm + pp.rbegin()->first - 1) / pp.rbegin()->first;
      if (soc >= pp.rbegin()->second) soc /= 0;
      rem.push_back(make_pair(pp.rbegin()->first, soc));
      pp.rbegin()->second -= soc;
      tt -= soc * pp.rbegin()->first;
      kpn -= soc;
    }
  }
  vector<long long> pech;
  pech.reserve(gr[kv].size() + 1);
  for (auto &v : gr[kv])
    pech.push_back(trav(v, tm - 2 * vr[v], gr, kp, tp, vr, pp, tt, kpn));
  sort(pech.begin(), pech.end());
  for (auto &r : rem) pp[r.first] += r.second;
  pp[tp[kv]] -= kp[kv];
  if (!pp[tp[kv]]) pp.erase(tp[kv]);
  if (gr[kv].size() < 2 && kv != 0) return kpn;
  if (gr[kv].size() < 1) return kpn;
  if (kv == 0) return max(pech.back(), kpn);
  return max(pech[pech.size() - 1], kpn);
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, t;
  cin >> n >> t;
  vector<long long> kp(n);
  vector<long long> vp(n);
  vector<long long> rb(n);
  for (auto &v : kp) cin >> v;
  for (auto &v : vp) cin >> v;
  vector<vector<long long>> gr(n);
  for (long long i = 1; i < n; i++) {
    long long a;
    cin >> a >> rb[i];
    a--;
    gr[a].push_back(i);
  }
  map<long long, long long> pp;
  cout << trav(0, t, gr, kp, vp, rb, pp, 0, 0);
  return 0;
}
