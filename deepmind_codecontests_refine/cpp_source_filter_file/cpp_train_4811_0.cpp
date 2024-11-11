#include <bits/stdc++.h>
using namespace std;
using pi = pair<long long, long long>;
using vi = vector<long long>;
using vvi = vector<vector<long long> >;
const long long NUM = 1000030;
const long long N = 10000000;
vector<long long> lp, sieve;
vector<long long> pr;
void primefactor();
long long binpow(long long a, long long b);
long long binpow(long long a, long long b, long long mod);
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
bool comp(long long a, long long b);
long long inversemod(long long a, long long mod);
void calc_sieve();
void add1(string& s, long long n, long long k) {
  long long carry = 1;
  for (long long i = k - 1; i >= 0; i--) {
    if (s[i] == '9') {
      if (carry == 1) {
        s[i] = '0';
        carry = 1;
      } else
        break;
    } else {
      s[i] = s[i] + 1;
      carry = 0;
      break;
    }
  }
}
void test() {
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  long long flag = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i % k] > s[i])
      flag = 1;
    else if (s[i % k] < s[i]) {
      if (flag)
        continue;
      else {
        flag = -1;
        break;
      }
    }
  }
  if (flag == -1) {
    add1(s, n, k);
    for (long long i = 0; i < n; i++) s[i] = s[i % k];
  }
  cout << (long long)(s).size() << endl;
  cout << s << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  while (t--) test();
  return 0;
}
void calc_sieve() {
  sieve.resize(NUM + 1, 0);
  for (long long x = 2; x <= NUM; x++) {
    if (sieve[x]) continue;
    for (long long u = x; u <= NUM; u += x) {
      sieve[u] = x;
    }
  }
}
void primefactor() {
  lp.resize(N + 1, 0);
  for (long long i = 2; i <= N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (long long j = 0;
         j < (long long)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
      lp[i * pr[j]] = pr[j];
  }
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long binpow(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return ((a / gcd(a, b)) * b); }
bool comp(long long a, long long b) { return a > b; }
long long inversemod(long long a, long long mod) {
  return binpow(a, mod - 2, mod);
}
