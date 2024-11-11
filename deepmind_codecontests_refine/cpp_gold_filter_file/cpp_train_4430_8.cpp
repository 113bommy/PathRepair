#include <bits/stdc++.h>
using namespace std;
template <class T>
const T& max(const T& a, const T& b, const T& c) {
  return max(a, max(b, c));
}
template <class T>
const T& min(const T& a, const T& b, const T& c) {
  return min(a, min(b, c));
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long poww(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = poww(a, b / 2);
  return (b & 1 ? a * tmp * tmp : tmp * tmp);
}
long long sumOfDigs(string s) {
  long long sum = 0;
  for (int i = 0; i < s.length(); i++) sum += s[i] - '0';
  return sum;
}
long long sumOfDigs(long long n) {
  return (n < 10 ? n : n % 10 + sumOfDigs(n / 10));
}
string itos(long long i) {
  string s = "";
  while (i) {
    s += char(i % 10 + '0');
    i /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long stoi(string& s) {
  long long tot = 0;
  for (int i = (int)s.length() - 1, j = 1; i >= 0; i--, j *= 10) {
    tot += j * (s[i] + '0');
  }
  return tot;
}
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
using namespace std;
void t() { freopen("test.txt", "r", stdin); }
long long fact[1000 * 1000];
long long mod = 1e9 + 7;
long long modpower(long long x, long long y, long long p) {
  x %= mod;
  if (!y) return 1;
  long long res = 1;
  if (y & 1) {
    res *= x;
    res %= p;
  }
  long long z = modpower(x, y / 2, p);
  z %= p;
  z *= z;
  z %= mod;
  res *= z;
  res %= p;
  return res;
}
long long ncr(long long n, long long k) {
  long long res = 1;
  long long a = fact[n];
  long long b = modpower(fact[k], mod - 2, mod);
  long long c = modpower(fact[n - k], mod - 2, mod);
  res *= a;
  res %= mod;
  res *= b;
  res %= mod;
  res *= c;
  res %= mod;
  return res;
}
long long NcR(long long n, long long k) {
  long long res = fact[n] / fact[k] / fact[n - k];
  return res;
}
int sieve[1000];
set<int> st;
bool isPrime(int num) { return (st.find(num) != st.end()); }
int main() {
  st = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  vector<int> v = {4, 9, 25, 49};
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
    fflush(stdout);
    string s;
    cin >> s;
    if (s == "yes") {
      return cout << "composite" << endl, 0;
    }
  }
  v.clear();
  for (auto itr = st.begin(); itr != st.end(); ++itr) {
    cout << *itr << endl;
    fflush(stdout);
    string s;
    cin >> s;
    if (s == "yes") v.push_back(*itr);
  }
  return cout << (v.size() >= 2 ? "composite" : "prime") << endl, 0;
  return 0;
}
