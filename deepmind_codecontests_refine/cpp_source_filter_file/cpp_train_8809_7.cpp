#include <bits/stdc++.h>
using namespace std;
const long long infll = powl(2, 62) - 1;
const long double pi = 4.0 * atanl(1.0);
const long long mod = powl(10, 9) + 7;
struct NchooseK {
  long long mod;
  long long range;
  vector<long long> fact, ifact;
  NchooseK() {
    (this->mod) = (long long)1e9 + 7;
    this->range = 1000000;
    fact.resize(this->range);
    ifact.resize(this->range);
    calcFacts();
  }
  long long power(long long a, long long b) {
    if (b <= 0) return 1;
    long long temp = power(a, b / 2) % this->mod;
    if (b % 2 == 0) {
      return (temp * temp) % this->mod;
    } else {
      return (((a * temp) % this->mod) * temp) % this->mod;
    }
  }
  void calcFacts() {
    fact[0] = 1;
    for (long long i = 1; i < this->range; ++i) {
      fact[i] = (fact[i - 1] * i) % (this->mod);
    }
    ifact[this->range - 1] = power(fact[this->range - 1], this->mod - 2);
    for (long long i = this->range - 2; i >= 0; --i) {
      ifact[i] = (ifact[i + 1] * (i + 1)) % this->mod;
    }
  }
  long long gcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
      x = 0;
      y = 1;
      return b;
    }
    long long x1, y1;
    long long d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
  }
  long long divide(long long a, long long b) {
    long long m = (this->mod);
    long long x, y;
    long long g = gcd(b, m, x, y);
    if (g != 1) {
      cerr << "Bad gcd!" << endl;
      for (;;)
        ;
    }
    x = (x % m + m) % m;
    return ((long long)a * (long long)x) % m;
  }
  long long choose(long long n, long long k) {
    if (k < 0 || k > n || n < 0) return 0;
    return ((fact[n] * ifact[k]) % this->mod * ifact[n - k]) % this->mod;
  }
};
string a, b;
long long ways(string &s, vector<long long> cnt, NchooseK &div) {
  long long sum = 0, prod = div.fact[a.size()];
  for (long long counter : cnt) {
    if (counter > 0) {
      prod *= div.ifact[counter];
      prod %= mod;
    }
  }
  long long num = a.size();
  for (char c : s) {
    for (char letter = 'a'; letter < c; ++letter) {
      long long &temp = cnt[letter - 'a'];
      if (temp > 0) {
        long long diff = prod;
        diff *= div.ifact[num];
        diff %= mod;
        diff *= div.fact[num - 1];
        diff %= mod;
        diff *= div.fact[temp];
        diff %= mod;
        diff *= div.ifact[temp - 1];
        diff %= mod;
        sum += diff;
        sum %= mod;
      }
    }
    long long &temp = cnt[c - 'a'];
    if (temp == 0) break;
    prod *= div.ifact[num];
    prod %= mod;
    prod *= div.fact[num - 1];
    prod %= mod;
    prod *= div.fact[temp];
    prod %= mod;
    prod *= div.ifact[temp - 1];
    prod %= mod;
    temp--;
    num--;
  }
  return sum;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b;
  vector<long long> cnt(26, 0);
  for (char c : a) cnt[c - 'a']++;
  NchooseK div;
  cout << (ways(b, cnt, div) - ways(a, cnt, div) + 2 * mod - 1) % mod << '\n';
  return 0;
}
