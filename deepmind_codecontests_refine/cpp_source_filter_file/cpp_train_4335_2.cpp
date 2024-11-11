#include <bits/stdc++.h>
using namespace std;
int n, l, r;
long long p;
long long mod, bs, expo;
pair<long long, long long> gcd(long long a, long long b) {
  if (a == 0) {
    return make_pair(0, 1);
  }
  pair<long long, long long> prev = gcd(b % a, a);
  return make_pair(prev.second - (b / a) * prev.first, prev.first);
}
long long modInv(long long x) {
  pair<long long, long long> res = gcd(x, mod);
  res.first = (res.first + mod) % mod;
  return res.first;
}
long long modDiv(long long x, long long y) { return (x * modInv(y)) % mod; }
pair<long long, long long> fac[100005];
void getFacs() {
  fac[0] = {1, 0};
  for (int i = (1); i <= (signed)(100005 - 1); i++) {
    fac[i] = fac[i - 1];
    int tmp = i;
    while (tmp % bs == 0) {
      fac[i].second++;
      tmp /= bs;
    }
    fac[i].first = (fac[i].first * tmp) % mod;
  }
}
long long modExp(long long b, long long ex) {
  long long prod = 1;
  while (ex > 0) {
    if (ex % 2 == 0) {
      b = (b * b) % mod;
      ex /= 2;
    } else {
      prod = (prod * b) % mod;
      ex--;
    }
  }
  return prod;
}
long long choose(int a, int b) {
  int c = a - b;
  if (c < 0) {
    cout << "ur bad\n";
    exit(0);
  }
  long long bsp = fac[a].second - fac[b].second - fac[c].second;
  long long res = modDiv(fac[a].first, (fac[b].first * fac[c].first) % mod);
  if (bsp >= expo) return 0;
  for (int _ = 0; _ < (signed)(bsp); _++) res = (res * p) % mod;
  return res;
}
long long calc(int n, int l, int r) {
  if (r > n) r = n;
  if (l > n) return 0;
  if ((n - r) % 2) --r;
  if ((n - l) % 2) ++l;
  long long ret =
      choose(n, (n - l) / 2) - (n == r ? 0 : choose(n, (n - r) / 2 - 1));
  return ret < 0 ? ret + mod : ret;
}
map<long long, long long> res;
long long calc2() {
  getFacs();
  long long sm = 0;
  for (int i = (0); i <= (signed)(n); i++) {
    long long p1 = calc(n - i, l, r);
    long long p2 = choose(n, i);
    sm = (sm + p1 * p2) % mod;
  }
  return sm;
}
int main() {
  cin >> n >> p >> l >> r;
  long long op = p;
  for (int i = 2; 1LL * i * i <= p; ++i) {
    if (p % i != 0) continue;
    int cnt = 0;
    long long ree = 1;
    while (p % i == 0) {
      ++cnt;
      p /= i;
      ree *= i;
    }
    mod = ree;
    bs = i;
    expo = cnt;
    long long ans = calc2();
    res[mod] = ans;
  }
  if (p != 1) {
    mod = p;
    bs = p;
    expo = 1;
    long long ans = calc2();
    res[mod] = ans;
  }
  long long fin = 0;
  for (auto u : res) {
    pair<long long, long long> hmm = gcd(u.first, op / u.first);
    long long got = ((u.second * hmm.second) % op * (op / u.first)) % op;
    fin = (fin + got) % op;
  }
  cout << (fin + op) % op << "\n";
  return 0;
}
